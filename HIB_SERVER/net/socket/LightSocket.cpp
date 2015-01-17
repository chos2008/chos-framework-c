/*
 *
 *
 * @author ada
 * @version 1.0
 * @since 1.0
 */

#include <WINSOCK2.H>
#pragma comment(lib, "ws2_32")

#include "Socket.h"
#include "LightSocket.h"

/**
 *
 *
 *
 */
LightSocket::LightSocket() 
{

}

LightSocket::LightSocket(SOCKET socket) : Socket(socket)
{

}


LightSocket::LightSocket(string host, int port) 
{

}

LightSocket::LightSocket(string host, int port, int stream) 
{

}

LightSocket::LightSocket(string host, int port, string localAddress, int localPort) 
{

}

LightSocket::~LightSocket()
{
	
}

SOCKET LightSocket::getPlainSocket() 
{
	return this->socket;
}

sockaddr_in LightSocket::getSocketAddress() 
{
	return this->addr;
}

void LightSocket::setSocketAddress(sockaddr_in socketAddress) 
{
	this->addr = socketAddress;
}

void LightSocket::connect(string host, int port) 
{

}
