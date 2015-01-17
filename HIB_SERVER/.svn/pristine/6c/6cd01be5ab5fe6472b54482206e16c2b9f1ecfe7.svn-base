#include "socket/HardSocket.h"
#include "socket/LightSocket.h"
#include "SelectEventHandler.hpp"

#ifndef __SELECT
#define __SELECT

class Select 
{

private: 
	HardSocket *socket;

	fd_set fd;

	SelectEventHandler* eventHandler;

public:
	Select(HardSocket &socket);

	void registerSelectEventHandler(SelectEventHandler &eventHandler);

	void select();

	void onAccept();

	void onRead(SOCKET sfd);
};

#endif