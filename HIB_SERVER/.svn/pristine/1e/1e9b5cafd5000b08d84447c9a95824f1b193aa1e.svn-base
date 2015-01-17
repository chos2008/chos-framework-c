#include <log.h>
#include "ZoomServerSelectEventHandler.hpp"

void ZoomServerSelectEventHandler::onAccept(LightSocket &socket)
{
	sockaddr_in addr = socket.getSocketAddress();
	debug("handle on accept event from %s:%d(socket %d)", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port), socket.getPlainSocket());
}

void ZoomServerSelectEventHandler::onMessage(LightSocket &socket, char *bytes)
{
	sockaddr_in addr = socket.getSocketAddress();
	//打印接收的数据
	info("recv from %s:%d\ndata:%s", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port), bytes);
}
