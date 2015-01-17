/*
 *
 *
 * @author ada
 * @version 1.0
 * @since 1.0
 */

#include <string>
#include <windows.h>

#include "Socket.h"

using namespace std;

/**
 *
 *
 *
 */
#ifndef LIGHT_SOCKET
#define LIGHT_SOCKET

class _declspec(dllexport) LightSocket : public Socket 
{

private:

	//sockaddr_in socketAddress;

public:

	LightSocket();

	LightSocket(SOCKET socket);

	LightSocket(string host, int port);

	LightSocket(string host, int port, int stream);

	LightSocket(string host, int port, string localAddress, int localPort);

	~LightSocket();

	SOCKET getPlainSocket();

	sockaddr_in getSocketAddress();

	void setSocketAddress(sockaddr_in socketAddress);

	void connect(string host, int port);
};

#endif;