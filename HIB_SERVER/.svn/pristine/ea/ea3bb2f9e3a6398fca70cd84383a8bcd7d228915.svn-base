/*
 *
 *
 *
 *
 */

#include <WINDOWS.H>
#include <string>
using namespace std;

#include "Socket.h"
#include "LightSocket.h"

#ifdef TEST_SWITCH_OPEN
#define PRIVATE public:
#else 
#define PRIVATE private:
#endif

/**
 *
 *
 *
 *
 *
 *
 */
#ifndef HARD_SOCKET
#define HARD_SOCKET

//#if !defined HARD_SOCKET
//#define HARD_SOCKET



class _declspec(dllexport) HardSocket : public Socket {

private:

	void init() throw (SocketException);

public:

	/**
     * Default construct with none parameter. This construstor would instant a 
     * default {@link HardSocket} socket instance by call this construct.
     *
     * This constructor would instant a socket {@link HardSocket} instance which
     * unbound any port and local i net address.
     */
	HardSocket();

	/**
	 *
	 *
	 *
	 */
	HardSocket(int port);

	/**
	 *
	 *
	 *
	 */
	HardSocket(int port, string bindAddress);

	/**
	 *
	 *
	 *
	 *
	 */
	HardSocket(int port, int backlog);

	/**
	 *
	 *
	 *
	 *
	 */
	HardSocket(int port, int backlog, string bindAddress);

	~HardSocket();

	/**
	 * Bound to the specified port. A port of <code>0</code> creates a  
     * socket on any free port.
     * 
     * As the bound local address not specificed, it will default accepting
     * connections on any/all local addresses.
     */
	void bind(int port) throw (SocketException);

	/**
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 */
	void bind(int port, int backlog) throw (SocketException);

	/**
	 *
	 *
	 *
	 *
	 *
	 *
	 */
	void bind(string bindAddress) throw (SocketException);

	/**
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 */
	void bind(string bindAddress, int backlog) throw (SocketException);

	/**
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 */
	void bind(int port, string bindAddress) throw (SocketException);

	/**
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 */
	void bind(int port, string bindAddress, int backlog) throw (SocketException);

	void bind(int port, char* bindAddress, int backlog) throw (SocketException);

	void listen() throw (SocketException);

	void listen(int backlog) throw (SocketException);

	/**
	 *
	 *
	 *
	 *
	 */
	LightSocket* accept() throw (SocketException);
};
#endif