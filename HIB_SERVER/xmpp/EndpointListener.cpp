/*
 *
 *
 */

#include "log.h"
#include "EndpointListener.hpp"


/**
 *
 *
 *
 */

EndpointListener::EndpointListener(HardSocket* socket) {
	this->socket = socket;
}

void EndpointListener::start() {
	loginfo("Accepting Client Sockets Connection...                      [OK]\n");
	while(1) {
		LightSocket *socket = this->socket->accept();
		this->socketHandler.handle(socket);
	}
}