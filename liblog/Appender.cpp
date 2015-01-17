#include "Appender.hpp"

Appender::Appender()
{
	this->appender = stdout;
}

Appender::Appender(FILE *appender)
{
	this->appender = appender;
}

Appender::~Appender()
{
	
}