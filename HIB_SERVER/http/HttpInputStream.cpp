/*
 *
 *
 *
 *
 */

#include "../net/socket/LightSocket.h"
#pragma comment(lib, "ws2_32")
#include "HttpConnection.h"
#include "HttpInputStream.h"

/**
 *
 *
 *
 *
 */

/**
 *
 *
 *
 */
HttpInputStream::HttpInputStream(HttpConnection *connection) {
	this->connection = connection;
}


/**
 * Read a character from the connection base HTTP protocol
 *
 */
char HttpInputStream::read() {
	return 'a';
}

/**
 * Read a string from the connection base HTTP protocol
 *
 *
 */
string HttpInputStream::readstring() {
	return "";
}

int HttpInputStream::read(char* c) {
	return 0;
}

int HttpInputStream::read(char * c, int offset, int length) {
	LightSocket * socket = this->connection->getSocket();
	SOCKET iClientSocket = socket->getPlainSocket();
	sockaddr_in clientsocketaddress = socket->getSocketAddress();

	/*
	 * int recv(
     *     _In_   SOCKET s,
     *     _Out_  char *buf,
     *     _In_   int len,
     *     _In_   int flags
     * );
	 *
	 * flags [in]
     *     A set of flags that influences the behavior of this function. See remarks below. 
	 * See the Remarks section for details on the possible value for this parameter.
	 *
	 * The flags parameter can be used to influence the behavior of the function invocation 
	 * beyond the options specified for the associated socket. The semantics of this function 
	 * are determined by the socket options and the flags parameter. The possible value of 
	 * flags parameter is constructed by using the bitwise OR operator with any of the following 
	 * values.
     * Value	Meaning
     * MSG_PEEK	Peeks at the incoming data. The data is copied into the buffer, but is not 
	 *          removed from the input queue. The function subsequently returns the amount of 
	 *          data that can be read in a single call to the recv (or recvfrom) function, 
	 *          which may not be the same as the total amount of data queued on the socket. 
	 *          The amount of data that can actually be read in a single call to the recv (or 
	 *          recvfrom) function is limited to the data size written in the send or sendto 
	 *          function call.
     * MSG_OOB	Processes Out Of Band (OOB) data.
     * MSG_WAITALL	The receive request will complete only when one of the following events 
	 *          occurs:
     *          The buffer supplied by the caller is completely full.
     *          The connection has been closed.
     *          The request has been canceled or an error occurred.
     * Note that if the underlying transport does not support MSG_WAITALL, or if the socket 
	 * is in a non-blocking mode, then this call will fail with WSAEOPNOTSUPP. Also, if 
	 * MSG_WAITALL is specified along with MSG_OOB, MSG_PEEK, or MSG_PARTIAL, then this call 
	 * will fail with WSAEOPNOTSUPP. This flag is not supported on datagram sockets or message-
	 * oriented sockets.
     */
	int i = recv(iClientSocket, c, length, 0);
	if (i == 0 || (i == SOCKET_ERROR && WSAGetLastError() == WSAECONNRESET)) {
		printf("Closed Connection From %s\n", inet_ntoa(clientsocketaddress.sin_addr));
		closesocket(iClientSocket);
	}
	return i;
}