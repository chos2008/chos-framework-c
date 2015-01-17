/*
 *
 *
 */

#include "../micro.h"
#include "../net/socket/LightSocket.h"
#include "XMPPMessageHandler.hpp"

#if ! defined XMPP_STREAM
#define XMPP_STREAM

/**
 *
 *
 *
 */
class TK_API XMPPStream {

private:

	LightSocket* socket;

	XMPPMessageHandler *messageHandler;

public:

	XMPPStream(LightSocket *socket);

	void setMessageHandler(XMPPMessageHandler* handler);

	void openStream();


};

#endif;