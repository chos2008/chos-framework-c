#include <stdio.h>
#include "dllexport.h"

#ifndef APPENDER
#define APPENDER

class __declspec_dllexport Appender 
{
protected:

	FILE *appender;

public:

	Appender();

	Appender(FILE *appender);

	~Appender();

	virtual void log(const char *level, const char *log, ...) = 0;

	virtual void debug(const char *log, ...) = 0;

	virtual void info(const char *log, ...) = 0;

	virtual void warn(const char *log, ...) = 0;

	virtual void error(const char *log, ...) = 0;

	virtual void fatal(const char *log, ...) = 0;
};


#endif