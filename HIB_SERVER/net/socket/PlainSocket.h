
#include <WINDOWS.H>

#include "SocketProvider.h"

/**
 * @c PlainSocket @c {@link PlainSocket} provides a plain 
 * implementation of socket. A plain socket represents a socket
 * implementation of system type.
 *
 *
 * 
 */
class _declspec(dllexport) PlainSocket {

private:

	SOCKET socket;


public:

	/**
	 *
	 *
	 *
	 */
	Socket();

	/**
	 *
	 *
	 *
	 */
	Socket(const SocketProvider provider);

	/**
	 *
	 *
	 *
	 */
	void close();

};