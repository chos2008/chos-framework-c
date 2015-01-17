#include <stdio.h > 
#include <winsock2.h > 
#include <ws2tcpip.h > 

#define ICMP_ECHO 8 
/*����IP��ͷ���ݽṹ*/
typedef struct iphdr { 
	unsigned char verlen; 			//ͷ�İ汾�ͳ���
	unsigned char tos; 				//��������
	unsigned short total_len; 			//�������ĳ���
	unsigned short ident; 			//Ψһ��ʾ��
	unsigned short frag_and_flags; 		//flags 
	unsigned char ttl;				//����ʱ��
	unsigned char proto; 			//protocol (TCP, UDP etc) 
	unsigned short checksum; 			//IP����� 
	unsigned int sourceIP;			//Դ��ַ
	unsigned int destIP;				//Ŀ���ַ
} IPHDR; 
/*����ICMP��ͷ���ݽṹ*/
typedef struct icmphdr { 
	BYTE i_type;				//���ͣ�����Ϊ8λ
	BYTE i_code;				//���룬����Ϊ8λ
	USHORT i_cksum;				//У�飬����Ϊ16λ
	USHORT i_id;				//��ʶ��,����Ψһ��ʶICMP����
	USHORT i_seq;				//˳���,����ICMP���ĵķ���˳��
} ICMPHDR; 
//��������IPУ��ͺ���cal_checksum
unsigned short cal_checksum( unsigned short *buf, int size); 
unsigned short cal_checksum( unsigned short *buf, int size) 
{ 
	unsigned long cksum = 0; 
	
	while( size > 1) { 
		cksum += *buf++; 
		size -= sizeof( unsigned short); 
	} 
	
	if(size) { 
		cksum += *( unsigned char *)buf;			//��У�������16λ�����ۼ�
	} 
	
	cksum = ( cksum >> 16) + ( cksum & 0xffff);		//ȡ����
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
	if ( WSAStartup( MAKEWORD( 2, 2), &WSAData)) {	/*���� winsock*/
		printf( "fail to start up winsock.\n "); 
		return; 
	} 
	
	//����һ���µ�socket���ӣ�������ICMP_ECHO��Ϣ 
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
	
	//��дip��ͷ 
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
	
	// ���icmpͷ... 
	pIcmphdr = (ICMPHDR *) (buf + sizeof(IPHDR)); 
	pIcmphdr->i_type = ICMP_ECHO;
	pIcmphdr->i_code = 0;
	pIcmphdr->i_cksum = 0;
	pIcmphdr->i_id = (unsigned short) GetCurrentProcessId();
	pIcmphdr->i_seq = 0;
	
	// ���icmp���� ... 
	pIcmpdata = ( unsigned long *)(buf + sizeof( IPHDR) + sizeof( ICMPHDR)); 
	*pIcmpdata = GetTickCount(); 
	
	// ����icmpУ��� ... 
	pIcmphdr->i_cksum = cal_checksum( (unsigned short *)pIcmphdr, sizeof(ICMPHDR) + sizeof(unsigned long)); 
	
	// ����ipУ��� ... 
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
	iRtn = sendto(s, buf, pIphdr->total_len, 0, (const SOCKADDR *) &dest, sizeof(dest));		//����IP��
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

	closesocket(s);				/*�ر�socket����*/
	Sleep(10000);
	ExitThread(0);
	WSACleanup(); 
}