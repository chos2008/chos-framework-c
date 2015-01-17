#include <iostream>
#include <map>

#include "Request.h"

RequestException::RequestException()
{
	this->message = NULL;
}

RequestException::RequestException(char* message)
{
	this->message = message;
}

char* RequestException::getMessage()
{
	return this->message;
}

Request::Request(char* command)
{
	this->command = command;
}

Request::Request(char* command, std::map<char*, char*> paramMap)
{
	this->command = command;
	this->paramMap = paramMap;
}

void Request::setParameter(char* param, char* value)
{
	this->paramMap.insert ( std::pair<char*, char*>(param, value) );
}

char* Request::getParameterValue(char* param)
{
	//return this->paramMap.at(param).second;
	std::map<char*, char*>::iterator it 
		= this->paramMap.find(param);
	char* value = it == paramMap.end() ? NULL : it->second;
	return value;
}