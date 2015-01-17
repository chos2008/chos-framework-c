/*
 *
 *
 * @author ada
 * @version 1.0
 * @since 1.0
 */
#include <errno.h>
#include "ServerSocket.h"



ServerSocket::ServerSocket() throw(SocketException)
{
	this->socket = ::socket(AF_INET, SOCK_STREAM, 0);
	if (this->socket == -1)
	{
		int error = errno;
		printf("socket create error %d\n", error);
		throw SocketException();
	}
}

/**
 *
 *
 *
 */
ServerSocket::ServerSocket(int port) 
{

}

/**
 *
 *
 *
 */
ServerSocket::ServerSocket(int port, char* bindAddress) 
{

}

	/**
	 *
	 *
	 *
	 *
	 */
ServerSocket::ServerSocket(int port, int backlog) {

}

	/**
	 *
	 *
	 *
	 *
	 */
ServerSocket::ServerSocket(int port, int backlog, char* bindAddress) {

}

	/**
	 *
	 *
	 *
	 *
	 *
	 */
int ServerSocket::getPlainSocket() {
	return 0;
}


void ServerSocket::bind(int port) throw(SocketException)
{
	struct sockaddr_in s_addr;
	bzero(&s_addr, sizeof(struct sockaddr_in));

    s_addr.sin_family = AF_INET;
    s_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    s_addr.sin_port = htons(port);
	
    if(-1 == ::bind(this->socket, (struct sockaddr *) (&s_addr), sizeof(struct sockaddr)))
	{
        printf("bind fail! error %d\n", errno);
        char *message = NULL;
        if (errno == EINVAL) 
        {
            message = "The socket is already bound to an address.";
        }
        throw SocketException(errno, message);
	}
    printf("bind ok !\r\n");
	/**/
}

	/**
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 */
void ServerSocket::bind(int port, int backlog) {

}

	/**
	 *
	 *
	 *
	 *
	 *
	 *
	 */
void ServerSocket::bind(char* bindAddress) {

}
	/**
	 *
	 *
	 *
	 *
	 *
	 *
	 *
	 */
void ServerSocket::bind(char* bindAddress, int backlog) 
{

}

/**
 *
 *
 *
 *
 *
 *
 *
 */
void ServerSocket::bind(int port, char* bindAddress) 
{

}

/**
 *
 *
 *
 *
 *
 *
 *
 */
void ServerSocket::bind(int port, char* bindAddress, int backlog) 
{

}

/**
 *
 *
 *
 *
 */
//LightSocket* accept();

void ServerSocket::listen() 
{
    listen(50);
}

void ServerSocket::listen(int backlog) 
{
    int error = ::listen(this->socket, backlog);
    if (error == -1) 
    {
        printf("fail to listen, error %d\n", errno);
    }
}

/**
 *
 *
 *
 *
 *
 */
void ServerSocket::close() 
{

}
