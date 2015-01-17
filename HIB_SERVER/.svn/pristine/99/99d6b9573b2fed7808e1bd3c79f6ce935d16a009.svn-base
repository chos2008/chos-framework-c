/*
 * Registor server
 *
 *
 *
 * 
 * @author ada
 * @version 1.0
 * @since 1.0
 */
#include "../net/socket/HardSocket.h"
#include "../net/socket/SocketConnection.h"

#if ! defined NON_BLOCK_REGISTOR_SERVER
#define NON_BLOCK_REGISTOR_SERVER

class NonBlockRegistorServer 
{
private:
	HardSocket* startRegistorServer() throw(SocketException);

	void startService();

	SocketConnection * createConnectionForClient(LightSocket* socket);

public:
    void start();
};

#endif
