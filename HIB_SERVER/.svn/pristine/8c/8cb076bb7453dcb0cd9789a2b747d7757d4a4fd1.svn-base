/*
 *
 *
 *
 *
 *
 *
 *
 */

#include "HttpConnection.h"
#include "HttpInputStream.h"

/**
 *
 *
 *
 *
 *
 *
 */

/**
 *
 *
 *
 *
 *
 *
 */
HttpConnection::HttpConnection(LightSocket * socket) {
	this->socket = socket;
}

/**
 *
 *
 *
 *
 *
 *
 */
LightSocket* HttpConnection::getSocket() {
	return this->socket;
}

HttpInputStream HttpConnection::getInputStream() {
	HttpInputStream* inputStream = new HttpInputStream(this);
	return *inputStream;
}
