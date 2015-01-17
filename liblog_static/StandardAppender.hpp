#include "log.h"
#include "Appender.hpp"

#if ! defined STANDARD_APPENDER
#define STANDARD_APPENDER
class __declspec_dllexport StandardAppender : public Appender
{
public:

	void log(const char *level, const char *log, ...);

	void debug(const char *log, ...);

	void info(const char *log, ...);

	void warn(const char *log, ...);

	void error(const char *log, ...);

	void fatal(const char *log, ...);
};
#endif