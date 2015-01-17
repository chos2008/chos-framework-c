#include "Appender.hpp"

#ifndef SOCKET_APPENDER
#define SOCKET_APPENDER
class __declspec_dllexport SocketAppender : public Appender
{
public:

	SocketAppender(char *host, int port);

	void log(const char *level, const char *log, ...);

	void debug(const char *log, ...);

	void info(const char *log, ...);

	void warn(const char *log, ...);

	void error(const char *log, ...);

	void fatal(const char *log, ...);
};
#endif