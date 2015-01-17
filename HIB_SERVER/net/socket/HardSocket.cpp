/*
 *
 *
 *
 * @author ada
 * @version 1.0
 * @since 1.0
 */

#include <windows.h>
#include <stdio.h>
#include <string>
using namespace std;

#include "log.h"
#include "LightSocket.h"
#include "HardSocket.h"

/**
 *
 *
 *
 *
 *
 *
 */

void HardSocket::init() throw (SocketException) 
{
	/*
	startup();
	this->socket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (this->socket == INVALID_SOCKET) 
	{
		int error = WSAGetLastError();
		throw SocketException(error);
	}
	logdebug("Create Socket                                              [OK]");
	*/
	Socket::init(AF_INET, SOCK_STREAM, IPPROTO_TCP);
}

/**
 * Default construct with none parameter. This construstor would instant a 
 * default {@link HardSocket} socket instance by call this construct.
 *
 * This constructor would instant a socket {@link HardSocket} instance which
 * unbound any port and local i net address.
 */
HardSocket::HardSocket() 
{	
	this->init();
}


/*
 * C++0x规范中允许这种写法:
 *
 *     HardSocket::HardSocket(int port) : HardSocket()
 * 
 * 注意: 在标准C++中，是不允许这种写法的。
 */
HardSocket::HardSocket(int port)// : HardSocket()
{
	this->init();
	bind(port, NULL, 50);
}

HardSocket::HardSocket(int port, string bindAddress)// : HardSocket()
{
	this->init();
	bind(port, bindAddress, 50);
}

HardSocket::HardSocket(int port, int backlog)// : HardSocket()
{
	this->init();
	bind(port, NULL, backlog);
}

HardSocket::HardSocket(int port, int backlog, string bindAddress)// : HardSocket()
{
	this->init();
	bind(port, bindAddress, backlog);
}

HardSocket::~HardSocket()
{
	printf("~HardSocket\n");
	this->close();
}

/**
 * Bound to the specified port. A port of <code>0</code> creates a  
 * socket on any free port.
 * 
 * As the bound local address not specificed, it will default accepting
 * connections on any/all local addresses.
 */
void HardSocket::bind(int port) throw (SocketException)
{
	bind(port, "", 50);
}

void HardSocket::bind(int port, int backlog) throw (SocketException)
{
	bind(port, NULL, backlog);
}

void HardSocket::bind(string bindAddress) throw (SocketException)
{
	bind(0, bindAddress, 50);
}

void HardSocket::bind(string bindAddress, int backlog) throw (SocketException)
{
	bind(0, bindAddress, backlog);
}

void HardSocket::bind(int port, string bindAddress) throw (SocketException)
{
	bind(port, bindAddress, 50);
}

void HardSocket::bind(int port, string bindAddress, int backlog) throw (SocketException)
{
	bind(port, bindAddress.c_str(), backlog);
}

void HardSocket::bind(int port, char* bindAddress, int backlog) throw (SocketException)
{
    // /*
	//  * Socket address, internet style.
	//  */
	// struct sockaddr_in {
	//         short   sin_family;
	//         u_short sin_port;
	//         struct  in_addr sin_addr;
	//         char    sin_zero[8];
	// };
	sockaddr_in socketaddress;
	socketaddress.sin_family = AF_INET;
	if (bindAddress == NULL) 
	{
		socketaddress.sin_addr.S_un.S_addr = INADDR_ANY;
	}
	else 
	{
		socketaddress.sin_addr.s_addr = inet_addr(bindAddress); //socketaddress.sin_addr.s_addr = inet_addr("172.0.0.1");
	}
	socketaddress.sin_port = htons(port);

	this->addr = socketaddress;
	// /*
	//  * Structure used by kernel to store most
	//  * addresses.
	//  */
	// struct sockaddr {
	//         u_short sa_family;              /* address family */
	//         char    sa_data[14];            /* up to 14 bytes of direct address */
	// };
	// 
	// typedef struct sockaddr FAR *LPSOCKADDR;
	SOCKET socket = getPlainSocket();
	int error = ::bind(socket, (LPSOCKADDR) &this->addr, sizeof(this->addr));
	if (error == SOCKET_ERROR) 
	{
		error = WSAGetLastError();
		throw SocketException(error);
	}
	logdebug("Bind Socket on Socket Address                              [OK]");
}

void HardSocket::listen() throw (SocketException)
{
	listen(50);
}

void HardSocket::listen(int backlog) throw (SocketException)
{
	SOCKET socket = getPlainSocket();
	int error = ::listen(socket, backlog);
	if (error == SOCKET_ERROR) 
	{
		error = WSAGetLastError();
		throw SocketException(error);
	}
}

/**
 *
 *
 *
 *
 *
 */
LightSocket* HardSocket::accept() throw (SocketException)
{
	sockaddr_in addr;
	int len = sizeof(SOCKADDR_IN);

	SOCKET _socket = getPlainSocket();
	SOCKET iClientSocket = ::accept(_socket, (SOCKADDR *) &addr, &len);
	debug("accept socket#%d", iClientSocket);
	if (iClientSocket == INVALID_SOCKET) 
	{
		int error = WSAGetLastError();
		if (getNonBlocking() && error == WSAEWOULDBLOCK) 
		{
			return NULL;
		}
		else 
		{
			throw SocketException(error);
		}
	}

	LightSocket * socket = new LightSocket(iClientSocket);
	socket->setSocketAddress(addr);
	return socket;
}
