#include <stdio.h>
#include <assert.h>
#include <vector>

#ifndef UNICODE
#define UNICODE 1
#endif

// link with Ws2_32.lib
//#pragma comment(lib,"Ws2_32.lib")
#pragma comment(lib, "ws2_32")

#include <winsock2.h>
#include <MSWSock.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <stdlib.h>

#define MAX_POST_ACCEPT              10
#define EXIT_CODE                    NULL

// 缓冲区长度 (1024*8)
// 之所以为什么设置8K，也是一个江湖上的经验值
// 如果确实客户端发来的每组数据都比较少，那么就设置得小一些，省内存
#define MAX_BUFFER_LEN        8192  
// 默认端口
#define DEFAULT_PORT          12345    
// 默认IP地址
#define DEFAULT_IP            _T("127.0.0.1")




//////////////////////////////////////////////////////////////////
// 在完成端口上投递的I/O操作的类型
typedef enum _OPERATION_TYPE  
{  
	ACCEPT_POSTED,                     // 标志投递的Accept操作
	SEND_POSTED,                       // 标志投递的是发送操作
	RECV_POSTED,                       // 标志投递的是接收操作
	NULL_POSTED                        // 用于初始化，无意义

}OPERATION_TYPE;

//====================================================================================
//
//				单IO数据结构体定义(用于每一个重叠操作的参数)
//
//====================================================================================

typedef struct _PER_IO_CONTEXT
{
	OVERLAPPED     m_Overlapped;                               // 每一个重叠网络操作的重叠结构(针对每一个Socket的每一个操作，都要有一个)              
	SOCKET         m_sockAccept;                               // 这个网络操作所使用的Socket
	WSABUF         m_wsaBuf;                                   // WSA类型的缓冲区，用于给重叠操作传参数的
	char           m_szBuffer[MAX_BUFFER_LEN];                 // 这个是WSABUF里具体存字符的缓冲区
	OPERATION_TYPE m_OpType;                                   // 标识网络操作的类型(对应上面的枚举)

	// 初始化
	_PER_IO_CONTEXT()
	{
		ZeroMemory(&m_Overlapped, sizeof(m_Overlapped));  
		ZeroMemory( m_szBuffer,MAX_BUFFER_LEN );
		m_sockAccept = INVALID_SOCKET;
		m_wsaBuf.buf = m_szBuffer;
		m_wsaBuf.len = MAX_BUFFER_LEN;
		m_OpType     = NULL_POSTED;
	}
	// 释放掉Socket
	~_PER_IO_CONTEXT()
	{
		if( m_sockAccept!=INVALID_SOCKET )
		{
			closesocket(m_sockAccept);
			m_sockAccept = INVALID_SOCKET;
		}
	}
	// 重置缓冲区内容
	void ResetBuffer()
	{
		ZeroMemory( m_szBuffer,MAX_BUFFER_LEN );
	}

} PER_IO_CONTEXT, *PPER_IO_CONTEXT;


//====================================================================================
//
//				单句柄数据结构体定义(用于每一个完成端口，也就是每一个Socket的参数)
//
//====================================================================================

typedef struct _PER_SOCKET_CONTEXT
{  
	SOCKET      m_Socket;                                  // 每一个客户端连接的Socket
	SOCKADDR_IN m_ClientAddr;                              // 客户端的地址
	std::vector<_PER_IO_CONTEXT*> m_arrayIoContext;             // 客户端网络操作的上下文数据，
	                                                       // 也就是说对于每一个客户端Socket，是可以在上面同时投递多个IO请求的

	// 初始化
	_PER_SOCKET_CONTEXT()
	{
		m_Socket = INVALID_SOCKET;
		memset(&m_ClientAddr, 0, sizeof(m_ClientAddr)); 
	}

	// 释放资源
	~_PER_SOCKET_CONTEXT()
	{
		if( m_Socket!=INVALID_SOCKET )
		{
			closesocket( m_Socket );
		    m_Socket = INVALID_SOCKET;
		}
		// 释放掉所有的IO上下文数据
		for( int i=0;i<m_arrayIoContext.size();i++ )
		{
			delete m_arrayIoContext.at(i);
		}
		m_arrayIoContext.clear();
	}

	// 获取一个新的IoContext
	_PER_IO_CONTEXT* GetNewIoContext()
	{
		_PER_IO_CONTEXT* p = new _PER_IO_CONTEXT;

		m_arrayIoContext.push_back( p );

		return p;
	}

	// 从数组中移除一个指定的IoContext
	void RemoveContext( _PER_IO_CONTEXT* pContext )
	{
		assert( pContext!=NULL );

		for( int i=0;i<m_arrayIoContext.size();i++ )
		{
			if( pContext==m_arrayIoContext.at(i) )
			{
				delete pContext;
				pContext = NULL;
				m_arrayIoContext.erase(m_arrayIoContext.begin() + i);				
				break;
			}
		}
	}

} PER_SOCKET_CONTEXT, *PPER_SOCKET_CONTEXT;

typedef struct _tagThreadParams_WORKER
{
	//CIOCPModel* pIOCPModel;                                   // 类指针，用于调用类中的函数
	int         nThreadNo;                                    // 线程编号

} THREADPARAMS_WORKER,*PTHREADPARAM_WORKER; 


bool _PostAccept( PER_IO_CONTEXT* pAcceptIoContext );

HANDLE                       m_hShutdownEvent;

HANDLE                       m_hIOCompletionPort;           // 完成端口的句柄

PER_SOCKET_CONTEXT*          m_pListenContext;              // 用于监听的Socket的Context信息
LPFN_ACCEPTEX                m_lpfnAcceptEx;
LPFN_GETACCEPTEXSOCKADDRS    m_lpfnGetAcceptExSockAddrs; 

CRITICAL_SECTION             m_csContextList;               // 用于Worker线程同步的互斥量

std::vector<PER_SOCKET_CONTEXT*>  m_arrayClientContext;          // 客户端Socket的Context信息        

bool _IsSocketAlive(SOCKET s)
{
	int nByteSent=send(s,"",0,0);
	if (-1 == nByteSent) return false;
	return true;
}

bool HandleError( PER_SOCKET_CONTEXT *pContext,const DWORD& dwErr )
{
	// 如果是超时了，就再继续等吧  
	if(WAIT_TIMEOUT == dwErr)  
	{  	
		// 确认客户端是否还活着...
		if( !_IsSocketAlive( pContext->m_Socket) )
		{
			printf("检测到客户端异常退出！");
			//this->_RemoveContext( pContext );
			return true;
		}
		else
		{
			printf("网络操作超时！重试中...");
			return true;
		}
	}  

	// 可能是客户端异常退出了
	else if( ERROR_NETNAME_DELETED==dwErr )
	{
		printf("检测到客户端异常退出！");
		//this->_RemoveContext( pContext );
		return true;
	}

	else
	{
		printf("完成端口操作出现错误，线程退出。错误代码：%d",dwErr );
		return false;
	}
}

bool _AssociateWithIOCP( PER_SOCKET_CONTEXT *pContext )
{
	// 将用于和客户端通信的SOCKET绑定到完成端口中
	HANDLE hTemp = CreateIoCompletionPort((HANDLE)pContext->m_Socket, m_hIOCompletionPort, (DWORD)pContext, 0);

	if (NULL == hTemp)
	{
		printf("执行CreateIoCompletionPort()出现错误.错误代码：%d", GetLastError());
		return false;
	}

	return true;
}

bool _PostRecv( PER_IO_CONTEXT* pIoContext )
{
	// 初始化变量
	DWORD dwFlags = 0;
	DWORD dwBytes = 0;
	WSABUF *p_wbuf   = &pIoContext->m_wsaBuf;
	OVERLAPPED *p_ol = &pIoContext->m_Overlapped;

	pIoContext->ResetBuffer();
	pIoContext->m_OpType = RECV_POSTED;

	// 初始化完成后，，投递WSARecv请求
	int nBytesRecv = WSARecv( pIoContext->m_sockAccept, p_wbuf, 1, &dwBytes, &dwFlags, p_ol, NULL );

	// 如果返回值错误，并且错误的代码并非是Pending的话，那就说明这个重叠请求失败了
	if ((SOCKET_ERROR == nBytesRecv) && (WSA_IO_PENDING != WSAGetLastError()))
	{
		printf("投递第一个WSARecv失败！");
		return false;
	}
	return true;
}


void _AddToContextList( PER_SOCKET_CONTEXT *pHandleData )
{
	
	EnterCriticalSection(&m_csContextList);
	
	m_arrayClientContext.push_back(pHandleData);	
	
	LeaveCriticalSection(&m_csContextList);
	
}

bool _DoAccpet( PER_SOCKET_CONTEXT* pSocketContext, PER_IO_CONTEXT* pIoContext )
{
	SOCKADDR_IN* ClientAddr = NULL;
	SOCKADDR_IN* LocalAddr = NULL;  
	int remoteLen = sizeof(SOCKADDR_IN), localLen = sizeof(SOCKADDR_IN);  

	///////////////////////////////////////////////////////////////////////////
	// 1. 首先取得连入客户端的地址信息
	// 这个 m_lpfnGetAcceptExSockAddrs 不得了啊~~~~~~
	// 不但可以取得客户端和本地端的地址信息，还能顺便取出客户端发来的第一组数据，老强大了...
	m_lpfnGetAcceptExSockAddrs(pIoContext->m_wsaBuf.buf, pIoContext->m_wsaBuf.len - ((sizeof(SOCKADDR_IN)+16)*2),  
		sizeof(SOCKADDR_IN)+16, sizeof(SOCKADDR_IN)+16, (LPSOCKADDR*)&LocalAddr, &localLen, (LPSOCKADDR*)&ClientAddr, &remoteLen);  

	printf("客户端 %s:%d 连入.", inet_ntoa(ClientAddr->sin_addr), ntohs(ClientAddr->sin_port) );
	printf("客户额 %s:%d 信息：%s.",inet_ntoa(ClientAddr->sin_addr), ntohs(ClientAddr->sin_port),pIoContext->m_wsaBuf.buf );


	//////////////////////////////////////////////////////////////////////////////////////////////////////
	// 2. 这里需要注意，这里传入的这个是ListenSocket上的Context，这个Context我们还需要用于监听下一个连接
	// 所以我还得要将ListenSocket上的Context复制出来一份为新连入的Socket新建一个SocketContext

	PER_SOCKET_CONTEXT* pNewSocketContext = new PER_SOCKET_CONTEXT;
	pNewSocketContext->m_Socket           = pIoContext->m_sockAccept;
	memcpy(&(pNewSocketContext->m_ClientAddr), ClientAddr, sizeof(SOCKADDR_IN));

	// 参数设置完毕，将这个Socket和完成端口绑定(这也是一个关键步骤)
	if( false== _AssociateWithIOCP( pNewSocketContext ) )
	{
		//RELEASE( pNewSocketContext );
		return false;
	}  


	///////////////////////////////////////////////////////////////////////////////////////////////////
	// 3. 继续，建立其下的IoContext，用于在这个Socket上投递第一个Recv数据请求
	PER_IO_CONTEXT* pNewIoContext = pNewSocketContext->GetNewIoContext();
	pNewIoContext->m_OpType       = RECV_POSTED;
	pNewIoContext->m_sockAccept   = pNewSocketContext->m_Socket;
	// 如果Buffer需要保留，就自己拷贝一份出来
	//memcpy( pNewIoContext->m_szBuffer,pIoContext->m_szBuffer,MAX_BUFFER_LEN );

	// 绑定完毕之后，就可以开始在这个Socket上投递完成请求了
	if( false==_PostRecv( pNewIoContext) )
	{
		pNewSocketContext->RemoveContext( pNewIoContext );
		return false;
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////
	// 4. 如果投递成功，那么就把这个有效的客户端信息，加入到ContextList中去(需要统一管理，方便释放资源)
	_AddToContextList( pNewSocketContext );

	////////////////////////////////////////////////////////////////////////////////////////////////
	// 5. 使用完毕之后，把Listen Socket的那个IoContext重置，然后准备投递新的AcceptEx
	pIoContext->ResetBuffer();
	return _PostAccept( pIoContext ); 	
}


bool _DoRecv( PER_SOCKET_CONTEXT* pSocketContext, PER_IO_CONTEXT* pIoContext )
{
	// 先把上一次的数据显示出现，然后就重置状态，发出下一个Recv请求
	SOCKADDR_IN* ClientAddr = &pSocketContext->m_ClientAddr;
	printf("收到  %s:%d 信息：%s",inet_ntoa(ClientAddr->sin_addr), ntohs(ClientAddr->sin_port),pIoContext->m_wsaBuf.buf );

	// 然后开始投递下一个WSARecv请求
	return _PostRecv( pIoContext );
}

DWORD WINAPI work_thread_process(LPVOID lpParam) 
{
	printf("thread worker\n");
	THREADPARAMS_WORKER* pParam = (THREADPARAMS_WORKER*)lpParam;
	//CIOCPModel* pIOCPModel = (CIOCPModel*)pParam->pIOCPModel;
	int nThreadNo = (int)pParam->nThreadNo;

	printf("工作者线程启动，ID: %d.",nThreadNo);

	OVERLAPPED           *pOverlapped = NULL;
	PER_SOCKET_CONTEXT   *pSocketContext = NULL;
	DWORD                dwBytesTransfered = 0;

	// 循环处理请求，知道接收到Shutdown信息为止
	while (WAIT_OBJECT_0 != WaitForSingleObject(m_hShutdownEvent, 0))
	{
		BOOL bReturn = GetQueuedCompletionStatus(
			m_hIOCompletionPort,
			&dwBytesTransfered,
			(unsigned long *)&pSocketContext,
			&pOverlapped,
			INFINITE);

		// 如果收到的是退出标志，则直接退出
		if ( EXIT_CODE==(DWORD)pSocketContext )
		{
			break;
		}

		// 判断是否出现了错误
		if( !bReturn )  
		{  
			DWORD dwErr = GetLastError();

			// 显示一下提示信息
			if( !HandleError( pSocketContext,dwErr ) )
			{
				break;
			}

			continue;  
		}  
		else  
		{  	
			// 读取传入的参数
			PER_IO_CONTEXT* pIoContext = CONTAINING_RECORD(pOverlapped, PER_IO_CONTEXT, m_Overlapped);  

			// 判断是否有客户端断开了
			if((0 == dwBytesTransfered) && ( RECV_POSTED==pIoContext->m_OpType || SEND_POSTED==pIoContext->m_OpType))  
			{  
				printf("客户端 %s:%d 断开连接.",inet_ntoa(pSocketContext->m_ClientAddr.sin_addr), ntohs(pSocketContext->m_ClientAddr.sin_port) );

				// 释放掉对应的资源
				//pIOCPModel->_RemoveContext( pSocketContext );

 				continue;  
			}  
			else
			{
				switch( pIoContext->m_OpType )  
				{  
					 // Accept  
				case ACCEPT_POSTED:
					{ 

						// 为了增加代码可读性，这里用专门的_DoAccept函数进行处理连入请求
						_DoAccpet( pSocketContext, pIoContext );						
						

					}
					break;

					// RECV
				case RECV_POSTED:
					{
						// 为了增加代码可读性，这里用专门的_DoRecv函数进行处理接收请求
						_DoRecv( pSocketContext,pIoContext );
					}
					break;

					// SEND
					// 这里略过不写了，要不代码太多了，不容易理解，Send操作相对来讲简单一些
				case SEND_POSTED:
					{

					}
					break;
				default:
					// 不应该执行到这里
					printf("_WorkThread中的 pIoContext->m_OpType 参数异常.\n");
					break;
				} //switch
			}//if
		}//if

	}//while

	printf("工作者线程 %d 号退出.\n", nThreadNo);

	// 释放线程参数
	//RELEASE(lpParam);	

	return 0;
}

bool _PostAccept( PER_IO_CONTEXT* pAcceptIoContext )
{
	
	assert( INVALID_SOCKET!=m_pListenContext->m_Socket );

	// 准备参数
	DWORD dwBytes = 0;  
	pAcceptIoContext->m_OpType = ACCEPT_POSTED;  
	WSABUF *p_wbuf   = &pAcceptIoContext->m_wsaBuf;
	OVERLAPPED *p_ol = &pAcceptIoContext->m_Overlapped;
	
	// 为以后新连入的客户端先准备好Socket( 这个是与传统accept最大的区别 ) 
	pAcceptIoContext->m_sockAccept  = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED);  
	if( INVALID_SOCKET==pAcceptIoContext->m_sockAccept )  
	{  
		printf("创建用于Accept的Socket失败！错误代码: %d", WSAGetLastError()); 
		return false;  
	} 

	// 投递AcceptEx
	if(FALSE == m_lpfnAcceptEx( m_pListenContext->m_Socket, pAcceptIoContext->m_sockAccept, p_wbuf->buf, p_wbuf->len - ((sizeof(SOCKADDR_IN)+16)*2),   
								sizeof(SOCKADDR_IN)+16, sizeof(SOCKADDR_IN)+16, &dwBytes, p_ol))  
	{  
		if(WSA_IO_PENDING != WSAGetLastError())  
		{  
			printf("投递 AcceptEx 请求失败，错误代码: %d\n", WSAGetLastError());  
			return false;  
		}  
	}
	return true;
}

int main() 
{
	// 初始化线程互斥量
	InitializeCriticalSection(&m_csContextList);


	// 建立系统退出的事件通知
	m_hShutdownEvent = CreateEvent(NULL, TRUE, FALSE, NULL);

	HANDLE fHandle = NULL;/*CreateFile("D:\\home\\admin\\workstation\\c\\HIB_SERVER\\HDATA.IDX", 
		GENERIC_READ | GENERIC_WRITE, 
		FILE_SHARE_READ | FILE_SHARE_WRITE, 
		NULL, 
		CREATE_ALWAYS, 
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, // flag FILE_FLAG_OVERLAPPED must be specific in this case
		NULL);*/
	fHandle = INVALID_HANDLE_VALUE;
	if (fHandle == INVALID_HANDLE_VALUE) 
	{
	    DWORD error = GetLastError();
		printf("error %d\n", error);

		fHandle = INVALID_HANDLE_VALUE;
		printf("use invalid handle value to create i/o completion port\n");
	}
	else 
	{
		printf("file handle created\n");
	}

	/**
	 * HANDLE WINAPI CreateIoCompletionPort(
     *     _In_      HANDLE FileHandle,
     *     _In_opt_  HANDLE ExistingCompletionPort,
     *     _In_      ULONG_PTR CompletionKey,
     *     _In_      DWORD NumberOfConcurrentThreads
	 * );
     *
	 * FileHandle [in]
	 * 
	 * An open file handle or INVALID_HANDLE_VALUE.
     * 
	 * The handle must be to an object that supports overlapped I/O.
     * 
	 * If a handle is provided, it has to have been opened for overlapped 
	 * I/O completion. For example, you must specify the FILE_FLAG_OVERLAPPED 
	 * flag when using the CreateFile function to obtain the handle.
     * 
	 * If INVALID_HANDLE_VALUE is specified, the function creates an I/O 
	 * completion port without associating it with a file handle. In this 
	 * case, the ExistingCompletionPort parameter must be NULL and the 
	 * CompletionKey parameter is ignored.
	 * 
	 * if parameter FileHandle specific as NULL, function return NULL, and 
	 * the error returned ERROR_INVALID_HANDLE
	 * 
	 * if the parameter FileHandle specific is not specific the 
	 * FILE_FLAG_OVERLAPPED flag when using the CreateFile function to obtain 
	 * the handle, function return NULL, and the error returned 
	 * ERROR_INVALID_PARAMETER
	 */
	//fHandle = NULL;
    HANDLE handle = CreateIoCompletionPort(fHandle, NULL, 0, 0);
	if (handle == NULL) 
	{
	    DWORD error = GetLastError();
	    printf("error %d\n", error);
		return 1;
	}
    printf("i/o completion port created...\n");

	SYSTEM_INFO si;
	GetSystemInfo(&si);
	int m_nProcessors = si.dwNumberOfProcessors;
	
	int m_nThreads = m_nProcessors * 2 + 2;
	HANDLE *m_pWorkThreadProcess = new HANDLE[m_nThreads];
	for (int i = 0; i < m_nThreads; i++) 
	{
		DWORD threadID;

		THREADPARAMS_WORKER* pThreadParams = new THREADPARAMS_WORKER;
		//pThreadParams->pIOCPModel = this;
		pThreadParams->nThreadNo  = i+1;

	    m_pWorkThreadProcess[i] = CreateThread(NULL, 0, work_thread_process, (LPVOID) pThreadParams, 0, &threadID);
	}



	m_pListenContext = new PER_SOCKET_CONTEXT;

	GUID GuidAcceptEx = WSAID_ACCEPTEX;  
	GUID GuidGetAcceptExSockAddrs = WSAID_GETACCEPTEXSOCKADDRS; 

	// 初始化Socket库  
    WSADATA wsaData;  
    WSAStartup(MAKEWORD(2,2), &wsaData);  
    //初始化Socket  
    struct sockaddr_in ServerAddress;  
    // 这里需要特别注意，如果要使用重叠I/O的话，这里必须要使用WSASocket来初始化Socket  
    // 注意里面有个WSA_FLAG_OVERLAPPED参数  
    m_pListenContext->m_Socket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);//::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    
	
	// 填充地址结构信息  
    ZeroMemory((char *)&ServerAddress, sizeof(ServerAddress));  
    ServerAddress.sin_family = AF_INET;  
    // 这里可以选择绑定任何一个可用的地址，或者是自己指定的一个IP地址   
    ServerAddress.sin_addr.s_addr = htonl(INADDR_ANY);                        
    //ServerAddress.sin_addr.s_addr = inet_addr(“你的IP”);           
    ServerAddress.sin_port = htons(11111);                            
    // 绑定端口
	int error = bind(m_pListenContext->m_Socket, (struct sockaddr *) &ServerAddress, sizeof(ServerAddress));
    if (error == SOCKET_ERROR) 
	{
		error = WSAGetLastError();
	    printf("error %d\n", error);
	}

	// 开始监听  
	listen(m_pListenContext->m_Socket, SOMAXCONN);

	handle = CreateIoCompletionPort((HANDLE) m_pListenContext->m_Socket, handle, (DWORD) m_pListenContext, 0);
	if (handle == NULL) 
	{
	    DWORD error = GetLastError();
	    printf("error %d\n", error);
		return 1;
	}

	// 使用AcceptEx函数，因为这个是属于WinSock2规范之外的微软另外提供的扩展函数
	// 所以需要额外获取一下函数的指针，
	// 获取AcceptEx函数指针
	DWORD dwBytes = 0;  
	if(SOCKET_ERROR == WSAIoctl(
		m_pListenContext->m_Socket, 
		SIO_GET_EXTENSION_FUNCTION_POINTER, 
		&GuidAcceptEx, 
		sizeof(GuidAcceptEx), 
		&m_lpfnAcceptEx, 
		sizeof(m_lpfnAcceptEx), 
		&dwBytes, 
		NULL, 
		NULL))  
	{  
		printf("WSAIoctl 未能获取AcceptEx函数指针。错误代码: %d\n", WSAGetLastError()); 
		//this->_DeInitialize();
		return 1;  
	}  

	// 获取GetAcceptExSockAddrs函数指针，也是同理
	if(SOCKET_ERROR == WSAIoctl(
		m_pListenContext->m_Socket, 
		SIO_GET_EXTENSION_FUNCTION_POINTER, 
		&GuidGetAcceptExSockAddrs,
		sizeof(GuidGetAcceptExSockAddrs), 
		&m_lpfnGetAcceptExSockAddrs, 
		sizeof(m_lpfnGetAcceptExSockAddrs),   
		&dwBytes, 
		NULL, 
		NULL))  
	{  
		printf("WSAIoctl 未能获取GuidGetAcceptExSockAddrs函数指针。错误代码: %d\n", WSAGetLastError());  
		//this->_DeInitialize();
		return false; 
	}  


	// 为AcceptEx 准备参数，然后投递AcceptEx I/O请求
	for(i=0;i<MAX_POST_ACCEPT;i++ )
	{
		// 新建一个IO_CONTEXT
		PER_IO_CONTEXT* pAcceptIoContext = m_pListenContext->GetNewIoContext();

		if( false== _PostAccept( pAcceptIoContext ) )
		{
			m_pListenContext->RemoveContext(pAcceptIoContext);
			return false;
		}
	}

	printf("投递 %d 个AcceptEx请求完毕\n", MAX_POST_ACCEPT );
	ExitThread(0);
}