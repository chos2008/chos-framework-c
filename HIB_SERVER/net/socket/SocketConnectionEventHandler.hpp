#include "SocketConnection.h"

#ifndef SOCKET_CONNECTION_EVENT_HANDLER
#define SOCKET_CONNECTION_EVENT_HANDLER

class SocketConnectionEventHandler 
{

public: 

	virtual void onClose(SocketConnection *connection);

	virtual void onAccept(SocketConnection *connection);

	virtual void onMessage(SocketConnection *connection, char *bytes);
};

#endif