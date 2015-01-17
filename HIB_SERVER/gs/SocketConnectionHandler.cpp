/*
 * Class SocketConnectionHandler to handle the client socket 
 * connection @SocketConnection@
 *
 * @see SocketConnection
 * @author  a.da
 * @since  1.0
 */
#include <assert.h>
#include "log.h"
#include "../net/socket/SocketInputStream.hpp"
#include "../net/socket/SocketOutputStream.hpp"
#include "SocketConnectionHandler.h"
#include "../net/socket/SocketConnectionEventHandler.hpp"
#include "BinaryRequest.h"
#include "Account.h"

/**
 *
 *
 *
 */
SocketConnectionHandler::SocketConnectionHandler(MutexLock *mutex, 
	RequestDataBuffer *requestDataBuffer) 
{
	this->mutex = mutex;
	this->requestDataBuffer = requestDataBuffer;
}

void SocketConnectionHandler::registerEventHandler(SocketConnectionEventHandler *eventHandler)
{
	this->eventHandler = eventHandler;
}

void SocketConnectionHandler::process(char *data)
{
	//WaitForSingleObject(&this->m_hMutex, INFINITE);
	this->mutex->lock();
	//this->requestDataBuffer->write(data);

	// Release mutex
	//ReleaseMutex(&this->m_hMutex);
	this->mutex->unlock();
}

void SocketConnectionHandler::readPacket(SocketConnection *connection, BinaryRequest *request) throw (SocketConnectionException)
{
	assert (request != NULL);

	if (connection->isClose()) 
	{
		info("=======connection closed");
		throw SocketConnectionException();
	}

	LightSocket *socket = connection->getSocket();
	SocketInputStream* is = connection->getInputStream();
	SocketOutputStream* os = connection->getOutputStream();

	int size = 8;
	char bf[9];
	char *tp = bf;
	memset(bf, 0, size);

	int i = 0;
	while (1) 
	{
		try 
		{
			i = is->read(tp, 0, size);
		}
		catch (SocketException e) 
		{
			if (e.getCode() == Socket::CLOSED) 
			{
				info("socket connection closed");
				this->eventHandler->onClose(connection);
				return;
			}
			else if (e.getCode() == WSAECONNRESET) 
			{
				info("socket connection reset");
				this->eventHandler->onClose(connection);
				return;
			}
			else 
			{
				warn("read socket data error %d", e.getCode());
				this->eventHandler->onClose(connection);
				return;
			}
		}

		debug("read %dbytes socket data from %s:%d(), read buffer size: %d", 
			i, 
			socket->getInetAddressAsString(), socket->getPort(), 
			size);
		
		if (i < size) 
		{
			tp += i;
			size -= i;
			continue;
		}
		break;
	}
	char *p = bf;
	int version = *p;
	version = version >> 4;
	//version = ntohs((u_short) version);
	info("request version %d", version);

	p++;
	int length = *p;
	//length = ntohs((u_short) length);
	info("request message length %d", length);

	p++;
	unsigned short *ps = (unsigned short *) p;
	unsigned short command = *ps;
	command = ntohs(command);
	info("request message command %d", command);

	p = p + 2;
	unsigned long *pl = (unsigned long *) p;
	unsigned long userId = *pl;
	userId = ntohl(userId);
	info("request message user id %d", userId);

	request->setVersion(version);
	request->setLength(length);
	request->setCommand(command);
	request->setUserId(userId);
}

void SocketConnectionHandler::handle0(SocketConnection * connection)
{
	LightSocket *socket = connection->getSocket();
	SocketInputStream* is = connection->getInputStream();
	SocketOutputStream* os = connection->getOutputStream();
	//*
	int size = 128;
	char *bf = (char *) malloc(size * sizeof(char));
	memset(bf, 0, size);

	int i = 0;
	while (1) 
	{
		try 
		{
			i = is->read(bf, 0, size - 1);
		}
		catch (SocketException e) 
		{
			if (e.getCode() == Socket::CLOSED) 
			{
				info("socket connection closed");
				this->eventHandler->onClose(connection);
				return;
			}
			else if (e.getCode() == WSAECONNRESET) 
			{
				info("socket connection reset");
				this->eventHandler->onClose(connection);
				return;
			}
			else 
			{
				warn("read socket data error %d", e.getCode());
				this->eventHandler->onClose(connection);
				return;
			}
		}

		debug("read %dbytes socket data from %s:%d(), read buffer size: %d", 
			i, 
			socket->getInetAddressAsString(), socket->getPort(), 
			size - 1);
		os->write(bf, 0, 1);
		//printf("%s\n", bf);
		
		this->process(bf);
		memset(bf, 0, size);
	}
	
	free(bf);
	delete socket;
	delete connection;
	//*/
}

/**
 *
 *
 *
 *
 */
void SocketConnectionHandler::handle(SocketConnection *connection) 
{
	while (1)
	{
		BinaryRequest *request = new BinaryRequest();
		try 
		{
			readPacket(connection, request);
		}
		catch(SocketConnectionException e) 
		{
			return;
		}
		int command = request->getCommand();
		int dataLength = request->getLength();
		int userId = request->getUserId();
		if (command == BinaryRequest::REG) 
		{
			info("[REQ] REG(%d)", command);
			char *id = NULL;
			char *password = "222";
			int bytes = fprintf(stderr, "%d", userId);
			id = (char *) malloc(bytes);
			itoa(userId, id, 10);
			info("creating new account...");
			Account account(id, password);
			
			
			account.create();

			
			printf("Account created, id: %s, password: %s\n", account.getId(), account.getPassword());
			//free(id);
		}
		else if(command == BinaryRequest::LOGIN) 
		{
			info("[REQ] LOGIN(%d)", command);
		}
		else 
		{
			warn("Unknown request(%d) from %d", command, request->getUserId());
			continue;
		}

		//handle0(connection);
	}
}
