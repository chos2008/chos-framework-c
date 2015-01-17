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
#include "NonBlockRegistorServer.hpp"
#include "../MutexLock.hpp"

HardSocket* NonBlockRegistorServer::startRegistorServer() throw(SocketException) 
{
	HardSocket *socket = new HardSocket();
	socket->setNonBlocking();
	int port = 1111;
	socket->bind(port);

	try 
	{
		socket->listen(5);
	}
	catch(SocketException e) 
	{
		error("Listen error %d", e.getCode());
		socket->close();
		throw SocketException();
	}

	/*
	string debug = "Registor server listen on 127.0.0.1:";
	//char c[2];
	//sprintf(c, "%d", port);
	char *s = (char *) malloc(sizeof(int));
	s = itoa(port, s, 10);
	//debug += "1111";
	debug.append(s);
	debug += "(default xxxx)...                      [OK]\n";
	logdebug(debug.c_str());
	*/
	//inet_ntoa(clientsocketaddress.sin_addr);
	
	info("Registor server listen on %s:%d(default 127.0.0.1:xxxx)", socket->getInetAddressAsString(), port);
	return socket;
}

void NonBlockRegistorServer::startService()
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
	HANDLE m_hMutex = CreateMutex(NULL, FALSE, "DataBufferQueueInstancez#1");

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
	loginfo("Accepting client socket connection...                      [OK]");
	try {
	while(1) 
	{
		// accept client connection
		
		LightSocket* socket = s->accept();
		if (socket != NULL) 
		{
			SocketConnection *connection = 
				createConnectionForClient(socket);

			logdebug("handing new connection...");
			// handle the client connection
			handler->handle(connection);
		}
	}
	}
	catch(SocketException e) 
	{
		warn("Accept error %d", e.getCode());
		exit(1);
	}
	s->close();
	
	WSACleanup();
}


SocketConnection * NonBlockRegistorServer::createConnectionForClient(LightSocket* socket)
{
	sockaddr_in clientsocketaddress = socket->getSocketAddress();

	/*
	char* addr = inet_ntoa(clientsocketaddress.sin_addr);
	
	char* c = (char *) malloc(sizeof(clientsocketaddress.sin_port));
	itoa(clientsocketaddress.sin_port, c, 10);
	
	string log = "Accepted Socket Connection From ";
	log = log + addr;
	log = log + ":";
	log = log + c;
	log = log + "\n";
	loginfo(log.c_str());
	*/
	info("Accepted Socket Connection From %s:%d", inet_ntoa(clientsocketaddress.sin_addr), clientsocketaddress.sin_port);

	return new SocketConnection(socket);
}

void NonBlockRegistorServer::start() 
{
    startService();
}
