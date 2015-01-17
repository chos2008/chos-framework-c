#include <assert.h>
#include <vector>
#include <winsock2.h>
#include <MSWSock.h>
#pragma comment(lib,"ws2_32.lib")


// ÿһ���������ϲ������ٸ��߳�(Ϊ������޶ȵ��������������ܣ���������ĵ�)
#define WORKER_THREADS_PER_PROCESSOR 2
// ͬʱͶ�ݵ�Accept���������(���Ҫ����ʵ�ʵ�����������)
#define MAX_POST_ACCEPT              10
// ���ݸ�Worker�̵߳��˳��ź�
#define EXIT_CODE                    NULL


// �ͷ�ָ��;����Դ�ĺ�

// �ͷ�ָ���
#define RELEASE(x)                      {if(x != NULL ){delete x;x=NULL;}}
// �ͷž����
#define RELEASE_HANDLE(x)               {if(x != NULL && x!=INVALID_HANDLE_VALUE){ CloseHandle(x);x = NULL;}}
// �ͷ�Socket��
#define RELEASE_SOCKET(x)               {if(x !=INVALID_SOCKET) { closesocket(x);x=INVALID_SOCKET;}}





// ���������� (1024*8)
// ֮����Ϊʲô����8K��Ҳ��һ�������ϵľ���ֵ
// ���ȷʵ�ͻ��˷�����ÿ�����ݶ��Ƚ��٣���ô�����õ�СһЩ��ʡ�ڴ�
#define MAX_BUFFER_LEN        8192  
// Ĭ�϶˿�
#define DEFAULT_PORT          12345    
// Ĭ��IP��ַ
#define DEFAULT_IP            "127.0.0.1"


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




//====================================================================================
//
//				CIOCPModel�ඨ��
//
//====================================================================================

// �������̵߳��̲߳���

typedef struct _tagThreadParams_WORKER
{
	//CIOCPModel* pIOCPModel;                                   // ��ָ�룬���ڵ������еĺ���
	int         nThreadNo;                                    // �̱߳��

} THREADPARAMS_WORKER,*PTHREADPARAM_WORKER; 


HANDLE                       m_hShutdownEvent;              // ����֪ͨ�߳�ϵͳ�˳����¼���Ϊ���ܹ����õ��˳��߳�

HANDLE                       m_hIOCompletionPort;           // ��ɶ˿ڵľ��

HANDLE*                      m_phWorkerThreads;             // �������̵߳ľ��ָ��

int		                     m_nThreads;                    // ���ɵ��߳�����
char*                      m_strIP;                       // �������˵�IP��ַ
int                          m_nPort;                       // �������˵ļ����˿�

//CDialog*                     m_pMain;                       // ������Ľ���ָ�룬����������������ʾ��Ϣ

CRITICAL_SECTION             m_csContextList;               // ����Worker�߳�ͬ���Ļ�����

std::vector<PER_SOCKET_CONTEXT*>  m_arrayClientContext;          // �ͻ���Socket��Context��Ϣ        

PER_SOCKET_CONTEXT*          m_pListenContext;              // ���ڼ�����Socket��Context��Ϣ

LPFN_ACCEPTEX                m_lpfnAcceptEx;                // AcceptEx �� GetAcceptExSockaddrs �ĺ���ָ�룬���ڵ�����������չ����
LPFN_GETACCEPTEXSOCKADDRS    m_lpfnGetAcceptExSockAddrs; 


// ����������
bool Start();

//	ֹͣ������
void Stop();

// ����Socket��
bool LoadSocketLib();

// ж��Socket�⣬��������
void UnloadSocketLib() { WSACleanup(); }

// ��ñ�����IP��ַ
char* GetLocalIP();

// ���ü����˿�
void SetPort( const int& nPort ) { m_nPort=nPort; }

// �����������ָ�룬���ڵ�����ʾ��Ϣ��������
//void SetMainDlg( CDialog* p ) { m_pMain=p; }

// ��ʼ��IOCP
bool _InitializeIOCP();

// ��ʼ��Socket
bool _InitializeListenSocket();

// ����ͷ���Դ
void _DeInitialize();

// Ͷ��Accept����
bool _PostAccept( PER_IO_CONTEXT* pAcceptIoContext ); 

// Ͷ�ݽ�����������
bool _PostRecv( PER_IO_CONTEXT* pIoContext );

// ���пͻ��������ʱ�򣬽��д���
bool _DoAccpet( PER_SOCKET_CONTEXT* pSocketContext, PER_IO_CONTEXT* pIoContext );

// ���н��յ����ݵ����ʱ�򣬽��д���
bool _DoRecv( PER_SOCKET_CONTEXT* pSocketContext, PER_IO_CONTEXT* pIoContext );

// ���ͻ��˵������Ϣ�洢��������
void _AddToContextList( PER_SOCKET_CONTEXT *pSocketContext );

// ���ͻ��˵���Ϣ���������Ƴ�
void _RemoveContext( PER_SOCKET_CONTEXT *pSocketContext );

// ��տͻ�����Ϣ
void _ClearContextList();

// ������󶨵���ɶ˿���
bool _AssociateWithIOCP( PER_SOCKET_CONTEXT *pContext);

// ������ɶ˿��ϵĴ���
bool HandleError( PER_SOCKET_CONTEXT *pContext,const DWORD& dwErr );

// �̺߳�����ΪIOCP�������Ĺ������߳�
static DWORD WINAPI _WorkerThread(LPVOID lpParam);

// ��ñ����Ĵ���������
int _GetNoOfProcessors();

// �жϿͻ���Socket�Ƿ��Ѿ��Ͽ�
bool _IsSocketAlive(SOCKET s);

// ������������ʾ��Ϣ
void _ShowMessage( const char* szFormat,...);


int main() 
{
	m_nThreads = 0;
	m_hShutdownEvent = NULL;
	m_hIOCompletionPort = NULL;
	m_phWorkerThreads = NULL;
    m_strIP = DEFAULT_IP;
	m_nPort = DEFAULT_PORT;
	//m_pMain = NULL;
    m_lpfnAcceptEx = NULL;
	m_pListenContext = NULL;


	// ��ʼ��Socket��
	if( false==LoadSocketLib() )
	{
		printf("����Winsock 2.2ʧ�ܣ����������޷����У�");
		return 1;
	}

	if( false == Start() )
	{
		printf("����������ʧ�ܣ�");
		return 1;
	}

	while (1)
	{
	    Sleep(5000);
	}


	//Stop();
}




///////////////////////////////////////////////////////////////////
// �������̣߳�  ΪIOCP�������Ĺ������߳�
//         Ҳ����ÿ����ɶ˿��ϳ�����������ݰ����ͽ�֮ȡ�������д�����߳�
///////////////////////////////////////////////////////////////////

DWORD WINAPI _WorkerThread(LPVOID lpParam)
{    
	THREADPARAMS_WORKER* pParam = (THREADPARAMS_WORKER*)lpParam;
	//CIOCPModel* pIOCPModel = (CIOCPModel*)pParam->pIOCPModel;
	int nThreadNo = (int)pParam->nThreadNo;

	_ShowMessage("�������߳�������ID: %d.",nThreadNo);

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
			if((0 == dwBytesTransfered) 
				&& ( RECV_POSTED == pIoContext->m_OpType || SEND_POSTED == pIoContext->m_OpType))  
			{  
				_ShowMessage("�ͻ��� %s:%d �Ͽ�����.",inet_ntoa(pSocketContext->m_ClientAddr.sin_addr), ntohs(pSocketContext->m_ClientAddr.sin_port) );

				// �ͷŵ���Ӧ����Դ
				_RemoveContext( pSocketContext );

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

	printf("�������߳� %d ���˳�.\n",nThreadNo);

	// �ͷ��̲߳���
	RELEASE(lpParam);	

	return 0;
}



//====================================================================================
//
//				    ϵͳ��ʼ������ֹ
//
//====================================================================================




////////////////////////////////////////////////////////////////////
// ��ʼ��WinSock 2.2
bool LoadSocketLib()
{    
	WSADATA wsaData;
	int nResult;
	nResult = WSAStartup(MAKEWORD(2,2), &wsaData);
	// ����(һ�㶼�����ܳ���)
	if (NO_ERROR != nResult)
	{
		_ShowMessage("��ʼ��WinSock 2.2ʧ�ܣ�\n");
		return false; 
	}

	return true;
}

//////////////////////////////////////////////////////////////////
//	����������
bool Start()
{
	// ��ʼ���̻߳�����
	InitializeCriticalSection(&m_csContextList);

	// ����ϵͳ�˳����¼�֪ͨ
	m_hShutdownEvent = CreateEvent(NULL, TRUE, FALSE, NULL);

	// ��ʼ��IOCP
	if (false == _InitializeIOCP())
	{
		_ShowMessage("��ʼ��IOCPʧ�ܣ�\n");
		return false;
	}
	else
	{
		_ShowMessage("\nIOCP��ʼ�����\n.");
	}

	// ��ʼ��Socket
	if( false==_InitializeListenSocket() )
	{
		_ShowMessage("Listen Socket��ʼ��ʧ�ܣ�\n");
		_DeInitialize();
		return false;
	}
	else
	{
		_ShowMessage("Listen Socket��ʼ�����.");
	}

	_ShowMessage("ϵͳ׼���������Ⱥ�����....\n");

	return true;
}


////////////////////////////////////////////////////////////////////
//	��ʼ����ϵͳ�˳���Ϣ���˳���ɶ˿ں��߳���Դ
void Stop()
{
	if( m_pListenContext!=NULL && m_pListenContext->m_Socket!=INVALID_SOCKET )
	{
		// ����ر���Ϣ֪ͨ
		SetEvent(m_hShutdownEvent);

		for (int i = 0; i < m_nThreads; i++)
		{
			// ֪ͨ���е���ɶ˿ڲ����˳�
			PostQueuedCompletionStatus(m_hIOCompletionPort, 0, (DWORD)EXIT_CODE, NULL);
		}

		// �ȴ����еĿͻ�����Դ�˳�
		WaitForMultipleObjects(m_nThreads, m_phWorkerThreads, TRUE, INFINITE);

		// ����ͻ����б���Ϣ
		_ClearContextList();

		// �ͷ�������Դ
		_DeInitialize();

		_ShowMessage("ֹͣ����\n");
	}	
}


////////////////////////////////
// ��ʼ����ɶ˿�
bool _InitializeIOCP()
{
	// ������һ����ɶ˿�
	m_hIOCompletionPort = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0 );

	if ( NULL == m_hIOCompletionPort)
	{
		_ShowMessage("������ɶ˿�ʧ�ܣ��������: %d!\n", WSAGetLastError());
		return false;
	}

	// ���ݱ����еĴ�����������������Ӧ���߳���
	m_nThreads = WORKER_THREADS_PER_PROCESSOR * _GetNoOfProcessors();
	
	// Ϊ�������̳߳�ʼ�����
	m_phWorkerThreads = new HANDLE[m_nThreads];
	
	// ���ݼ�����������������������߳�
	DWORD nThreadID;
	for (int i = 0; i < m_nThreads; i++)
	{
		THREADPARAMS_WORKER* pThreadParams = new THREADPARAMS_WORKER;
		//pThreadParams->pIOCPModel = this;
		pThreadParams->nThreadNo  = i+1;
		m_phWorkerThreads[i] = ::CreateThread(0, 0, _WorkerThread, (void *)pThreadParams, 0, &nThreadID);
	}

	printf(" ���� _WorkerThread %d ��.\n", m_nThreads );

	return true;
}


/////////////////////////////////////////////////////////////////
// ��ʼ��Socket
bool _InitializeListenSocket()
{
	// AcceptEx �� GetAcceptExSockaddrs ��GUID�����ڵ�������ָ��
	GUID GuidAcceptEx = WSAID_ACCEPTEX;  
	GUID GuidGetAcceptExSockAddrs = WSAID_GETACCEPTEXSOCKADDRS; 

	// ��������ַ��Ϣ�����ڰ�Socket
	struct sockaddr_in ServerAddress;

	// �������ڼ�����Socket����Ϣ
	m_pListenContext = new PER_SOCKET_CONTEXT;

	// ��Ҫʹ���ص�IO�������ʹ��WSASocket������Socket���ſ���֧���ص�IO����
	m_pListenContext->m_Socket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);
	if (INVALID_SOCKET == m_pListenContext->m_Socket) 
	{
		_ShowMessage("��ʼ��Socketʧ�ܣ��������: %d.\n", WSAGetLastError());
		return false;
	}
	else
	{
		printf("WSASocket() ���.\n");
	}

	// ��Listen Socket������ɶ˿���
	if(NULL == CreateIoCompletionPort((HANDLE) m_pListenContext->m_Socket, 
		m_hIOCompletionPort, 
		(DWORD) m_pListenContext, 
		0))
	{  
		_ShowMessage("�� Listen Socket����ɶ˿�ʧ�ܣ��������: %d/n", WSAGetLastError());  
		RELEASE_SOCKET( m_pListenContext->m_Socket );
		return false;
	}
	else
	{
		printf("Listen Socket����ɶ˿� ���.\n");
	}

	// ����ַ��Ϣ
	ZeroMemory((char *)&ServerAddress, sizeof(ServerAddress));
	ServerAddress.sin_family = AF_INET;
	// ������԰��κο��õ�IP��ַ�����߰�һ��ָ����IP��ַ 
	//ServerAddress.sin_addr.s_addr = htonl(INADDR_ANY);                      
	ServerAddress.sin_addr.s_addr = inet_addr(m_strIP);         
	ServerAddress.sin_port = htons(m_nPort);                          

	// �󶨵�ַ�Ͷ˿�
	if (SOCKET_ERROR == bind(m_pListenContext->m_Socket, (struct sockaddr *) &ServerAddress, sizeof(ServerAddress))) 
	{
		_ShowMessage("bind()����ִ�д���.\n");
		return false;
	}
	else
	{
		printf("bind() ���.\n");
	}

	// ��ʼ���м���
	if (SOCKET_ERROR == listen(m_pListenContext->m_Socket,SOMAXCONN))
	{
		_ShowMessage("Listen()����ִ�г��ִ���.\n");
		return false;
	}
	else
	{
		printf("Listen() ���.\n");
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
		_ShowMessage("WSAIoctl δ�ܻ�ȡAcceptEx����ָ�롣�������: %d\n", WSAGetLastError()); 
		_DeInitialize();
		return false;  
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
		_ShowMessage("WSAIoctl δ�ܻ�ȡGuidGetAcceptExSockAddrs����ָ�롣�������: %d\n", WSAGetLastError());  
		_DeInitialize();
		return false; 
	}  


	// ΪAcceptEx ׼��������Ȼ��Ͷ��AcceptEx I/O����
	for( int i=0;i<MAX_POST_ACCEPT;i++ )
	{
		// �½�һ��IO_CONTEXT
		PER_IO_CONTEXT* pAcceptIoContext = m_pListenContext->GetNewIoContext();

		if( false == _PostAccept( pAcceptIoContext ) )
		{
			m_pListenContext->RemoveContext(pAcceptIoContext);
			return false;
		}
	}

	_ShowMessage("Ͷ�� %d ��AcceptEx�������", MAX_POST_ACCEPT );

	return true;
}

////////////////////////////////////////////////////////////
//	����ͷŵ�������Դ
void _DeInitialize()
{
	// ɾ���ͻ����б�Ļ�����
	DeleteCriticalSection(&m_csContextList);

	// �ر�ϵͳ�˳��¼����
	RELEASE_HANDLE(m_hShutdownEvent);

	// �ͷŹ������߳̾��ָ��
	for( int i=0;i<m_nThreads;i++ )
	{
		RELEASE_HANDLE(m_phWorkerThreads[i]);
	}
	
	RELEASE(m_phWorkerThreads);

	// �ر�IOCP���
	RELEASE_HANDLE(m_hIOCompletionPort);

	// �رռ���Socket
	RELEASE(m_pListenContext);

	_ShowMessage("�ͷ���Դ���.\n");
}


//====================================================================================
//
//				    Ͷ����ɶ˿�����
//
//====================================================================================


//////////////////////////////////////////////////////////////////
// Ͷ��Accept����
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
		_ShowMessage("��������Accept��Socketʧ�ܣ��������: %d", WSAGetLastError()); 
		return false;  
	} 

	// Ͷ��AcceptEx
	if(FALSE == m_lpfnAcceptEx(m_pListenContext->m_Socket, 
		pAcceptIoContext->m_sockAccept, 
		p_wbuf->buf, 
		p_wbuf->len - ((sizeof(SOCKADDR_IN) + 16) * 2),   
		sizeof(SOCKADDR_IN) + 16, 
		sizeof(SOCKADDR_IN) + 16, 
		&dwBytes, 
		p_ol))  
	{  
		if(WSA_IO_PENDING != WSAGetLastError())  
		{  
			_ShowMessage("Ͷ�� AcceptEx ����ʧ�ܣ��������: %d", WSAGetLastError());  
			return false;  
		}  
	} 

	return true;
}

////////////////////////////////////////////////////////////
// ���пͻ��������ʱ�򣬽��д���
// �����е㸴�ӣ���Ҫ�ǿ������Ļ����Ϳ����׵��ĵ���....
// ������������Ļ�����ɶ˿ڵĻ������������һ�����

// ��֮��Ҫ֪�����������ListenSocket��Context��������Ҫ����һ�ݳ������������Socket��
// ԭ����Context����Ҫ���������Ͷ����һ��Accept����
//
bool _DoAccpet( PER_SOCKET_CONTEXT* pSocketContext, PER_IO_CONTEXT* pIoContext )
{
	SOCKADDR_IN* ClientAddr = NULL;
	SOCKADDR_IN* LocalAddr = NULL;  
	int remoteLen = sizeof(SOCKADDR_IN), localLen = sizeof(SOCKADDR_IN);  

	///////////////////////////////////////////////////////////////////////////
	// 1. ����ȡ������ͻ��˵ĵ�ַ��Ϣ
	// ��� m_lpfnGetAcceptExSockAddrs �����˰�~~~~~~
	// ��������ȡ�ÿͻ��˺ͱ��ض˵ĵ�ַ��Ϣ������˳��ȡ���ͻ��˷����ĵ�һ�����ݣ���ǿ����...
	m_lpfnGetAcceptExSockAddrs(
		pIoContext->m_wsaBuf.buf, 
		pIoContext->m_wsaBuf.len - ((sizeof(SOCKADDR_IN)+16)*2),  
		sizeof(SOCKADDR_IN)+16, 
		sizeof(SOCKADDR_IN)+16, 
		(LPSOCKADDR*)&LocalAddr, 
		&localLen, 
		(LPSOCKADDR*)&ClientAddr, 
		&remoteLen);  

	_ShowMessage("�ͻ��� %s:%d ����.", inet_ntoa(ClientAddr->sin_addr), ntohs(ClientAddr->sin_port) );
	_ShowMessage("�ͻ��� %s:%d ��Ϣ��%s.",inet_ntoa(ClientAddr->sin_addr), ntohs(ClientAddr->sin_port),pIoContext->m_wsaBuf.buf );


	//////////////////////////////////////////////////////////////////////////////////////////////////////
	// 2. ������Ҫע�⣬���ﴫ��������ListenSocket�ϵ�Context�����Context���ǻ���Ҫ���ڼ�����һ������
	// �����һ���Ҫ��ListenSocket�ϵ�Context���Ƴ���һ��Ϊ�������Socket�½�һ��SocketContext

	PER_SOCKET_CONTEXT* pNewSocketContext = new PER_SOCKET_CONTEXT;
	pNewSocketContext->m_Socket           = pIoContext->m_sockAccept;
	memcpy(&(pNewSocketContext->m_ClientAddr), ClientAddr, sizeof(SOCKADDR_IN));

	// ����������ϣ������Socket����ɶ˿ڰ�(��Ҳ��һ���ؼ�����)
	if( false == _AssociateWithIOCP( pNewSocketContext ) )
	{
		RELEASE( pNewSocketContext );
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
	if( false == _PostRecv( pNewIoContext) )
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

////////////////////////////////////////////////////////////////////
// Ͷ�ݽ�����������
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
		_ShowMessage("Ͷ�ݵ�һ��WSARecvʧ�ܣ�");
		return false;
	}
	return true;
}

/////////////////////////////////////////////////////////////////
// ���н��յ����ݵ����ʱ�򣬽��д���
bool _DoRecv( PER_SOCKET_CONTEXT* pSocketContext, PER_IO_CONTEXT* pIoContext )
{
	// �Ȱ���һ�ε�������ʾ���֣�Ȼ�������״̬��������һ��Recv����
	SOCKADDR_IN* ClientAddr = &pSocketContext->m_ClientAddr;
	_ShowMessage("�յ�  %s:%d ��Ϣ��%s",inet_ntoa(ClientAddr->sin_addr), ntohs(ClientAddr->sin_port),pIoContext->m_wsaBuf.buf );

	// Ȼ��ʼͶ����һ��WSARecv����
	return _PostRecv( pIoContext );
}



/////////////////////////////////////////////////////
// �����(Socket)�󶨵���ɶ˿���
bool _AssociateWithIOCP( PER_SOCKET_CONTEXT *pContext )
{
	// �����ںͿͻ���ͨ�ŵ�SOCKET�󶨵���ɶ˿���
	HANDLE hTemp = CreateIoCompletionPort((HANDLE)pContext->m_Socket, m_hIOCompletionPort, (DWORD)pContext, 0);

	if (NULL == hTemp)
	{
		_ShowMessage("ִ��CreateIoCompletionPort()���ִ���.������룺%d", 
			GetLastError());
		return false;
	}

	return true;
}




//====================================================================================
//
//				    ContextList ��ز���
//
//====================================================================================


//////////////////////////////////////////////////////////////
// ���ͻ��˵������Ϣ�洢��������
void _AddToContextList( PER_SOCKET_CONTEXT *pHandleData )
{
	EnterCriticalSection(&m_csContextList);

	m_arrayClientContext.push_back(pHandleData);	
	
	LeaveCriticalSection(&m_csContextList);
}

////////////////////////////////////////////////////////////////
//	�Ƴ�ĳ���ض���Context
void _RemoveContext( PER_SOCKET_CONTEXT *pSocketContext )
{
	EnterCriticalSection(&m_csContextList);

	for( int i=0;i<m_arrayClientContext.size();i++ )
	{
		if( pSocketContext==m_arrayClientContext.at(i) )
		{
			RELEASE( pSocketContext );			
			m_arrayClientContext.erase(m_arrayClientContext.begin() + i);			
			break;
		}
	}

	LeaveCriticalSection(&m_csContextList);
}

////////////////////////////////////////////////////////////////
// ��տͻ�����Ϣ
void _ClearContextList()
{
	EnterCriticalSection(&m_csContextList);

	for( int i=0;i<m_arrayClientContext.size();i++ )
	{
		delete m_arrayClientContext.at(i);
	}

	m_arrayClientContext.clear();

	LeaveCriticalSection(&m_csContextList);
}



//====================================================================================
//
//				       ����������������
//
//====================================================================================



////////////////////////////////////////////////////////////////////
// ��ñ�����IP��ַ
char* GetLocalIP()
{
	// ��ñ���������
	char hostname[MAX_PATH] = {0};
	gethostname(hostname,MAX_PATH);                
	struct hostent FAR* lpHostEnt = gethostbyname(hostname);
	if(lpHostEnt == NULL)
	{
		return DEFAULT_IP;
	}

	// ȡ��IP��ַ�б��еĵ�һ��Ϊ���ص�IP(��Ϊһ̨�������ܻ�󶨶��IP)
	LPSTR lpAddr = lpHostEnt->h_addr_list[0];      

	// ��IP��ַת�����ַ�����ʽ
	struct in_addr inAddr;
	memmove(&inAddr,lpAddr,4);
	return inet_ntoa(inAddr);

}

///////////////////////////////////////////////////////////////////
// ��ñ����д�����������
int _GetNoOfProcessors()
{
	SYSTEM_INFO si;

	GetSystemInfo(&si);

	return si.dwNumberOfProcessors;
}

/////////////////////////////////////////////////////////////////////
// ������������ʾ��ʾ��Ϣ
void _ShowMessage(const char* szFormat,...)
{
	// ���ݴ���Ĳ�����ʽ���ַ���
	//CString   strMessage;
	va_list   arglist;

	// ����䳤����
	va_start(arglist, szFormat);
	//strMessage.FormatV(szFormat,arglist);
	vfprintf(stderr, szFormat, arglist);
	va_end(arglist);
	fflush(stderr);
	// ������������ʾ
	/*
	CMainDlg* pMain = (CMainDlg*)m_pMain;
	if( m_pMain!=NULL )
	{
		pMain->AddInformation(strMessage);
		TRACE( strMessage+_T("\n") );
	}
	*/
}

/////////////////////////////////////////////////////////////////////
// �жϿͻ���Socket�Ƿ��Ѿ��Ͽ���������һ����Ч��Socket��Ͷ��WSARecv����������쳣
// ʹ�õķ����ǳ��������socket�������ݣ��ж����socket���õķ���ֵ
// ��Ϊ����ͻ��������쳣�Ͽ�(����ͻ��˱������߰ε����ߵ�)��ʱ�򣬷����������޷��յ��ͻ��˶Ͽ���֪ͨ��

bool _IsSocketAlive(SOCKET s)
{
	int nByteSent=send(s,"",0,0);
	if (-1 == nByteSent) return false;
	return true;
}

///////////////////////////////////////////////////////////////////
// ��ʾ��������ɶ˿��ϵĴ���
bool HandleError( PER_SOCKET_CONTEXT *pContext,const DWORD& dwErr )
{
	// ����ǳ�ʱ�ˣ����ټ����Ȱ�  
	if(WAIT_TIMEOUT == dwErr)  
	{  	
		// ȷ�Ͽͻ����Ƿ񻹻���...
		if( !_IsSocketAlive( pContext->m_Socket) )
		{
			_ShowMessage("��⵽�ͻ����쳣�˳���");
			_RemoveContext( pContext );
			return true;
		}
		else
		{
			_ShowMessage("���������ʱ��������...");
			return true;
		}
	}  

	// �����ǿͻ����쳣�˳���
	else if( ERROR_NETNAME_DELETED==dwErr )
	{
		_ShowMessage("��⵽�ͻ����쳣�˳���");
		_RemoveContext( pContext );
		return true;
	}

	else
	{
		_ShowMessage("��ɶ˿ڲ������ִ����߳��˳���������룺%d",dwErr );
		return false;
	}
}




