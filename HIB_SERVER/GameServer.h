#include "SQLException.hpp"
#include "net/socket/HardSocket.h"
#include "net/socket/LightSocket.h"
#include "net/socket/SocketConnection.h"
#include "gs/Instance.hpp"

#ifndef GAME_SERVER
#define GAME_SERVER

class GameServer 
{
private:
	void getBarriers(Instance *instance, char* instance_idx);

	Instance * getInstances() throw (SQLException);

	void init();

	HardSocket* startGameServer() throw(SocketException);

    void startService();

public:
	void start();
};

#endif