#include <WINDOWS.H>
#include <stdio.h>
#include "time.h"
#include <string>
using namespace std;

#include "log.h"

DWORD WINAPI ModuleEcho(LPVOID args) {
	DWORD ret = 0;

	// 
	// 
	// 
	WSAData wsaData;
	WORD socketVersion = MAKEWORD(2, 2);
	printf("%s Loading Socket Library, Version %i\n", logdate(), socketVersion);
	/*
	int iStartUp = WSAStartup(socketVersion, &wsaData);
	if (iStartUp != 0) {
		printf("%s Load Socket Library, Version %i                        [ERROR]\n", logdate(), socketVersion);
		return ret;
	}
	*/
	char* logDate = logdate();
	printf("%s Loaded Socket Library, Version %i                          [OK]\n", logDate, socketVersion);

	//
	SOCKET iSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (iSocket == INVALID_SOCKET) {
		logdebug("Create Socket                                          [ERROR]\n");
		return ret;
	}
	logdebug("Create Socket                                              [OK]\n");

	int port = 24;
	//
	sockaddr_in socketaddress;
	socketaddress.sin_family = AF_INET;
	socketaddress.sin_addr.S_un.S_addr = INADDR_ANY;
	socketaddress.sin_port = htons(port);

	int iBind = bind(iSocket, (LPSOCKADDR)&socketaddress, sizeof(socketaddress));
	if (iBind == SOCKET_ERROR) {
		logdebug("Bind Socket on Socket Address                          [ERROR]\n");
		return ret;
	}
	logdebug("Bind Socket on Socket Address                              [OK]\n");

	int iListen = listen(iSocket, 5);
	if (iListen == SOCKET_ERROR) {
		printf("Listen...                                              [ERROR]\n");
		printf("Closing Socket...                                      \n");
		closesocket(iSocket);
		printf("Closed Socket...                                       [OK]\n");
		return ret;
	}
	//logdebug("Listen...                                                  [OK]\n");
	string debug = "Echo server listen on 127.0.0.1:";
	char c[2];
	sprintf(c, "%d", port);
	debug = debug + c;
	debug = debug + "(default 24)...                      [OK]\n";
	logdebug(debug.c_str());

	/*
	 *循环接受连接请求
	 */
	// The socket represents the client socket that received from client connect request.
	SOCKET iClientSocket;

	// The socket address in of the client socket that received from client connect request.
	// Refer header file WINSOCK2.H for the struct sockaddr_in details.
	sockaddr_in clientsocketaddress;

	// micro SOCKADDR_IN defined as struct sockaddr_in, refer header 
	// file WINSOCK2.H for details
	int nAddrLen = sizeof(SOCKADDR_IN);

	char revData[255];
	loginfo("Accepting Client Sockets Connection...                      [OK]\n");

	// echo
	while(1) {
		iClientSocket = accept(iSocket, (SOCKADDR *) &clientsocketaddress, &nAddrLen);
		if (iClientSocket == INVALID_SOCKET) {
			printf("Accept Client Socket Connection...                 [ERROR]\n");
			continue;
		}
		printf("Accepted Socket Connection From %s\n", inet_ntoa(clientsocketaddress.sin_addr));

		while(true) {
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
		}
	}
	closesocket(iSocket);
	WSACleanup();

	return ret;

}