#include <log.h>
#include "LightSocket.h"
#include "SocketEventHandler.hpp"

void SocketEventHandler::onClose(LightSocket &socket)
{
	debug("close event");
}

void SocketEventHandler::onAccept(LightSocket &socket)
{
	sockaddr_in addr = socket.getSocketAddress();
	debug("handle on accept event from %s:%d(socket %d)", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port), socket.getPlainSocket());
}

void SocketEventHandler::onMessage(LightSocket &socket, char *bytes)
{
	sockaddr_in addr = socket.getSocketAddress();
	//打印接收的数据
	info("recv from %s:%d\ndata:%s", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port), bytes);
}
