/*
 *
 *
 * @author ada
 * @version 1.0
 * @since 1.0
 */

#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

//using namespace std;

#include "../net/socket/SocketException.hpp"
//#include "../net/socket/LightSocket.h"

#ifndef _WINDOWS_
#define __declspec_dllexport 



// bzero
//#define bzero(p, i) std::memset(p, 0, i)
#else 
#define __declspec_dllexport _declspec(dllexport)
#endif

/**
 *
 *
 *
 *
 *
 *
 */
#ifndef SERVER_SOCKET
#define SERVER_SOCKET

//#if !defined HARD_SOCKET
//#define HARD_SOCKET

class __declspec_dllexport ServerSocket {

private:

	int socket;

	// socket state
	int state;


public:

    /**
     * Default construct with none parameter. This construstor would instant a 
     * default {@link HardSocket} socket instance by call this construct.
     *
     * This constructor would instant a socket {@link HardSocket} instance which
     * unbound any port and local i net address.
     */
    ServerSocket() throw(SocketException);

    /**
     *
     *
     *
     */
    ServerSocket(int port);

	/**
	 *
	 *
	 *
	 */
	ServerSocket(int port, char* bindAddress);

	/**
	 *
	 *
	 *
	 *
	 */
	ServerSocket(int port, int backlog);

	/**
	 *
	 *
	 *
	 *
	 */
	ServerSocket(int port, int backlog, char* bindAddress);

	/**
	 *
	 *
	 *
	 *
	 *
	 */
	int getPlainSocket();

	/**
	 * Bound to the specified port. A port of <code>0</code> creates a  
     * socket on any free port.
     * 
     * As the bound local address not specificed, it will default accepting
     * connections on any/all local addresses.
     */
	void bind(int port) throw(SocketException);

	/**
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 */
	void bind(int port, int backlog);

	/**
	 *
	 *
	 *
	 *
	 *
	 *
	 */
	void bind(char* bindAddress);

	/**
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 */
	void bind(char* bindAddress, int backlog);

	/**
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 */
	void bind(int port, char* bindAddress);

	/**
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 */
	void bind(int port, char* bindAddress, int backlog);

    void listen();

    void listen(int backlog);

	/**
	 *
	 *
	 *
	 *
	 */
	//LightSocket* accept();

	/**
	 *
	 *
	 *
	 *
	 *
	 */
	void close();
};
#endif

