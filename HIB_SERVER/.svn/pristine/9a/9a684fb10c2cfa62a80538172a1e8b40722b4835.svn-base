/*
 * Handle the request(SOCK Level) from connection, echo connection is a client.
 * Read network data request from client.
 */

#include "dllexport.h"
#include "../net/socket/SocketConnection.h"
#include "../net/socket/SocketConnectionEventHandler.hpp"
#include "RequestDataBuffer.h"
#include "BinaryRequest.h"

/**
 *
 *
 *
 *
 *
 *
 */

#ifndef SOCKET_CONNECTION_HANDLER
#define SOCKET_CONNECTION_HANDLER

class __declspec_dllexport SocketConnectionHandler 
{

private:

	MutexLock *mutex;

	RequestDataBuffer *requestDataBuffer;

	SocketConnectionEventHandler* eventHandler;

public:

	/**
	 *
	 *
	 *
	 */
	SocketConnectionHandler(MutexLock *mutex, RequestDataBuffer *requestDataBuffer);

	void registerEventHandler(SocketConnectionEventHandler *eventHandler);

	void process(char *data);

	void readPacket(SocketConnection *connection, BinaryRequest *request) throw (SocketConnectionException);

	void handle0(SocketConnection * connection);
	/**
	 *
	 *
	 *
	 *
	 */
	void handle(SocketConnection * connection);

};

#endif;