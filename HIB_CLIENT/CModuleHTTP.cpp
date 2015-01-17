#include <WINDOWS.H>
#include <stdio.h>
#include "time.h"
#include <string>
using namespace std;

#include "log.h"
#include "sp.h"
#include "sp_socket.h"

#define PORT 1192
#define ADDRESS "127.0.0.1"

DWORD WINAPI CModuleHTTP(LPVOID args) {
	DWORD threadID = GetCurrentThreadId();
	char* a = (char*) malloc(4 * sizeof(char));
	itoa(threadID, a, 10);
	string log = "";
	log = log + "Thread #";
	log = log + a;
	log = log + " running...\n";
	logdebug(log.c_str());

	char* e = (char*) args;
	DWORD ret = 0;

	//加载winsock库
	WSADATA wsaData;
	WORD sockVersion = MAKEWORD(2,2);

	log = "";
	log = log + "Loading Socket Library, Version ";
	a = (char*) malloc(2 * sizeof(char));
	itoa(sockVersion, a, 10);
	log = log + a;
	log = log + "...\n";
	logdebug(log.c_str());
	printf("%s Loading Socket Library, Version %i\n", logdate(), sockVersion);

	if (WSAStartup(sockVersion,&wsaData) != 0)
		return ret;

	log = "";
	log = log + "Loaded Socket Library, Version ";
	a = (char*) malloc(2 * sizeof(char));
	itoa(sockVersion, a, 10);
	log = log + a;
	log = log + "                          [OK]\n";
	logdebug(log.c_str());
	char* logDate = logdate();
	printf("%s Loaded Socket Library, Version %i                          [OK]\n", logDate, sockVersion);

	//创建套接字
	SOCKET sClient;
	// SOCKET sClient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	sp_socket spsocket = __sp_socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	sClient = spsocket.socket;
	if (sClient == INVALID_SOCKET) {
		logdebug("Socket error...\n");
		return ret;
	}

	//socket中装入远程地址信息
	SOCKADDR_IN remote;
	remote.sin_family = AF_INET;
	remote.sin_port = htons(PORT);
	remote.sin_addr.S_un.S_addr = inet_addr(ADDRESS);

	log = "";
	log = log + "Connecting ";
	log = log + ADDRESS;
	log = log + ":";
	a = (char *) malloc(2 * sizeof(char));
	itoa(PORT, a, 10);
	log = log + a;
	log = log + "...\n";
	logdebug(log.c_str());
	if (connect(sClient, (SOCKADDR *) &remote, sizeof(SOCKADDR)) == SOCKET_ERROR) {
		logerror("Connecting fail...         [ERROR]\n");
		closesocket(sClient);
		return ret;
	}

	// echo
	while(true) {
		printf("%s>", e);
		char SendData[255];
		int i,ch;
		for ( i = 0; (i < 254) && ((ch = getchar()) != EOF) && (ch != '\n'); i++)
			SendData[i] = (char)ch;
		SendData[i] = '\n';
		SendData[i+1] = '\0';
  
  
		send(sClient,SendData,i+2,0);

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
		hdr_domain->next = hdr_domain_next;


		lp_sp sp_packet = (sp*) malloc(sizeof(sp));
		sp_packet->pdu = 0;
		sp_packet->hdr_domain = hdr_domain;
		//send(sClient,sp_packet,i+2,0);
		//////////////////////////////////
		printf("%s>", e);
	}

	closesocket(sClient);
	WSACleanup();

	return ret;

}