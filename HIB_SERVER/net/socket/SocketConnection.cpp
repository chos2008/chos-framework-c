/*
 *
 *
 * @author ada
 * @version 1.0
 * @since 1.0
 */
#include <log.h>

#include "SocketConnection.h"
#include "SocketInputStream.hpp"

/**
 *
 *
 *
 *
 *
 *
 */
SocketConnection::SocketConnection(LightSocket * socket) 
{
	this->socket = socket;
}

SocketConnection::~SocketConnection()
{
	debug("~SocketConnection");
}

/**
 *
 *
 *
 *
 *
 *
 */
LightSocket* SocketConnection::getSocket() 
{
	return this->socket;
}

SocketInputStream* SocketConnection::getInputStream() 
{
	return this->socket->getInputStream();
}

SocketOutputStream* SocketConnection::getOutputStream()
{
	return this->socket->getOutputStream();
}

void SocketConnection::close()
{
	this->socket->close();
	delete this->socket;
	this->socket = NULL;
}

int SocketConnection::isClose()
{
	if (! this->socket) 
	{
		return 1;
	}
	return this->socket->isClose();
}