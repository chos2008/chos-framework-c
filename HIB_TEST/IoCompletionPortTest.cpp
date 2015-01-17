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

// ���������� (1024*8)
// ֮����Ϊʲô����8K��Ҳ��һ�������ϵľ���ֵ
// ���ȷʵ�ͻ��˷�����ÿ�����ݶ��Ƚ��٣���ô�����õ�СһЩ��ʡ�ڴ�
#define MAX_BUFFER_LEN        8192  
// Ĭ�϶˿�
#define DEFAULT_PORT          12345    
// Ĭ��IP��ַ
#define DEFAULT_IP            _T("127.0.0.1")




//////////////////////////////////////////////////////////////////
// ����ɶ˿���Ͷ�ݵ�I/O����������
typedef enum _OPERATION_TYPE  
{  
	ACCEPT_POSTED,                     // ��־Ͷ�ݵ�Accept����
	SEND_POSTED,                       // ��־Ͷ�ݵ��Ƿ��Ͳ���
	RECV_POSTED,                       // ��־Ͷ�ݵ��ǽ��ղ���
	NULL_POSTED                        // ���ڳ�ʼ����������

}OPERATION_TYPE;

//====================================================================================
//
//				��IO���ݽṹ�嶨��(����ÿһ���ص������Ĳ���)
//
//====================================================================================

typedef struct _PER_IO_CONTEXT
{
	OVERLAPPED     m_Overlapped;                               // ÿһ���ص�����������ص��ṹ(���ÿһ��Socket��ÿһ����������Ҫ��һ��)              
	SOCKET         m_sockAccept;                               // ������������ʹ�õ�Socket
	WSABUF         m_wsaBuf;                                   // WSA���͵Ļ����������ڸ��ص�������������
	char           m_szBuffer[MAX_BUFFER_LEN];                 // �����WSABUF�������ַ��Ļ�����
	OPERATION_TYPE m_OpType;                                   // ��ʶ�������������(��Ӧ�����ö��)

	// ��ʼ��
	_PER_IO_CONTEXT()
	{
		ZeroMemory(&m_Overlapped, sizeof(m_Overlapped));  
		ZeroMemory( m_szBuffer,MAX_BUFFER_LEN );
		m_sockAccept = INVALID_SOCKET;
		m_wsaBuf.buf = m_szBuffer;
		m_wsaBuf.len = MAX_BUFFER_LEN;
		m_OpType     = NULL_POSTED;
	}
	// �ͷŵ�Socket
	~_PER_IO_CONTEXT()
	{
		if( m_sockAccept!=INVALID_SOCKET )
		{
			closesocket(m_sockAccept);
			m_sockAccept = INVALID_SOCKET;
		}
	}
	// ���û���������
	void ResetBuffer()
	{
		ZeroMemory( m_szBuffer,MAX_BUFFER_LEN );
	}

} PER_IO_CONTEXT, *PPER_IO_CONTEXT;


//====================================================================================
//
//				��������ݽṹ�嶨��(����ÿһ����ɶ˿ڣ�Ҳ����ÿһ��Socket�Ĳ���)
//
//====================================================================================

typedef struct _PER_SOCKET_CONTEXT
{  
	SOCKET      m_Socket;                                  // ÿһ���ͻ������ӵ�Socket
	SOCKADDR_IN m_ClientAddr;                              // �ͻ��˵ĵ�ַ
	std::vector<_PER_IO_CONTEXT*> m_arrayIoContext;             // �ͻ���������������������ݣ�
	                                                       // Ҳ����˵����ÿһ���ͻ���Socket���ǿ���������ͬʱͶ�ݶ��IO�����

	// ��ʼ��
	_PER_SOCKET_CONTEXT()
	{
		m_Socket = INVALID_SOCKET;
		memset(&m_ClientAddr, 0, sizeof(m_ClientAddr)); 
	}

	// �ͷ���Դ
	~_PER_SOCKET_CONTEXT()
	{
		if( m_Socket!=INVALID_SOCKET )
		{
			closesocket( m_Socket );
		    m_Socket = INVALID_SOCKET;
		}
		// �ͷŵ����е�IO����������
		for( int i=0;i<m_arrayIoContext.size();i++ )
		{
			delete m_arrayIoContext.at(i);
		}
		m_arrayIoContext.clear();
	}

	// ��ȡһ���µ�IoContext
	_PER_IO_CONTEXT* GetNewIoContext()
	{
		_PER_IO_CONTEXT* p = new _PER_IO_CONTEXT;

		m_arrayIoContext.push_back( p );

		return p;
	}

	// ���������Ƴ�һ��ָ����IoContext
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
	//CIOCPModel* pIOCPModel;                                   // ��ָ�룬���ڵ������еĺ���
	int         nThreadNo;                                    // �̱߳��

} THREADPARAMS_WORKER,*PTHREADPARAM_WORKER; 


bool _PostAccept( PER_IO_CONTEXT* pAcceptIoContext );

HANDLE                       m_hShutdownEvent;

HANDLE                       m_hIOCompletionPort;           // ��ɶ˿ڵľ��

PER_SOCKET_CONTEXT*          m_pListenContext;              // ���ڼ�����Socket��Context��Ϣ
LPFN_ACCEPTEX                m_lpfnAcceptEx;
LPFN_GETACCEPTEXSOCKADDRS    m_lpfnGetAcceptExSockAddrs; 

CRITICAL_SECTION             m_csContextList;               // ����Worker�߳�ͬ���Ļ�����

std::vector<PER_SOCKET_CONTEXT*>  m_arrayClientContext;          // �ͻ���Socket��Context��Ϣ        

bool _IsSocketAlive(SOCKET s)
{
	int nByteSent=send(s,"",0,0);
	if (-1 == nByteSent) return false;
	return true;
}

bool HandleError( PER_SOCKET_CONTEXT *pContext,const DWORD& dwErr )
{
	// ����ǳ�ʱ�ˣ����ټ����Ȱ�  
	if(WAIT_TIMEOUT == dwErr)  
	{  	
		// ȷ�Ͽͻ����Ƿ񻹻���...
		if( !_IsSocketAlive( pContext->m_Socket) )
		{
			printf("��⵽�ͻ����쳣�˳���");
			//this->_RemoveContext( pContext );
			return true;
		}
		else
		{
			printf("���������ʱ��������...");
			return true;
		}
	}  

	// �����ǿͻ����쳣�˳���
	else if( ERROR_NETNAME_DELETED==dwErr )
	{
		printf("��⵽�ͻ����쳣�˳���");
		//this->_RemoveContext( pContext );
		return true;
	}

	else
	{
		printf("��ɶ˿ڲ������ִ����߳��˳���������룺%d",dwErr );
		return false;
	}
}

bool _AssociateWithIOCP( PER_SOCKET_CONTEXT *pContext )
{
	// �����ںͿͻ���ͨ�ŵ�SOCKET�󶨵���ɶ˿���
	HANDLE hTemp = CreateIoCompletionPort((HANDLE)pContext->m_Socket, m_hIOCompletionPort, (DWORD)pContext, 0);

	if (NULL == hTemp)
	{
		printf("ִ��CreateIoCompletionPort()���ִ���.������룺%d", GetLastError());
		return false;
	}

	return true;
}

bool _PostRecv( PER_IO_CONTEXT* pIoContext )
{
	// ��ʼ������
	DWORD dwFlags = 0;
	DWORD dwBytes = 0;
	WSABUF *p_wbuf   = &pIoContext->m_wsaBuf;
	OVERLAPPED *p_ol = &pIoContext->m_Overlapped;

	pIoContext->ResetBuffer();
	pIoContext->m_OpType = RECV_POSTED;

	// ��ʼ����ɺ󣬣�Ͷ��WSARecv����
	int nBytesRecv = WSARecv( pIoContext->m_sockAccept, p_wbuf, 1, &dwBytes, &dwFlags, p_ol, NULL );

	// �������ֵ���󣬲��Ҵ���Ĵ��벢����Pending�Ļ����Ǿ�˵������ص�����ʧ����
	if ((SOCKET_ERROR == nBytesRecv) && (WSA_IO_PENDING != WSAGetLastError()))
	{
		printf("Ͷ�ݵ�һ��WSARecvʧ�ܣ�");
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
	// 1. ����ȡ������ͻ��˵ĵ�ַ��Ϣ
	// ��� m_lpfnGetAcceptExSockAddrs �����˰�~~~~~~
	// ��������ȡ�ÿͻ��˺ͱ��ض˵ĵ�ַ��Ϣ������˳��ȡ���ͻ��˷����ĵ�һ�����ݣ���ǿ����...
	m_lpfnGetAcceptExSockAddrs(pIoContext->m_wsaBuf.buf, pIoContext->m_wsaBuf.len - ((sizeof(SOCKADDR_IN)+16)*2),  
		sizeof(SOCKADDR_IN)+16, sizeof(SOCKADDR_IN)+16, (LPSOCKADDR*)&LocalAddr, &localLen, (LPSOCKADDR*)&ClientAddr, &remoteLen);  

	printf("�ͻ��� %s:%d ����.", inet_ntoa(ClientAddr->sin_addr), ntohs(ClientAddr->sin_port) );
	printf("�ͻ��� %s:%d ��Ϣ��%s.",inet_ntoa(ClientAddr->sin_addr), ntohs(ClientAddr->sin_port),pIoContext->m_wsaBuf.buf );


	//////////////////////////////////////////////////////////////////////////////////////////////////////
	// 2. ������Ҫע�⣬���ﴫ��������ListenSocket�ϵ�Context�����Context���ǻ���Ҫ���ڼ�����һ������
	// �����һ���Ҫ��ListenSocket�ϵ�Context���Ƴ���һ��Ϊ�������Socket�½�һ��SocketContext

	PER_SOCKET_CONTEXT* pNewSocketContext = new PER_SOCKET_CONTEXT;
	pNewSocketContext->m_Socket           = pIoContext->m_sockAccept;
	memcpy(&(pNewSocketContext->m_ClientAddr), ClientAddr, sizeof(SOCKADDR_IN));

	// ����������ϣ������Socket����ɶ˿ڰ�(��Ҳ��һ���ؼ�����)
	if( false== _AssociateWithIOCP( pNewSocketContext ) )
	{
		//RELEASE( pNewSocketContext );
		return false;
	}  


	///////////////////////////////////////////////////////////////////////////////////////////////////
	// 3. �������������µ�IoContext�����������Socket��Ͷ�ݵ�һ��Recv��������
	PER_IO_CONTEXT* pNewIoContext = pNewSocketContext->GetNewIoContext();
	pNewIoContext->m_OpType       = RECV_POSTED;
	pNewIoContext->m_sockAccept   = pNewSocketContext->m_Socket;
	// ���Buffer��Ҫ���������Լ�����һ�ݳ���
	//memcpy( pNewIoContext->m_szBuffer,pIoContext->m_szBuffer,MAX_BUFFER_LEN );

	// �����֮�󣬾Ϳ��Կ�ʼ�����Socket��Ͷ�����������
	if( false==_PostRecv( pNewIoContext) )
	{
		pNewSocketContext->RemoveContext( pNewIoContext );
		return false;
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////
	// 4. ���Ͷ�ݳɹ�����ô�Ͱ������Ч�Ŀͻ�����Ϣ�����뵽ContextList��ȥ(��Ҫͳһ���������ͷ���Դ)
	_AddToContextList( pNewSocketContext );

	////////////////////////////////////////////////////////////////////////////////////////////////
	// 5. ʹ�����֮�󣬰�Listen Socket���Ǹ�IoContext���ã�Ȼ��׼��Ͷ���µ�AcceptEx
	pIoContext->ResetBuffer();
	return _PostAccept( pIoContext ); 	
}


bool _DoRecv( PER_SOCKET_CONTEXT* pSocketContext, PER_IO_CONTEXT* pIoContext )
{
	// �Ȱ���һ�ε�������ʾ���֣�Ȼ�������״̬��������һ��Recv����
	SOCKADDR_IN* ClientAddr = &pSocketContext->m_ClientAddr;
	printf("�յ�  %s:%d ��Ϣ��%s",inet_ntoa(ClientAddr->sin_addr), ntohs(ClientAddr->sin_port),pIoContext->m_wsaBuf.buf );

	// Ȼ��ʼͶ����һ��WSARecv����
	return _PostRecv( pIoContext );
}

DWORD WINAPI work_thread_process(LPVOID lpParam) 
{
	printf("thread worker\n");
	THREADPARAMS_WORKER* pParam = (THREADPARAMS_WORKER*)lpParam;
	//CIOCPModel* pIOCPModel = (CIOCPModel*)pParam->pIOCPModel;
	int nThreadNo = (int)pParam->nThreadNo;

	printf("�������߳�������ID: %d.",nThreadNo);

	OVERLAPPED           *pOverlapped = NULL;
	PER_SOCKET_CONTEXT   *pSocketContext = NULL;
	DWORD                dwBytesTransfered = 0;

	// ѭ����������֪�����յ�Shutdown��ϢΪֹ
	while (WAIT_OBJECT_0 != WaitForSingleObject(m_hShutdownEvent, 0))
	{
		BOOL bReturn = GetQueuedCompletionStatus(
			m_hIOCompletionPort,
			&dwBytesTransfered,
			(unsigned long *)&pSocketContext,
			&pOverlapped,
			INFINITE);

		// ����յ������˳���־����ֱ���˳�
		if ( EXIT_CODE==(DWORD)pSocketContext )
		{
			break;
		}

		// �ж��Ƿ�����˴���
		if( !bReturn )  
		{  
			DWORD dwErr = GetLastError();

			// ��ʾһ����ʾ��Ϣ
			if( !HandleError( pSocketContext,dwErr ) )
			{
				break;
			}

			continue;  
		}  
		else  
		{  	
			// ��ȡ����Ĳ���
			PER_IO_CONTEXT* pIoContext = CONTAINING_RECORD(pOverlapped, PER_IO_CONTEXT, m_Overlapped);  

			// �ж��Ƿ��пͻ��˶Ͽ���
			if((0 == dwBytesTransfered) && ( RECV_POSTED==pIoContext->m_OpType || SEND_POSTED==pIoContext->m_OpType))  
			{  
				printf("�ͻ��� %s:%d �Ͽ�����.",inet_ntoa(pSocketContext->m_ClientAddr.sin_addr), ntohs(pSocketContext->m_ClientAddr.sin_port) );

				// �ͷŵ���Ӧ����Դ
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

						// Ϊ�����Ӵ���ɶ��ԣ�������ר�ŵ�_DoAccept�������д�����������
						_DoAccpet( pSocketContext, pIoContext );						
						

					}
					break;

					// RECV
				case RECV_POSTED:
					{
						// Ϊ�����Ӵ���ɶ��ԣ�������ר�ŵ�_DoRecv�������д����������
						_DoRecv( pSocketContext,pIoContext );
					}
					break;

					// SEND
					// �����Թ���д�ˣ�Ҫ������̫���ˣ���������⣬Send�������������һЩ
				case SEND_POSTED:
					{

					}
					break;
				default:
					// ��Ӧ��ִ�е�����
					printf("_WorkThread�е� pIoContext->m_OpType �����쳣.\n");
					break;
				} //switch
			}//if
		}//if

	}//while

	printf("�������߳� %d ���˳�.\n", nThreadNo);

	// �ͷ��̲߳���
	//RELEASE(lpParam);	

	return 0;
}

bool _PostAccept( PER_IO_CONTEXT* pAcceptIoContext )
{
	
	assert( INVALID_SOCKET!=m_pListenContext->m_Socket );

	// ׼������
	DWORD dwBytes = 0;  
	pAcceptIoContext->m_OpType = ACCEPT_POSTED;  
	WSABUF *p_wbuf   = &pAcceptIoContext->m_wsaBuf;
	OVERLAPPED *p_ol = &pAcceptIoContext->m_Overlapped;
	
	// Ϊ�Ժ�������Ŀͻ�����׼����Socket( ������봫ͳaccept�������� ) 
	pAcceptIoContext->m_sockAccept  = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED);  
	if( INVALID_SOCKET==pAcceptIoContext->m_sockAccept )  
	{  
		printf("��������Accept��Socketʧ�ܣ��������: %d", WSAGetLastError()); 
		return false;  
	} 

	// Ͷ��AcceptEx
	if(FALSE == m_lpfnAcceptEx( m_pListenContext->m_Socket, pAcceptIoContext->m_sockAccept, p_wbuf->buf, p_wbuf->len - ((sizeof(SOCKADDR_IN)+16)*2),   
								sizeof(SOCKADDR_IN)+16, sizeof(SOCKADDR_IN)+16, &dwBytes, p_ol))  
	{  
		if(WSA_IO_PENDING != WSAGetLastError())  
		{  
			printf("Ͷ�� AcceptEx ����ʧ�ܣ��������: %d\n", WSAGetLastError());  
			return false;  
		}  
	}
	return true;
}

int main() 
{
	// ��ʼ���̻߳�����
	InitializeCriticalSection(&m_csContextList);


	// ����ϵͳ�˳����¼�֪ͨ
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

	// ��ʼ��Socket��  
    WSADATA wsaData;  
    WSAStartup(MAKEWORD(2,2), &wsaData);  
    //��ʼ��Socket  
    struct sockaddr_in ServerAddress;  
    // ������Ҫ�ر�ע�⣬���Ҫʹ���ص�I/O�Ļ����������Ҫʹ��WSASocket����ʼ��Socket  
    // ע�������и�WSA_FLAG_OVERLAPPED����  
    m_pListenContext->m_Socket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);//::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    
	
	// ����ַ�ṹ��Ϣ  
    ZeroMemory((char *)&ServerAddress, sizeof(ServerAddress));  
    ServerAddress.sin_family = AF_INET;  
    // �������ѡ����κ�һ�����õĵ�ַ���������Լ�ָ����һ��IP��ַ   
    ServerAddress.sin_addr.s_addr = htonl(INADDR_ANY);                        
    //ServerAddress.sin_addr.s_addr = inet_addr(�����IP��);           
    ServerAddress.sin_port = htons(11111);                            
    // �󶨶˿�
	int error = bind(m_pListenContext->m_Socket, (struct sockaddr *) &ServerAddress, sizeof(ServerAddress));
    if (error == SOCKET_ERROR) 
	{
		error = WSAGetLastError();
	    printf("error %d\n", error);
	}

	// ��ʼ����  
	listen(m_pListenContext->m_Socket, SOMAXCONN);

	handle = CreateIoCompletionPort((HANDLE) m_pListenContext->m_Socket, handle, (DWORD) m_pListenContext, 0);
	if (handle == NULL) 
	{
	    DWORD error = GetLastError();
	    printf("error %d\n", error);
		return 1;
	}

	// ʹ��AcceptEx��������Ϊ���������WinSock2�淶֮���΢�������ṩ����չ����
	// ������Ҫ�����ȡһ�º�����ָ�룬
	// ��ȡAcceptEx����ָ��
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
		printf("WSAIoctl δ�ܻ�ȡAcceptEx����ָ�롣�������: %d\n", WSAGetLastError()); 
		//this->_DeInitialize();
		return 1;  
	}  

	// ��ȡGetAcceptExSockAddrs����ָ�룬Ҳ��ͬ��
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
		printf("WSAIoctl δ�ܻ�ȡGuidGetAcceptExSockAddrs����ָ�롣�������: %d\n", WSAGetLastError());  
		//this->_DeInitialize();
		return false; 
	}  


	// ΪAcceptEx ׼��������Ȼ��Ͷ��AcceptEx I/O����
	for(i=0;i<MAX_POST_ACCEPT;i++ )
	{
		// �½�һ��IO_CONTEXT
		PER_IO_CONTEXT* pAcceptIoContext = m_pListenContext->GetNewIoContext();

		if( false== _PostAccept( pAcceptIoContext ) )
		{
			m_pListenContext->RemoveContext(pAcceptIoContext);
			return false;
		}
	}

	printf("Ͷ�� %d ��AcceptEx�������\n", MAX_POST_ACCEPT );
	ExitThread(0);
}