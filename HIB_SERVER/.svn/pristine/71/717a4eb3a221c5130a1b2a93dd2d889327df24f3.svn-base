/*
 * Handle the http connection from client
 *
 *
 *
 *
 *
 *
 *
 * @author a.da
 * @since 1.0
 * @see HttpConection
 */
#include "HttpConnection.h"
#include "../MutexLock.hpp"

#ifndef HTTP_HANDLER
#define HTTP_HANDLER

/**
 * 
 *
 *
 *
 */
class _declspec(dllexport) HttpHandler {

private:
	MutexLock *mutex;

public:

	/**
	 *
	 *
	 *
	 */
	HttpHandler(MutexLock *mutex);

	void process(HttpConnection * connection, char *data);

	/**
	 *
	 *
	 *
	 *
	 */
	void handle(HttpConnection * connection);
};

#endif