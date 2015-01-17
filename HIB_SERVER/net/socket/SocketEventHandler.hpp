#ifndef SOCKET_EVENT_HANDLER
#define SOCKET_EVENT_HANDLER

class SocketEventHandler 
{

public: 

	virtual void onClose(LightSocket &socket);

	virtual void onAccept(LightSocket &socket);

	virtual void onMessage(LightSocket &socket, char *bytes);
};

#endif