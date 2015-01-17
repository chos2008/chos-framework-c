/*
 *
 *
 * @author ada
 * @version 1.0
 * @since 1.0
 */

#include "log.h"
#include "HttpHandler.h"


/**
 *
 *
 *
 */
HttpHandler::HttpHandler(MutexLock *mutex) 
{
	this->mutex = mutex;
}

void HttpHandler::process(HttpConnection * connection, char *data)
{
	
}

/**
 *
 *
 *
 *
 */
void HttpHandler::handle(HttpConnection * connection) 
{
	HttpInputStream is = connection->getInputStream();
	
	int size = 64;
	char *bytes = (char *) malloc(size * sizeof(char));
	memset(bytes, 0, size);

	int i = 0;
	while (1) 
	{
		try 
		{
			i = is.read(bytes, 0, size - 1);
		}
		catch (SocketException e) 
		{
			if (e.getCode() == Socket::CLOSED) 
			{
				LightSocket *socket = connection->getSocket();
				socket->close();
				info("%s:%d closed connection", socket->getInetAddressAsString(), socket->getPort());
				break;
			}
		}
		printf("byte stream:%s\n", bytes);
/*
		this->mutex->lock();
		this->process(connection, bytes);
		
		this->mutex->unlock();
*/		
		memset(bytes, 0, size);
		
		if (i < size - 1) 
		{
			break;
		}
	}
}