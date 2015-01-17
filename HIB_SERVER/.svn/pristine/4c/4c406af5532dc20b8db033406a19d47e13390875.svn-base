#include <log.h>
#include "../net/socket/Socket.h"
#include "../net/socket/SocketInputStream.hpp"

void throwSocketException() throw (SocketException)
{
	throw SocketException(Socket::CLOSED);
}
void testSocketException() 
{
	try 
	{
		throwSocketException();
	}
	catch(SocketException e) 
	{
		info("socket exception %s(%d)", e.getMessage(), e.getCode());
	}
}
void main()
{
	testSocketException();

	SocketInputStream *is = new SocketInputStream(NULL);
	try 
	{
		is->read(NULL, 0, 0);
	}
	catch (SocketException e) 
	{
		info("read error, socket exception %s(%d)", e.getMessage(), e.getCode());
	}
}