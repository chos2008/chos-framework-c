#include "../net/socket/LightSocket.h"
#include "../net/SelectEventHandler.hpp"


#ifndef ZOOM_SERVER_SELECT_EVENT_HANDLER
#define ZOOM_SERVER_SELECT_EVENT_HANDLER

class ZoomServerSelectEventHandler : public SelectEventHandler 
{

public:

	virtual void onAccept(LightSocket &socket);

	virtual void onMessage(LightSocket &socket, char *bytes);

};

#endif