/*
 *
 * @author ada
 * @version 1.0
 * @since 1.0
 */

#include <windows.h>

#include "net/socket/HardSocket.h"
#include "http/HttpConnection.h"
#include "http/HttpHandler.h"

#ifndef HTTP_SERVER
#define HTTP_SERVER

class HttpServer 
{

public: 
	/**
	 * Start http server and listen on the specific port
	 * 
	 * The handle of socket created returned. 
	 *
	 * @return 
	 *
	 *
	 */
	HardSocket* startHttpServer() throw (SocketException);

	void start();
};

#endif