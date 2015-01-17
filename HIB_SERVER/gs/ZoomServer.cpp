/**
 * Zoom server for game server
 * 
 * @author a.da
 * @since 1.0
 * @see 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include <WINSOCK2.H>

#include "../stdafx.h"
#include "log.h"
#include "../net/sp.h"
#include "../resource.h"
#include "../Interactive.h"
#include "../WinAPIThreadModule.hpp"
#include "../ModuleXMPP.h"
#include "../ModuleHTTP.h"
#include "../ModuleTime.h"
#include "../ModuleGameServer.h"
#include "RegistorServer.hpp"
#include "NonBlockRegistorServer.hpp"
#include "Account.h"
#include "../net/Select.hpp"
#include "ZoomServerSelectEventHandler.hpp"

#pragma comment(lib,"ws2_32")

// <AFXMT.H> file only use in windows application.
// #error WINDOWS.H already included.  MFC apps must not #include <windows.h>
//#include <AFXMT.H>

//
// 
#define _WIN32_WINNT 0x0500
#define WINVER 0x0500
#define WIN32_LEAN_AND_MEAN	 // Exclude rarely-used stuff from Windows headers

//#include "net/usb/UsbDeviceList.h"

// 函数GetConsoleWindow声明。
// 动态载入函数GetConsoleWindow之前，需要先声明。
typedef HWND (WINAPI *PROCGETCONSOLEWINDOW)();

PROCGETCONSOLEWINDOW GetConsoleWindow;


DWORD WINAPI threaddefinition(LPVOID args) {
	DWORD ret = 0;

	SYSTEMTIME stime;
	GetSystemTime(&stime);
	printf("%d Thread starting...\n", stime);
	
	time_t t;
	time(&t);
	char* ct = ctime(&t);
	printf("%s Thread starting...\n", ct);

	tm* tt = gmtime(&t);
	char* at = asctime(tt);
	printf("%s Thread starting...\n", at);

	tt = localtime(&t);
	at = asctime(tt);
	printf("%s Thread starting...\n", at);

	char* dt = dateformat();
	printf("%s Thread starting...\n", dt);
	return ret;
}

void thread() {
	DWORD threadID;
	CreateThread(NULL, 0, threaddefinition, (LPVOID) NULL, 0, &threadID);
	printf("%s Thread %d started...\n", logdate(), &threadID);
}

DWORD WINAPI countthreaddefinition(LPVOID args) {
	printf("Thread starting...\n");
	DWORD result = 0;
	while (true) {
		Sleep(1000000);
	}
	return result;
}

void countthread() {
	/*
	int count = 0;
	int fg = 1;
	while (fg) {
		DWORD threadID;
		//void* f = CreateThread(NULL, 0, countthreaddefinition, (LPVOID) NULL, 0, &threadID);
		//if (f == NULL) {
		if (CreateThread(NULL, 0, countthreaddefinition, (LPVOID) NULL, 0, &threadID) == NULL) {
			fg = 0;
			break;
		} else {
			printf("Thread %d started...\n", &threadID);
			count++;
		}
		printf("Create %d threads...\n", &count);
	}
	return;
	*/
	
}

void self() {
	// 
	// 
	// 
	WSAData wsaData;
	WORD socketVersion = MAKEWORD(2, 2);
	printf("%s Loading Socket Library, Version %i\n", logdate(), socketVersion);
	int iStartUp = WSAStartup(socketVersion, &wsaData);
	if (iStartUp != 0) {
		printf("%s Load Socket Library, Version %i                        [ERROR]\n", logdate(), socketVersion);
		return;
	}
	char* logDate = logdate();
	printf("%s Loaded Socket Library, Version %i                          [OK]\n", logDate, socketVersion);

	//
	SOCKET iSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (iSocket == INVALID_SOCKET) {
		logdebug("Create Socket                                          [ERROR]");
		return;
	}
	logdebug("Create Socket                                              [OK]");

	//
	sockaddr_in socketaddress;
	socketaddress.sin_family = AF_INET;
	socketaddress.sin_addr.S_un.S_addr = INADDR_ANY;
	socketaddress.sin_port = htons(83);

	int iBind = bind(iSocket, (LPSOCKADDR)&socketaddress, sizeof(socketaddress));
	if (iBind == SOCKET_ERROR) {
		logdebug("Bind Socket on Socket Address                          [ERROR]");
		return;
	}
	logdebug("Bind Socket on Socket Address                              [OK]");

	int iListen = listen(iSocket, 5);
	if (iListen == SOCKET_ERROR) {
		logerror("Listen...                                              [ERROR]\n");
		logerror("Closing Socket...                                      \n");
		
		closesocket(iSocket);

		logerror("Closed Socket...                                       [OK]\n");
		return;
	}
	logdebug("Listen...                                                  [OK]\n");

	//循环接受连接请求
	SOCKET iClientSocket;
	sockaddr_in clientsocketaddress;
	int nAddrLen = sizeof(SOCKADDR_IN);
	char revData[255];
	loginfo("Accepting Client Sockets Connection...                     [OK]\n");

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
}

bool contains(char* args[], char* arg) 
{
	while (*args) 
	{
		char *s = *args;
		if (strcmp(s, arg) == 0) 
		{
			return true;
		}
		*args++;	
	}
	return false;
}

void loadModule()
{
	WinAPIThreadModule *module = NULL;
	/*
	 * Echo server module
	 */
	//module = new Module("Thread Echo Server", ModuleEcho);
	//module->start();
	
	/*
	 * Xmpp server module
	 */
	//module = new Module("Thread Xmpp Server", ModuleXMPP);
	//module->start();
	
	/*
	 * Http server module
	 */
	//module = new Module("Thread Http Server", ModuleHTTP);
	//module->start();
	
	/*
	 * Sip server module
	 */
	//module = new Module("Thread Sip Server", ModuleSIP);
	//module->start();
	
	/*
	 * Time server module
	 */
	//module = new Module("Thread Time Server", ModuleTime);
	//module->start();
	
	/*
	 * Registor server module
	 */
	//NonBlockRegistorServer *server = new NonBlockRegistorServer();
    //server->start();
	
	//module = new WinAPIThreadModule("Thread Register Server", ModuleRegistorServer);
	//module->start();


	HardSocket socket;
	bool bReuseAddr = true;
	socket.setSocketOption(SOL_SOCKET, SO_REUSEADDR, (char *) &bReuseAddr, sizeof(bReuseAddr));
    //unsigned   long cmd = 1;
    //iResult= ioctlsocket(sockServer,FIONBIO,&cmd);
	socket.bind(6002);
	socket.listen(5);

	Select select(socket);
	SelectEventHandler* eventHandler = new ZoomServerSelectEventHandler();
	select.registerSelectEventHandler(*eventHandler);

	

    info("Start server...");
	while(1)
	{
        select.select();
    }  
    WSACleanup();
}

char * path(char* e)
{
	printf("Microsoft Windows XP [版本 5.1.2600]\n");
	printf("(C) 版权所有 1985-2001 Microsoft Corp.\n");

	printf("\n");
	info("%s\n", e);

	int length1 = strlen(e);
	//int length0 = sizeof(e) / sizeof(char);
	//
	/*
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
	*/
	for (int i = length1; i >= 0; i--)
	{
		char c = e[i];
		e[i] = '\0';
		if (c == '\\') 
		{
			break;
		}
	}
	info("HOME: %s\n\n", e);

	info("Starting...\n");

	return e;
}

int main(int argc, char* argv[])
{
	
	char* root = path(argv[0]);

	// 动态载入函数GetConsoleWindow
	//HMODULE hKernel32 = GetModuleHandle("kernel32");
	//GetConsoleWindow = (PROCGETCONSOLEWINDOW) 
	//	GetProcAddress(hKernel32, "GetConsoleWindow");

	//HINSTANCE hInstance = GetModuleHandle(NULL);
	//HWND hwnd = GetConsoleWindow();
	//HICON hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON2));
	//SendMessage(hwnd, 
	//	WM_SETICON, 
	//	ICON_SMALL, 
	//	(LPARAM) hIcon);


	// 向QQ进程发送消息，关闭QQ进程。
	//HWND hWnd = ::FindWindow(NULL, "QQ2013");
	//if(hWnd != NULL)
	//{
	//	::SendMessage(hWnd, WM_CLOSE, 0, 0);
	//}
	
	//
	//
	//getUsbDeviceList();

	//
	//
	//Parameters for function CreateProcess call
	//LPSECURITY_ATTRIBUTES processA=NULL;//Default
	//LPSECURITY_ATTRIBUTES threadA=NULL;//Default
	//BOOL shareRights=TRUE;//Default
	//DWORD creationMask=CREATE_NEW_CONSOLE;//Window per process.
	//LPVOID enviroment=NULL;//Default
	//LPSTR curDir=NULL;//Default
	//STARTUPINFO startInfo;//Result
	//PROCESS_INFORMATION procInfo;//Result
	//char p[] = {'C', 'A', 'L', 'C', '.', 'E', 'X', 'E'};
	//i = CreateProcess(
	//	NULL,//File name of executable
	//	p,//command line
	//	processA,//Process inherited security
	//	threadA, //Thread inherited security
	//	shareRights,//Rights propagation
	//	creationMask,//various creation flags
	//	enviroment,//Enviroment variable
	//	curDir,           //Child's current directory
	//	&startInfo,
	//	&procInfo);
	//if (i == 0) {
	//	fprintf(stderr,"CreatProcess failed on error %d\n",GetLastError());
	//	ExitProcess(0);
	//}

	if (contains(argv, "-server-mode")) 
	{
		loginfo("Server run in a server mode");
		////thread();
		loadModule();
		////countthread();
		//self();
		ExitThread(0);
	}
	else if (contains(argv, "-interactive-mode"))
	{
		loginfo("Server run in a interactive mode");
		Interactive interactive;
		interactive.run();
	}
	return 0;
}
