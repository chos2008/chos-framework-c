#include "dllexport.h"
#include "Logger.hpp"
#include "Appender.hpp"

#ifndef LOGGER_WRAPPER
#define LOGGER_WRAPPER
class __declspec_dllexport LoggerWrapper : public Logger
{
private:
	Appender *appender;

public: 
	LoggerWrapper();

	~LoggerWrapper();
	

	virtual void log(const char *level, const char *log, ...);

	virtual void debug(const char *log, ...);

	virtual void info(const char *log, ...);

	virtual void warn(const char *log, ...);

	virtual void error(const char *log, ...);

	virtual void fatal(const char *log, ...);

};
#endif