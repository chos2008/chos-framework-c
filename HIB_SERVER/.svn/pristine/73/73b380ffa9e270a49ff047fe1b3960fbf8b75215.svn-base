#include <stdio.h > 
#include <winsock2.h > 
#include <ws2tcpip.h > 

#define ICMP_ECHO 8 
/*定义IP报头数据结构*/
typedef struct iphdr { 
	unsigned char verlen; 			//头的版本和长度
	unsigned char tos; 				//服务类型
	unsigned short total_len; 			//整个包的长度
	unsigned short ident; 			//唯一标示符
	unsigned short frag_and_flags; 		//flags 
	unsigned char ttl;				//生存时间
	unsigned char proto; 			//protocol (TCP, UDP etc) 
	unsigned short checksum; 			//IP交验和 
	unsigned int sourceIP;			//源地址
	unsigned int destIP;				//目标地址
} IPHDR; 
/*定义ICMP报头数据结构*/
typedef struct icmphdr { 
	BYTE i_type;				//类型，长度为8位
	BYTE i_code;				//编码，长度为8位
	USHORT i_cksum;				//校验，长度为16位
	USHORT i_id;				//标识符,用于唯一标识ICMP报文
	USHORT i_seq;				//顺序号,代表ICMP报文的发送顺序
} ICMPHDR; 
//声明计算IP校验和函数cal_checksum
unsigned short cal_checksum( unsigned short *buf, int size); 
unsigned short cal_checksum( unsigned short *buf, int size) 
{ 
	unsigned long cksum = 0; 
	
	while( size > 1) { 
		cksum += *buf++; 
		size -= sizeof( unsigned short); 
	} 
	
	if(size) { 
		cksum += *( unsigned char *)buf;			//被校验的数据16位进行累加
	} 
	
	cksum = ( cksum >> 16) + ( cksum & 0xffff);		//取反码
	cksum += (cksum >>16); 
	return ( unsigned short)(~cksum); 
}

void main() 
{ 
	SOCKET s; 
	WSADATA WSAData; 
	BOOL bIphdrIncl; 
	int iRtn; 
	IPHDR *pIphdr; 
	ICMPHDR *pIcmphdr; 
	unsigned long *pIcmpdata; 
	char buf[1024]; 
	struct sockaddr_in dest; 
	
	memset(buf, 0, 1024);
	if ( WSAStartup( MAKEWORD( 2, 2), &WSAData)) {	/*启动 winsock*/
		printf( "fail to start up winsock.\n "); 
		return; 
	} 
	
	//创建一个新的socket连接，并发送ICMP_ECHO消息 
	s = socket( AF_INET, SOCK_RAW, IPPROTO_IP); 
	if ( s == INVALID_SOCKET) { 
		printf( "socket error.\n "); 
		return; 
	} 
	
	bIphdrIncl = TRUE; 
	iRtn = setsockopt(s, IPPROTO_IP, IP_HDRINCL, (const char *)&bIphdrIncl, sizeof(BOOL)); 
	if(iRtn) 
	{
		printf( "fail to set sock option.\n ");
		return;
	} 
	
	//填写ip报头 
	pIphdr = (IPHDR *) buf;
	pIphdr->verlen = 0x45;
	pIphdr->tos = 0;
	pIphdr->total_len = sizeof(IPHDR) + sizeof(ICMPHDR) + sizeof(unsigned long);
	pIphdr->ident = htons(0); 
	pIphdr->frag_and_flags = htons(0); 
	pIphdr->ttl = 255; 
	pIphdr->proto = IPPROTO_ICMP; 
	pIphdr->sourceIP = inet_addr("192.168.0.1"); 
	pIphdr->destIP = inet_addr("192.168.0.202"); 
	pIphdr->checksum = 0; 
	
	// 填充icmp头... 
	pIcmphdr = (ICMPHDR *) (buf + sizeof(IPHDR)); 
	pIcmphdr->i_type = ICMP_ECHO;
	pIcmphdr->i_code = 0;
	pIcmphdr->i_cksum = 0;
	pIcmphdr->i_id = (unsigned short) GetCurrentProcessId();
	pIcmphdr->i_seq = 0;
	
	// 填充icmp数据 ... 
	pIcmpdata = ( unsigned long *)(buf + sizeof( IPHDR) + sizeof( ICMPHDR)); 
	*pIcmpdata = GetTickCount(); 
	
	// 计算icmp校验和 ... 
	pIcmphdr->i_cksum = cal_checksum( (unsigned short *)pIcmphdr, sizeof(ICMPHDR) + sizeof(unsigned long)); 
	
	// 计算ip校验和 ... 
	pIphdr->checksum = cal_checksum( (unsigned short *)pIphdr, pIphdr->total_len); 
	
	dest.sin_addr.S_un.S_addr = inet_addr("192.168.0.1"); 
	dest.sin_family = AF_INET;
	
/*
	DWORD value = (DWORD) 10000;
	int error = setsockopt(s, SOL_SOCKET, SO_SNDTIMEO, (char *) &value, sizeof(DWORD));
    if (error) 
	{
	    error = WSAGetLastError();
		//throw SocketException(error);
	}
*/
	iRtn = sendto(s, buf, pIphdr->total_len, 0, (const SOCKADDR *) &dest, sizeof(dest));		//发送IP包
	if (iRtn == SOCKET_ERROR)
	{
		int error = WSAGetLastError();
		printf("error %d\n", error);
		return;
	}
	else 
	{
		printf( "success.\n "); 
	}

	closesocket(s);				/*关闭socket连接*/
	Sleep(10000);
	ExitThread(0);
	WSACleanup(); 
}