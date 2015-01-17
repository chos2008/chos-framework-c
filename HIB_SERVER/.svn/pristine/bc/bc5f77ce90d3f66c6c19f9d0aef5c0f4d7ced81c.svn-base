#include <stdlib.h>
#include <log.h>
#include "Connection.hpp"

Connection::~Connection()
{
	if (this->handle == NULL)
	{
		debug("this->handle is NULL");
	}
	else 
	{
		debug("this->handle is not NULL");
		this->handle = NULL;
	}
}

void* Connection::getConnectionHandle()
{
	return this->handle;
}