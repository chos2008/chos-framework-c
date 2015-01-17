/*
 *
 *
 * @AUTHOR ADA
 * @VERSION 1.0
 * @SINCE 1.0
 */
#include "LightSocket.h"
#include "SocketInputStream.hpp"
#include "SocketOutputStream.hpp"

#ifndef HTTP_CONNECTION
#define HTTP_CONNECTION

class _declspec(dllexport) SocketConnectionException
{
private:
	int code;

public:
	SocketConnectionException() : code(0) 
	{
	
	}

	SocketConnectionException(int code)
	{
		this->code = code;
	}

	int getCode()
	{
		return this->code;
	}
};

/**
 *
 *
 *
 *
 *
 */
class _declspec(dllexport) SocketConnection 
{

private:

	LightSocket* socket;

public:

	/**
	 *
	 *
	 *
	 *
	 */
	SocketConnection(LightSocket * socket);

	~SocketConnection();

	/**
	 *
	 *
	 *
	 *
	 *
	 */
	LightSocket* getSocket();

	/**
	 *
	 *
	 *
	 *
	 *
	 */
	SocketInputStream* getInputStream();

	SocketOutputStream* getOutputStream();

	void close();

	int isClose();
};
/*
#if _MSC_VER > 1000
#pragma once
*/
#endif;