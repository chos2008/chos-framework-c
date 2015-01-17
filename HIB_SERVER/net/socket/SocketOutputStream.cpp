/*
 *
 *
 */
#include "SocketException.hpp"
#include "SocketOutputStream.hpp"
#include "LightSocket.h"

SocketOutputStream::SocketOutputStream()
{
	this->socket = NULL;
}

SocketOutputStream::SocketOutputStream(Socket *socket) 
{
	this->socket = socket;
}

void SocketOutputStream::setSocket(Socket *socket)
{
	this->socket = socket;
}

int SocketOutputStream::write(const char* s, int offset, int length) throw (SocketException)
{
	s = s + offset;
	SOCKET socket = this->socket->getPlainSocket();
	int bytes = send(socket, s, length, 0);
	if (bytes == SOCKET_ERROR) 
	{
		int error = WSAGetLastError();
		throw SocketException(error);
	}
	return bytes;
}
