/*
 *
 *
 * @author ada
 * @version 1.0
 * @since 1.0
 */
#include <stdlib.h>
#include "LuaException.hpp"

LuaException::LuaException(int code) 
{
	this->code = code;
	this->message = NULL;
}

LuaException::LuaException(char *message) 
{
	this->message = message;
}

LuaException::LuaException(int code, const char* message) 
{
	this->code = code;
	this->message = (char *) message;
}

int LuaException::getCode()
{
	return this->code;
}

char* LuaException::getMessage() 
{
	return this->message;
}