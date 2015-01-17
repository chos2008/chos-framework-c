/*
 *
 *
 *
 *
 */

#include "SocketException.hpp"

#if ! defined SOCKET_INPUT_STREAM
#define SOCKET_INPUT_STREAM

class Socket;

/**
 *
 *
 *
 */
class _declspec(dllexport) SocketInputStream 
{

private:

	Socket *socket;

public:

	SocketInputStream();

	SocketInputStream(Socket *socket);

	~SocketInputStream();

	void setSocket(Socket *socket);

	int read(char * c, int offset, int length) throw (SocketException);

};

#endif;