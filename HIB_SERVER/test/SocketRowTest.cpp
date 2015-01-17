#include <winsock2.h>  
#include <ws2tcpip.h>
#include "../net/socket/HardSocket.h"
#include <iostream>
using namespace std;
 
#pragma comment(lib, "ws2_32.lib")  

#define BUFFER_SIZE 1024  
#define SIO_RCVALL _WSAIOW(IOC_VENDOR,1)  
  
typedef struct _TCP //应用层，传输层层
{  
    WORD SrcPort; // 源端口  
    WORD DstPort; // 目的端口  
    DWORD SeqNum; // 顺序号  
    DWORD AckNum; // 确认号  
    BYTE DataOff; // TCP头长  
    BYTE Flags; // 标志（URG、ACK等）  
    WORD Window; // 窗口大小  
    WORD Chksum; // 校验和  
    WORD UrgPtr; // 紧急指针  
} TCP;
  
typedef TCP *LPTCP;  
typedef TCP UNALIGNED * ULPTCP;  
  
  
typedef struct _IP //传输层，网络层  
{  
    union  
	{
        BYTE Version; // 版本  
        BYTE HdrLen;  // IHL  
	};

    BYTE ServiceType; // 服务类型  
    WORD TotalLen; // 总长  
    WORD ID; // 标识  
    
	union  
	{
        WORD Flags; // 标志  
        WORD FragOff; // 分段偏移  
	};

	BYTE TimeToLive; // 生命期  
    BYTE Protocol; // 协议  
    WORD HdrChksum; // 头校验和  
    DWORD SrcAddr; // 源地址  
    DWORD DstAddr; // 目的地址  
    BYTE Options; // 选项
} IP;

typedef IP * LPIP;  
typedef IP UNALIGNED * ULPIP;  
  
#define PROTOCOL_STRING_ICMP_TXT "ICMP"  
#define PROTOCOL_STRING_TCP_TXT "TCP"  
#define PROTOCOL_STRING_UDP_TXT "UDP"  
#define PROTOCOL_STRING_SPX_TXT "SPX"  
#define PROTOCOL_STRING_NCP_TXT "NCP"  
#define PROTOCOL_STRING_UNKNOW_TXT "UNKNOW"  

char* GetProtocolTxt(int Protocol)
{
    switch (Protocol)
	{
        case IPPROTO_ICMP : //1  
            return PROTOCOL_STRING_ICMP_TXT;  
        case IPPROTO_TCP : //6  
            return PROTOCOL_STRING_TCP_TXT;  
        case IPPROTO_UDP : //17  
            return PROTOCOL_STRING_UDP_TXT;  
        default:  
            return PROTOCOL_STRING_UNKNOW_TXT;  
	}
}

void testWSAEnumProtocols() 
{
    WSADATA wsadata;
    // 检查 Winsock 版本号，WSAData为WSADATA结构对象
    int erro = WSAStartup(MAKEWORD(1, 1), &wsadata);
    if(erro != 0) 
	{
       cout<<"初始化失败"<<endl;
       return;
	}

	DWORD dwBufferLen = 16384;
	LPWSAPROTOCOL_INFO lpProtocolInfo = NULL;
	lpProtocolInfo = (LPWSAPROTOCOL_INFO) malloc(dwBufferLen);
	if (lpProtocolInfo == NULL) {
        wprintf(L"Memory allocation for providers buffer failed\n");
        WSACleanup();
        return;
    }
	INT iNuminfo = 0;
	iNuminfo = WSAEnumProtocols(NULL, lpProtocolInfo, &dwBufferLen);
	if (iNuminfo == SOCKET_ERROR) 
	{
		int error = WSAGetLastError();
		printf("error %d\n", error);
		return;
	}
	wprintf(L"WSAEnumProtocols succeeded with protocol count = %d\n\n", iNuminfo);
	int i = 0;
    for (i = 0; i < iNuminfo; i++) {
        wprintf(L"Winsock Catalog Provider Entry #%d\n", i);
        wprintf
            (L"----------------------------------------------------------\n");
        wprintf(L"Entry type:\t\t\t ");
        if (lpProtocolInfo[i].ProtocolChain.ChainLen == 1)
            wprintf(L"Base Service Provider\n");
        else
            wprintf(L"Layered Chain Entry\n");

        wprintf(L"Protocol:\t\t\t %ws\n", lpProtocolInfo[i].szProtocol);

		int iRet = 0;
		WCHAR GuidString[40] = { 0 };
        iRet = StringFromGUID2(lpProtocolInfo[i].ProviderId,
                            (LPOLESTR) & GuidString, 39);
        if (iRet == 0)
            wprintf(L"StringFromGUID2 failed\n");
        else
            wprintf(L"Provider ID:\t\t\t %ws\n", GuidString);

        wprintf(L"Catalog Entry ID:\t\t %u\n",
                lpProtocolInfo[i].dwCatalogEntryId);

        wprintf(L"Version:\t\t\t %d\n", lpProtocolInfo[i].iVersion);

        wprintf(L"Address Family:\t\t\t %d\n",
                lpProtocolInfo[i].iAddressFamily);
        wprintf(L"Max Socket Address Length:\t %d\n",
                lpProtocolInfo[i].iMaxSockAddr);
        wprintf(L"Min Socket Address Length:\t %d\n",
                lpProtocolInfo[i].iMinSockAddr);

        wprintf(L"Socket Type:\t\t\t %d\n", lpProtocolInfo[i].iSocketType);
        wprintf(L"Socket Protocol:\t\t %d\n", lpProtocolInfo[i].iProtocol);
        wprintf(L"Socket Protocol Max Offset:\t %d\n",
                lpProtocolInfo[i].iProtocolMaxOffset);

        wprintf(L"Network Byte Order:\t\t %d\n",
                lpProtocolInfo[i].iNetworkByteOrder);
        wprintf(L"Security Scheme:\t\t %d\n",
                lpProtocolInfo[i].iSecurityScheme);
        wprintf(L"Max Message Size:\t\t %u\n", lpProtocolInfo[i].dwMessageSize);

        wprintf(L"ServiceFlags1:\t\t\t 0x%x\n",
                lpProtocolInfo[i].dwServiceFlags1);
        wprintf(L"ServiceFlags2:\t\t\t 0x%x\n",
                lpProtocolInfo[i].dwServiceFlags2);
        wprintf(L"ServiceFlags3:\t\t\t 0x%x\n",
                lpProtocolInfo[i].dwServiceFlags3);
        wprintf(L"ServiceFlags4:\t\t\t 0x%x\n",
                lpProtocolInfo[i].dwServiceFlags4);
        wprintf(L"ProviderFlags:\t\t\t 0x%x\n",
                lpProtocolInfo[i].dwProviderFlags);

        wprintf(L"Protocol Chain length:\t\t %d\n",
                lpProtocolInfo[i].ProtocolChain.ChainLen);

        wprintf(L"\n");
    }

    if (lpProtocolInfo) {
        free(lpProtocolInfo);
        lpProtocolInfo = NULL;
    }
}

void testSocketRow() 
{
    WSADATA wsadata;
    // 检查 Winsock 版本号，WSAData为WSADATA结构对象
    int erro = WSAStartup(MAKEWORD(1, 1), &wsadata);
    if(erro != 0) 
	{
       cout<<"初始化失败"<<endl;
       return;
	}

    // 创建原始套接字
	//HardSocket *socket = new HardSocket(
    SOCKET sock;
    sock = socket(AF_INET, SOCK_RAW, IPPROTO_IP);
    
	/*
	 * 设置IP头操作选项，其中flag 设置为ture，亲自对IP头进行处理
	 * 
	 */
    BOOL flag = TRUE;
	int error = setsockopt(sock, IPPROTO_IP, IP_HDRINCL, (char*)&flag, sizeof(flag));
    if (error) 
	{
	    error = WSAGetLastError();
		printf("error %d\n", error);
		return;
	}

	// 获取本机名
    char LocalName[512];
    error = gethostname((char*)LocalName, sizeof(LocalName)-1);
    if (error) 
	{
		error = WSAGetLastError();
		printf("error %d\n", error);
		return;
	}
	
	// 获取本地 IP 地址
    hostent * pHost;
    pHost = gethostbyname((char*)LocalName);
    
	
	/**
	 * 填充SOCKADDR_IN结构
	 *
	 * struct sockaddr_in {
     *     short   sin_family;
     *     u_short sin_port;
     *     struct  in_addr sin_addr;
     *     char    sin_zero[8];
	 * };
	 * 
	 * struct in_addr {
     *     union {
     *         struct { 
	 *             u_char s_b1,s_b2,s_b3,s_b4; 
	 *         } S_un_b;
     *         
	 *         struct { 
	 *             u_short s_w1,s_w2; 
	 *         } S_un_w;
     *         
	 *         u_long S_addr;
     * } S_un;
	 * 
	 * #define s_addr  S_un.S_addr  
	 *         //* can be used for most tcp & ip code 
	 *
     * #define s_host  S_un.S_un_b.s_b2 
	 *         //* host on imp 
	 * #define s_net   S_un.S_un_b.s_b1
     *         //* network 
	 * #define s_imp   S_un.S_un_w.s_w2
     *         //* imp
	 * #define s_impno S_un.S_un_b.s_b4
     *         //* imp # 
	 * #define s_lh    S_un.S_un_b.s_b3
     *         //* logical host 
	 * };
	 */
    SOCKADDR_IN addr_in;
	char* addr = pHost->h_addr;//h_addr_list[0]; //IP h_addr定义的宏
    addr_in.sin_addr= *(in_addr *) addr;
    addr_in.sin_family = AF_INET;
    addr_in.sin_port = htons(1004);
    // 把原始套接字sock 绑定到本地网卡地址上
    bind(sock, (PSOCKADDR)&addr_in, sizeof(addr_in));
	printf("bind %s\n", addr);


    // dwValue为输入输出参数，为1时执行，0时取消
    DWORD dwValue = 1;
    // 设置 SOCK_RAW 为SIO_RCVALL，以便接收所有的IP包。其中SIO_RCVALL
    // 的定义为： #define SIO_RCVALL _WSAIOW(IOC_VENDOR,1)
    error = ioctlsocket(sock, SIO_RCVALL, &dwValue); //将网卡设置为混合模式
    if (error) 
	{
        error = WSAGetLastError();
		printf("error %d\n", error);
		return;
	}

	char RecvBuf[BUFFER_SIZE];
    IP ip;
    TCP tcp;
    while (true)
	{
        // 接收原始数据包信息
        int ret = recv(sock, RecvBuf, BUFFER_SIZE, 0);
        if (ret != 0)
		{
            // 对数据包进行分析，并输出分析结果
            ip = *(IP*)RecvBuf;
            tcp = *(TCP*)(RecvBuf + ip.HdrLen);
            cout<<"协议"<<GetProtocolTxt(ip.Protocol)<<endl;
            cout<<"IP源地址"<<inet_ntoa(*(in_addr*)&ip.SrcAddr)<<endl;
            cout<<"IP目标地址"<<inet_ntoa(*(in_addr*)&ip.DstAddr)<<endl;
            cout<<"TCP源端口号"<<tcp.SrcPort<<endl;
            cout<<"TCP目标端口号"<<tcp.DstPort<<endl;
            cout<<"数据包长度"<<ntohs(ip.TotalLen)<<endl;
            //cout<<(char *)(RecvBuf+sizeof(ip)+sizeof(tcp));
			//cout<<(char *)(RecvBuf+28)<<endl;
		}
	}
}

//*.cpp
void main()
{
	//testWSAEnumProtocols();
    testSocketRow();
}