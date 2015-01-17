/*
 * Registor server
 *
 *
 *
 * 
 * @author ada
 * @version 1.0
 * @since 1.0
 */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <WINDOWS.H>
#include <SIGNAL.H>


#include "log.h"
#include "../net/socket/HardSocket.h"
#include "../net/socket/SocketConnection.h"
#include "RequestDataBuffer.h"
#include "SocketConnectionHandler.h"
#include "RequestProcessor.h"
#include "RegistorServer.hpp"
#include "../MutexLock.hpp"

HardSocket* RegistorServer::startRegistorServer() throw(SocketException) 
{
	HardSocket *socket = new HardSocket();

	int port = 1111;
	socket->bind(port);
	SOCKET iSocket = socket->getPlainSocket();

	int iListen = listen(iSocket, 5);
	if (iListen == SOCKET_ERROR) {
		printf("Listen...                                              [ERROR]\n");
		printf("Closing Socket...                                      \n");
		closesocket(iSocket);
		printf("Closed Socket...                                       [OK]\n");
		throw SocketException();
	}
	string debug = "Registor server listen on 127.0.0.1:";
	//char c[2];
	//sprintf(c, "%d", port);
	char *s = (char *) malloc(sizeof(int));
	s = itoa(port, s, 10);
	//debug += "1111";
	debug.append(s);
	debug += "(default xxxx)...                      [OK]\n";
	logdebug(debug.c_str());
	return socket;
}

void RegistorServer::startService()
{
	HardSocket *s = NULL;
	try 
	{
		s = startRegistorServer();
	}
	catch(SocketException e) 
	{
		error("Fail to start registor server, error %d", e.getCode());
		return;
	}
	
	// Create a mutex for synchronization
	MutexLock *mutex = new MutexLock();
	//HANDLE m_hMutex = CreateMutex(NULL, FALSE, "DataBufferQueueInstancez#0");
	
	RequestDataBuffer *requestDataBuffer = new RequestDataBuffer();
	
	GRequestListener *dataBufferListener 
		= new GRequestListener(mutex);
	requestDataBuffer->registerListener(dataBufferListener);

	dataBufferListener->start();
	
	// create socket connection handler 
	SocketConnectionHandler * handler = 
		new SocketConnectionHandler(mutex, requestDataBuffer);

	//
	//
	loginfo("Accepting client socket connection...                      [OK]\n");
	while(1) 
	{
		// accept client connection
		
		LightSocket* socket = s->accept();
		SocketConnection *connection = 
			createConnectionForClient(socket);

		// handle the client connection
		handler->handle(connection);
		
	 }
	s->close();
	WSACleanup();
}


SocketConnection * RegistorServer::createConnectionForClient(LightSocket* socket)
{
    sockaddr_in clientsocketaddress = socket->getSocketAddress();

	/*
	string log = "Accepted Socket Connection From ";
	log = log + inet_ntoa(clientsocketaddress.sin_addr);
	log = log + ":";
	char* c = (char *) malloc(sizeof(clientsocketaddress.sin_port));
	itoa(clientsocketaddress.sin_port, c, 10);
	log = log + c;
	log = log + "\n";
	loginfo(log.c_str());
	*/
	info("Accepted Socket Connection From %s:%d", socket->getInetAddressAsString(), clientsocketaddress.sin_port);

	return new SocketConnection(socket);
}

void RegistorServer::start() 
{
    startService();
}


/**
 *
 *
 *
 *
 *
 *
 *
 */
DWORD WINAPI ModuleRegistorServer(LPVOID args) {
	//signal(SIGINT, interruptHandler);

	DWORD ret = 0;


	

	return ret;

}