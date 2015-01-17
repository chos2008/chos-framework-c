#include <WINDOWS.H>
#include <stdio.h>
#include "time.h"
#include <string>
using namespace std;

#include "log.h"
#include "sp.h"
#include "sp_socket.h"

#define PORT 1111
#define ADDRESS "127.0.0.1"


void read(SOCKET& socket)
{
	int size = 2048;
	char *bf = (char *) malloc(size * sizeof(char));
	memset(bf, 0, size);

	int i = 0;
	while (i = recv(socket, bf, size - 1, 0)) 
	{
		if (i == SOCKET_ERROR) 
		{
			int error = WSAGetLastError();
			warn("socket read error %d", error);
			closesocket(socket);
			break;
		}
		if (i == 0) 
		{
			warn("The connection from %s:%d has been gracefully closed");
			closesocket(socket);
			break;
		}

		logdebug("Read socket inputstream data...                 [OK]\n");
		printf("%s\n", bf);
		
		//this->process(bf);
		memset(bf, 0, size);
	}
}

DWORD WINAPI read_callback(LPVOID args)
{
	SOCKET sClient = (SOCKET) args;
	read(sClient);
	return 0;
}

void registor(SOCKET sClient, unsigned long id, const char *password) 
{
	char packet[8];
	memset(packet, 0, sizeof(packet));
	char version = 1;
	version = version << 4;
	packet[0] = version;

	char length = 0;
	packet[1] = length;

	char *p = packet;
	unsigned short command = 45;
	command = htons(command);
	p = p + 2;
	memcpy(p, &command, sizeof(command));

	p = p + 2;
	unsigned long userId = id;
	userId = htonl(userId);
	memcpy(p, &userId, sizeof(unsigned long));

	send(sClient, packet, sizeof(packet), 0);
}

void login(SOCKET sClient, unsigned long id, const char *password) 
{
	const int dataLength = 0;//strlen(password);
	char *packet = new char[8 + dataLength];
	memset(packet, 0, 8 + dataLength);
	char version = 1;
	version = version << 4;
	packet[0] = version;

	char length = dataLength;
	packet[1] = length;

	char *p = packet;
	unsigned short command = 46;
	command = htons(command);
	p = p + 2;
	memcpy(p, &command, sizeof(command));

	p = p + 2;
	unsigned long userId = id;
	userId = htonl(userId);
	memcpy(p, &userId, sizeof(unsigned long));

	//p = p + 4;
	//memcpy(p, password, dataLength);

	send(sClient, packet, 8 + dataLength, 0);
}

DWORD WINAPI CModuleGameClient(LPVOID args) {
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
	//free(a);
	//delete a;
	//printf("%s Loading Socket Library, Version %i\n", logdate(), sockVersion);

	if (WSAStartup(sockVersion,&wsaData) != 0)
		return ret;

	log = "";
	log = log + "Loaded Socket Library, Version ";
	a = (char*) malloc(2 * sizeof(char));
	itoa(sockVersion, a, 10);
	log = log + a;
	log = log + "                          [OK]\n";
	logdebug(log.c_str());
	//free(a);
	//delete a;
	//char* logDate = logdate();
	//printf("%s Loaded Socket Library, Version %i                          [OK]\n", logDate, sockVersion);

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
	a = (char*) malloc(2 * sizeof(char));
	itoa(PORT, a, 10);
	log = log + a;
	log = log + "...\n";
	logdebug(log.c_str());
	//free(a);
	if (connect(sClient, (SOCKADDR *) &remote, sizeof(SOCKADDR)) == SOCKET_ERROR) 
	{
		logerror("Connecting fail           [ERROR]\n");
		closesocket(sClient);
		return ret;
	}
	info("connected %s:%d", ADDRESS, PORT);

	/*
	char *packet = "req: reg\r\nuser-name:lxy\r\npassword:jxcoco1128\r\n\r\n";
	//send(sClient,packet,strlen(packet),0);
	//read(sClient);
	
	packet = "GET / HTTP/1.1\r\nHost: localhost:81\r\nConnection: keep-alive\r\nCache-Control: max-age=0\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,*\/*;q=0.8\r\nUser-Agent: Mozilla/5.0 (Windows NT 5.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/27.0.1453.110 Safari/537.36\r\nAccept-Encoding: gzip,deflate,sdch\r\nAccept-Language: zh-CN,zh;q=0.8\r\n\r\n";
	//send(sClient,packet,strlen(packet),0);
	//read(sClient);

	packet = "HEAD / HTTP/1.1\r\nHost: localhost:81\r\nConnection: keep-alive\r\nCache-Control: max-age=0\r\nAccept: text/html,application/xhtml+xml,application/xml;q=0.9,*\/*;q=0.8\r\nUser-Agent: Mozilla/5.0 (Windows NT 5.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/27.0.1453.110 Safari/537.36\r\nAccept-Encoding: gzip,deflate,sdch\r\nAccept-Language: zh-CN,zh;q=0.8\r\n\r\n";
	//send(sClient,packet,strlen(packet),0);
	//read(sClient);

	packet = "DELETE / HTTP/1.1\r\n\r\n";
	//send(sClient,packet,strlen(packet),0);
	//read(sClient);

	packet = "OPTIONS * HTTP/1.1\r\n\r\n";
	//send(sClient,packet,strlen(packet),0);
	//read(sClient);

	packet = "OPTIONS / HTTP/1.1\r\n\r\n";
	//send(sClient,packet,strlen(packet),0);
	//read(sClient);

	packet = "OPTIONS / HTTP/1.1\r\nContent-Length: 12\r\nContent-Type: text/html; charset=iso-8859-1\r\n\r\naaa=12&bbb=1";
	//send(sClient,packet,strlen(packet),0);
	//read(sClient);

	packet = "req: login\r\nuser-name:lxy\r\npassword:jxcoco1128\r\n\r\n";
	send(sClient,packet,strlen(packet),0);

	packet = "req: user-data\r\nuser-id: 1234\r\n\r\n";	
	send(sClient,packet,strlen(packet),0);

	packet = "req: map-list-data\r\nuser-id: 1234\r\n\r\n";
	send(sClient,packet,strlen(packet),0);

	packet = "req: map-data\r\nuser-id: 1234\r\nmap-id: 0\r\n\r\n";
	send(sClient,packet,strlen(packet),0);

	packet = "req: map-data\r\nuser-id: 1234\r\nmap-id: 1\r\n\r\n";
	send(sClient,packet,strlen(packet),0);

	packet = "req: map-data\r\nuser-id: 1234\r\nmap-id: 2\r\n\r\n";
	send(sClient,packet,strlen(packet),0);

	packet = "req: map-data\r\nuser-id: 1234\r\nmap-id: 3\r\n\r\n";
	send(sClient,packet,strlen(packet),0);

	packet = "req: map-data\r\nuser-id: 1234\r\nmap-id: 4\r\n\r\n";
	send(sClient,packet,strlen(packet),0);

	packet = "req: map-data\r\nuser-id: 1234\r\nmap-id: 5\r\n\r\n";
	send(sClient,packet,strlen(packet),0);

	packet = "req: map-data\r\nuser-id: 1234\r\nmap-id: 6\r\n\r\n";
	send(sClient,packet,strlen(packet),0);

	packet = "req: map-data\r\nuser-id: 1234\r\nmap-id: 7\r\n\r\n";
	send(sClient,packet,strlen(packet),0);

	packet = "req: map-data\r\nuser-id: 1234\r\nmap-id: 8\r\n\r\n";
	send(sClient,packet,strlen(packet),0);
	
	packet = "req: map-data\r\nuser-id: 1234\r\nmap-id: 9\r\n\r\n";
	send(sClient,packet,strlen(packet),0);

	packet = "req: login\r\nuser-name:abcdef\r\npassword:jxcoco1128\r\n\r\n";
	send(sClient, packet, strlen(packet), 0);
	*/

	DWORD td;
	//CreateThread(NULL, 0, read_callback, (void *) sClient, 0, &td);
	unsigned long id = 1;
	while (1) 
	{
		registor(sClient, id, "jxcoco1128");
		login(sClient, id, "jxcoco1128");
		id++;
		//break;
	}

	closesocket(sClient);
	WSACleanup();

	return ret;

}