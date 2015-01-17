/*
 *
 *
 *
 *
 */

#include <winsock2.h>
#include <WINDOWS.H>
#pragma comment(lib, "ws2_32")

#include "log.h"
#include "XMPPIMAccount.h"
#include "XMPPHandler.hpp"

XMPPHandler::XMPPHandler() 
{
	
}


	
/**
 *
 *
 *
 */
void XMPPHandler::handle(LightSocket *socket) {

	SOCKET iClientSocket = socket->getPlainSocket();
	sockaddr_in clientsocketaddress = socket->getSocketAddress();
	int i = 0;
	while(true) {
		char flag = 'a';
		char revData[255];
		int ret = recv(iClientSocket, revData, 255, 0);
		printf("Received Client Socket Inputstream Data...         [OK]\n");

		if (ret == 0 || (ret == SOCKET_ERROR && WSAGetLastError() == WSAECONNRESET)) {
			printf("Closed Connection From %s\n", inet_ntoa(clientsocketaddress.sin_addr));
			closesocket(iClientSocket);
			break;
		} else {
			revData[ret] = '\0';
			printf("Received Client Socket Data...\n");
			printf("%s\n", revData);
		}
		char* requestLine = (char*) malloc(sizeof(revData));
		int i = 0;
		char* rf = requestLine;
		while (revData[i] != '\r' && revData[i + 1] != '\n') {
			*requestLine = revData[i];
			i++;
			requestLine++;
		}
		requestLine = rf;
			
		printf("Request Line: %s", requestLine);
		if (flag == 'a') {
			logdebug("Register new account...\n");
			XMPPIMAccount imAccount("luoixaaa", "jxcoco1128");
			imAccount.create();
		}
	}
}
