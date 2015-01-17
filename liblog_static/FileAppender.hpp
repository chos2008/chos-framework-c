#include <stdio.h>
#include "Appender.hpp"

#if ! defined FILE_APPENDER
#define FILE_APPENDER

class __declspec_dllexport FileAppender : public Appender 
{
public:

	FileAppender(const char *dest);

	FileAppender(FILE *appender);

	void log(const char *level, const char *log, ...);

	void debug(const char *log, ...);

	void info(const char *log, ...);

	void warn(const char *log, ...);

	void error(const char *log, ...);

	void fatal(const char *log, ...);
};
#endif