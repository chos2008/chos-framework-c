/*
 *
 * @author ada
 * @version 1.0
 * @since 1.0
 */

#include <log.h>
#include "SocketInputStream.hpp"
#include "LightSocket.h"

/**
 *
 *
 *
 */
SocketInputStream::SocketInputStream()
{
	this->socket = NULL;
}

SocketInputStream::SocketInputStream(Socket *socket) 
{
	this->socket = socket;
}

SocketInputStream::~SocketInputStream()
{
	debug("~SocketInputStream");
}

void SocketInputStream::setSocket(Socket *socket)
{
	this->socket = socket;
}

int SocketInputStream::read(char * bf, int offset, int length) 
	throw (SocketException)
{
	///*
	SOCKET socket = this->socket->getPlainSocket();
	
	int i = recv(socket, bf, length, 0);
	if (i == 0) 
	{
		warn("Connection from %s:%d has been gracefully closed", 
			this->socket->getInetAddressAsString(), 
			this->socket->getPort());
		throw SocketException(Socket::CLOSED);
	}

	if (i == SOCKET_ERROR) 
	{
		int error = WSAGetLastError();
		if (this->socket->getNonBlocking() && error == WSAEWOULDBLOCK) 
		{
			i = 0;
		}
		else 
		{
			throw SocketException(error);
		}
	}
	return i;
	//*/
	//throw SocketException(Socket::CLOSED);
}