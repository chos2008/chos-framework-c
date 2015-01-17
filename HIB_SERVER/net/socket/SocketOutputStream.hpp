/*
 *
 * 
 * @author ada
 * @version 1.0
 * @since 1.0
 */

//#include "LightSocket.h"

#if ! defined SOCKET_OUTPUT_STREAM
#define SOCKET_OUTPUT_STREAM

class Socket;

class _declspec(dllexport) SocketOutputStream 
{
private:

	Socket *socket;

public:

	SocketOutputStream();

	SocketOutputStream(Socket *socket);

	void setSocket(Socket *socket);

	int write(const char* s, int offset, int length) throw (SocketException);

};

#endif;