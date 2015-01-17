#include "dllexport.h"

#ifndef LOGGER
#define LOGGER
class __declspec_dllexport Logger
{
private:

public: 

	virtual void log(const char *level, const char *log, ...) = 0;

	virtual void debug(const char *log, ...) = 0;

	virtual void info(const char *log, ...) = 0;

	virtual void warn(const char *log, ...) = 0;

	virtual void error(const char *log, ...) = 0;

	virtual void fatal(const char *log, ...) = 0;

};
#endif