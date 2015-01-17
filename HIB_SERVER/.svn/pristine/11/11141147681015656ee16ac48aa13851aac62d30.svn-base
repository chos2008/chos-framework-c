/*
 *
 * @author ada
 * @version 1.0
 * @since 1.0
 */

#include <windows.h>
#include <stdio.h>
#include "time.h"
#include <signal.H>


#include "log.h"
#include "MutexLock.hpp"
#include "HttpServer.h"

#include "Thread.hpp"

class Worker : public Thread 
{
private:

	MutexLock *mutex;
	
	HttpHandler *handler;

	HttpConnection * connection;

public:
	Worker() 
	{

	}

	Worker(HttpConnection * connection) 
	{
		// Create a mutex for synchronization
		this->mutex = new MutexLock();
		
		handler = new HttpHandler(mutex);
		this->connection = connection;
	}

	void run() 
	{
		handler->handle(connection);
	}
};

/**
 * Start http server and listen on the specific port
 * 
 * The handle of socket created returned. 
 *
 * @return 
 *
 *
 */
HardSocket* HttpServer::startHttpServer() throw (SocketException)
{
	HardSocket *s = NULL;
	try 
	{
		s = new HardSocket();
	}
	catch(SocketException e) 
	{
		throw e;
	}

	try 
	{
		int port = 81;
		s->bind(port);

		s->listen(5);
		/*
		string debug = "Http server listen on 127.0.0.1:";
		char c[2];
		sprintf(c, "%d", port);
		debug += "81";
		debug += "(default 80)...                      [OK]";
		loginfo(debug.c_str());
		*/
		info("Http server listen on %s:%d(default 127.0.0.1:80)", s->getInetAddressAsString(), s->getPort());
		return s;
	}
	catch(SocketException e) 
	{
		s->close();
		printf("Socket closed...                                       [OK]\n");
		throw e;
	}
}

void HttpServer::start() 
{
	HardSocket *s = NULL;
	try 
	{
		s = startHttpServer();
	}
	catch(SocketException e) 
	{
		error("Fail to start http server(error %d)", e.getCode());
		return;
	}
	loginfo("Accepting client socket connection\n");

	
	while(1) 
	{
		LightSocket *socket = s->accept();
		info("Accepted socket connection from %s:%d", socket->getInetAddressAsString(), socket->getPort());

		Worker *worker = new Worker(new HttpConnection(socket));
		worker->start();
	}
	s->close();
	WSACleanup();
}