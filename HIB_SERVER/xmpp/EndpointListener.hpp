/*
 *
 *
 */

#include "../micro.h"
#include "../net/socket/HardSocket.h"
#include "XMPPHandler.hpp"


#if ! defined ENDPOINT_LISTENER
#define ENDPOINT_LISTENER

class TK_API EndpointListener {
	
private:

	HardSocket *socket;

	XMPPHandler socketHandler;


public:

	EndpointListener(HardSocket* socket);

	void start();

};

#endif;