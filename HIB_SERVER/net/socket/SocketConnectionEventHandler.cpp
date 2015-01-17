/*
 * 
 *
 * @author ada
 * @version 1.0
 */
#include <log.h>
#include "LightSocket.h"
#include "SocketConnection.h"
#include "SocketConnectionEventHandler.hpp"

void SocketConnectionEventHandler::onClose(SocketConnection *connection)
{
	debug("close event");
	LightSocket *socket = connection->getSocket();
	socket->close();
	info("%s:%d closed connection", socket->getInetAddressAsString(), socket->getPort());
	connection->close();
	//delete connection;
}

void SocketConnectionEventHandler::onAccept(SocketConnection *connection)
{
	LightSocket *socket = connection->getSocket();
	sockaddr_in addr = socket->getSocketAddress();
	debug("handle on accept event from %s:%d(socket %d)", 
		inet_ntoa(addr.sin_addr), ntohs(addr.sin_port), socket->getPlainSocket());
}

void SocketConnectionEventHandler::onMessage(SocketConnection *connection, char *bytes)
{
	LightSocket *socket = connection->getSocket();
	sockaddr_in addr = socket->getSocketAddress();
	//打印接收的数据
	info("recv from %s:%d\ndata:%s", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port), bytes);
}
