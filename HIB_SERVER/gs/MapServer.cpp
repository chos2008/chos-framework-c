/* Zoom server 
 *
 * Maintains all game server
 *
 * Socket编程有阻塞和非阻塞两种，在操作系统I/O实现时又有几种模型，
 * 包括Select，WSAAsyncSelect，WSAEventSelect ，IO重叠模型，完成端口等。
 * 
 * @author a.da
 * @since 1.0
 */
#include <stdio.h>
#include <string.h>
#include <WINSOCK2.H>
#include "../stdafx.h"
#include "../CModule.h"
#include "../WinAPIThreadModule.hpp"
#include "../net/sp.h"

#pragma comment(lib,"ws2_32")

/**
 * If param m is zero return major version, otherwise, minor 
 * version returned.
 */
char wsa_vs_req(WORD version, int m)
{
	char c = m ? version >> 8 : version & 0xFF;
	return c;
}

SOCKET startZoomServer()
{
	WSAData wsaData;
	WORD socketVersion = MAKEWORD(2, 2);
	printf("Loading Socket Library, Version %i\n", socketVersion);
	// initiates use of the Winsock DLL by a process
	int iStartUp = WSAStartup(socketVersion, &wsaData);
	// If successful, the WSAStartup function returns zero. Otherwise, 
	// it returns one error code
	if (iStartUp != 0) 
	{	
		// The error code function WSAStartup returned
		// 10091 WSASYSNOTREADY
		// Network subsystem is unavailable.
		// This error is returned by WSAStartup if the Windows Sockets 
		// implementation cannot function at this time because the underlying 
		// system it uses to provide network services is currently unavailable. 
		// Users should check:
		// That the appropriate Windows Sockets DLL file is in the current path.
		// That they are not trying to use more than one Windows Sockets 
		// implementation simultaneously. If there is more than one Winsock DLL 
		// on your system, be sure the first one in the path is appropriate for 
		// the network subsystem currently loaded.
		// The Windows Sockets implementation documentation to be sure all 
		// necessary components are currently installed and configured correctly.
		//
		// 10092 WSAVERNOTSUPPORTED
		// Winsock.dll version out of range.
		// The current Windows Sockets implementation does not support the Windows 
		// Sockets specification version requested by the application. Check that 
		// no old Windows Sockets DLL files are being accessed.
		//
		// 10036 WSAEINPROGRESS
		// Operation now in progress.
		// A blocking operation is currently executing. Windows Sockets only 
		// allows a single blocking operation—per- task or thread—to be 
		// outstanding, and if any other function call is made (whether or not it 
		// references that or any other socket) the function fails with the 
		// WSAEINPROGRESS error.
		//
		// 10067 WSAEPROCLIM
		// Too many processes.
		// A Windows Sockets implementation may have a limit on the number of 
		// applications that can use it simultaneously. WSAStartup may fail with 
		// this error if the limit has been reached.
		// 
		// 10014 WSAEFAULT
		// Bad address.
		// The system detected an invalid pointer address in attempting to use a 
		// pointer argument of a call. This error occurs if an application passes 
		// an invalid pointer value, or if the length of the buffer is too small. 
		// For instance, if the length of an argument, which is a sockaddr 
		// structure, is smaller than the sizeof(sockaddr).
		printf("Load Socket Library, Version %i, Error code: %d                        [ERROR]\n", socketVersion, iStartUp);
		return 0;
	}
	printf("Loaded Socket Library, Version %i(%d,%d)                          [OK]\n", socketVersion, wsa_vs_req(socketVersion, 0), wsa_vs_req(socketVersion, 1));

	//
	SOCKET iSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (iSocket == INVALID_SOCKET) {
		printf("Create Socket                                          [ERROR]\n");
		return 0;
	}
	printf("Create Socket                                              [OK]\n");

	//
	sockaddr_in socketaddress;
	socketaddress.sin_family = AF_INET;
	socketaddress.sin_addr.S_un.S_addr = INADDR_ANY;
	socketaddress.sin_port = htons(1129);

	int iBind = bind(iSocket, (LPSOCKADDR)&socketaddress, sizeof(socketaddress));
	if (iBind == SOCKET_ERROR) {
		printf("Bind Socket on Socket Address                          [ERROR]\n");
		return 0;
	}
	printf("Bind Socket on Socket Address                              [OK]\n");

	int iListen = listen(iSocket, 5);
	if (iListen == SOCKET_ERROR) {
		printf("Listen...                                              [ERROR]\n");
		printf("Closing Socket...                                      \n");
		closesocket(iSocket);
		printf("Closed Socket...                                       [OK]\n");
		return 0;
	}
	printf("Listen...                                                  [OK]\n");
	return iSocket;
}

DWORD WINAPI ZoomServerModule(LPVOID args)
{
	// 
	// 
	// 
	SOCKET iSocket = startZoomServer();

	//循环接受连接请求
	SOCKET iClientSocket;
	sockaddr_in clientsocketaddress;
	int nAddrLen = sizeof(SOCKADDR_IN);
	char revData[255];
	printf("Accepting Client Sockets Connection...                     [OK]\n");

	// echo
	while(1) 
	{
		iClientSocket = accept(iSocket, (SOCKADDR *) &clientsocketaddress, &nAddrLen);
		if (iClientSocket == INVALID_SOCKET) 
		{
			printf("Accept Client Socket Connection...                 [ERROR]\n");
			continue;
		}
		printf("Accepted socket connection from %s\n", inet_ntoa(clientsocketaddress.sin_addr));

		while(true) 
		{
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
		}
	}
	closesocket(iSocket);
	WSACleanup();

}

int main(int argc, char* argv[])
{
	printf("Starting...\n");
	
	//module_start("Thread Zoom Server", ZoomServerModule);

	WinAPIThreadModule *module = NULL;
	module = new WinAPIThreadModule("Thread Zoom Server", ZoomServerModule);
	module->start();
	
	ExitThread(0);
	return 0;
}
