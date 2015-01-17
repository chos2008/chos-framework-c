/*
 *
 *
 * @author ada
 * @version 1.0
 * @since 1.0
 */
#include <stdlib.h>
#include "SQLException.hpp"

SQLException::SQLException(int code) 
{
	this->code = code;
	this->message = NULL;
}

SQLException::SQLException(char *message) 
{
	this->message = message;
}

SQLException::SQLException(int code, const char* message) 
{
	this->code = code;
	this->message = (char *) message;
}

int SQLException::getCode()
{
	return this->code;
}

char* SQLException::getMessage() 
{
	return this->message;
}