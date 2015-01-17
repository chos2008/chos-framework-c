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

#if ! defined REGISTOR_SERVER
#define REGISTOR_SERVER

class RegistorServer 
{
private:
	HardSocket* startRegistorServer() throw(SocketException);

	void startService();

	SocketConnection * createConnectionForClient(LightSocket* socket);

public:
    void start();
};

#endif
/*
 *
 */
DWORD WINAPI ModuleRegistorServer(LPVOID args);