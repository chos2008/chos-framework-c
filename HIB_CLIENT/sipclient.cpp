#include <Winsock2.h>
#pragma comment(lib,"ws2_32")
#include <stdio.h>
#include "sp.h"
#include "sp_socket.h"
#define PORT 1129
#define ADDRESS "127.0.0.1"

int main(int argc, char* args[]) {
	char* e = args[0];
	printf("Microsoft Windows XP [版本 5.1.2600]\n");
	printf("(C) 版权所有 1985-2001 Microsoft Corp.\n");
	printf("\n%s\n", args[0]);

	int i = 0, length = 0;
	while (e[i] != '\0') {
		length++;
		i++;
	}
	length++;
	for (i = length - 1; i >= 0; i--) {
		char c = e[i];
		e[i] = '\0';
		if (c == '\\') {
			break;
		}
	}
	printf("%s\n\n", e);


	//加载winsock库
	WSADATA wsaData;
	WORD sockVersion = MAKEWORD(2,2);
	if (WSAStartup(sockVersion,&wsaData) != 0)
		return 0;

	//创建套接字
	SOCKET sClient;
	// SOCKET sClient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	sp_socket spsocket = __sp_socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	sClient = spsocket.socket;
	if (sClient == INVALID_SOCKET) {
		printf("socket error\n");
		return 0;
	}

	//socket中装入远程地址信息
	SOCKADDR_IN remote;
	remote.sin_family = AF_INET;
	remote.sin_port = htons(82);
	remote.sin_addr.S_un.S_addr = inet_addr(ADDRESS);

	if (connect(sClient, (SOCKADDR *) &remote, sizeof(SOCKADDR)) == SOCKET_ERROR) {
		printf("connect error\n");
		closesocket(sClient);
		return 0;
	}

	// echo
	while(true) {
		printf("%s>", e);
		/*
		char SendData[255];
		int i,ch;
		for ( i = 0; (i < 254) && ((ch = getchar()) != EOF) && (ch != '\n'); i++)
			SendData[i] = (char)ch;
		SendData[i] = '\n';
		SendData[i+1] = '\0';
  
  
		send(sClient,SendData,i+2,0);
		*/

		/*
		FILE *lp_f;
		lp_f = fopen("D:\\home\\admin\\index.txt", "r+");
		if (lp_f == NULL) {
			printf("Open File \".\"                         [ERROR]\n");
			return 0;
		}
		printf("%s, %s, %s\n", lp_f->_base, lp_f->_ptr, lp_f->_tmpfname);

		lp_f = fopen(".\\", "r+");
		if (lp_f == NULL) {
			printf("Open File \".\"                         [ERROR]\n");
			return 0;
		}
		printf("%s, %s, %s\n", lp_f->_base, lp_f->_ptr, lp_f->_tmpfname);
		*/

		//////////////////////////////////
		lp_sp_hdr_domain hdr_domain = (sp_hdr_domain*) malloc(sizeof(sp_hdr_domain));

		lp_sp_hdr_domain_item field = (sp_hdr_domain_item*) malloc(sizeof(sp_hdr_domain_item));
		field->field_name = "Content-Type";
		field->field_value = "text/html";

		hdr_domain->first = field;

		lp_sp_hdr_domain hdr_domain_next = (sp_hdr_domain*) malloc(sizeof(sp_hdr_domain));

		lp_sp_hdr_domain_item next = (sp_hdr_domain_item*) malloc(sizeof(sp_hdr_domain_item));
		next->field_name = "Connection";
		next->field_value = "true";

		hdr_domain_next->first = next;
		hdr_domain_next->next = NULL;
		hdr_domain->next = hdr_domain_next;


		lp_sp sp_packet = (sp*) malloc(sizeof(sp));
		sp_packet->pdu = 'a';
		sp_packet->hdr_domain = hdr_domain;
		int so = sizeof(sp_packet);
		int so_sp = sizeof(sp);
		char* sendData = (char*) malloc(2 + 2);//(char*) malloc(sizeof(sp_packet) + 2);
		sendData[2] = '\n';
		sendData[3] = '\0';
		memcpy(sendData, &sp_packet->pdu, 2);
		/*
		char* name = sp_packet->hdr_domain->first->field_name;
		int length = 0;
		char* f = name;
		while (*name != '\0') {
			char c = *name;
			length++;
			name++;
		}
		name = f;
		memcpy(sendData + 2, name, length);
		*/
		send(sClient, sendData, 4, 0);
		//////////////////////////////////
		printf("%s>", e);
	}

	closesocket(sClient);
	WSACleanup();
	return 0;
}