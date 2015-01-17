#include <WINDOWS.H>
#include <stdio.h>
#include "time.h"
#include <string>
using namespace std;

#include "log.h"
#include "sp.h"
#include "sp_socket.h"
/*
#include "D:\home\admin\workstation\c\dp_d_xml\StartLine.h"
#include "D:\home\admin\workstation\c\dp_d_xml\StartTag.h"
*/
#define PORT 1192
#define ADDRESS "127.0.0.1"

DWORD WINAPI CModuleXMPP(LPVOID args) {
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

	log = "";
	log = log + "Connected ";
	log = log + ADDRESS;
	log = log + ":";
	log = log + a;
	log = log + "...\n";
	logdebug(log.c_str());

	/*
	// Open a stream
	StartLine startLine;
	
	string* lpStream = new string("");
	startLine.toStream(lpStream);
	const char* plStream = (*lpStream).c_str();
	printf("start line stream: %s...\n", plStream);
	send(sClient, plStream, (*lpStream).length(), 0);



	logdebug("Creating start tag with name: stream:stream...\n");
	StartTag startTag2("stream:stream");
	
	string tagName = startTag2.getTagName();
	const char* plTagName = tagName.c_str();
	printf("startTag2 tag name: %s...\n", plTagName);

	string* lpStream2 = new string("");
	startTag2.toStream(lpStream2);
	const char* plStream = (*lpStream2).c_str();
	printf("startTag2 tag stream: %s...\n", plStream);
	

	startTag2.appendAttribute("from", "juliet@im.example.com");
	logdebug("Append attribute 'from'...\n");

	startTag2.appendAttribute("to", "im.example.com");
	logdebug("Append attribute 'to'...\n");
	
	startTag2.appendAttribute("version", "1.0");
	logdebug("Append attribute 'version'...\n");

	startTag2.appendAttribute("xml:lang", "en");
	logdebug("Append attribute 'xml:lang'...\n");

	startTag2.appendAttribute("xmlns", "jabber:client");
	logdebug("Append attribute 'xmlns'...\n");

	startTag2.appendAttribute("xmlns:stream", "http://etherx.jabber.org/streams");
	logdebug("Append attribute 'xmlns:stream'...\n");

	string* lpStream3 = new string("");
	startTag2.toStream(lpStream3);
	plStream = (*lpStream3).c_str();
	printf("startTag2 tag stream: %s...\n", plStream);
	//string ss = "abcd";
	printf("startTag2 tag stream length: %d\n", (*lpStream3).length());

	
	send(sClient, plStream, (*lpStream3).length(), 0);
	*/

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