
#ifndef REQUEST_DATA_BUFFER
#define REQUEST_DATA_BUFFER 

#include "../net/DataBufferQueue.h"
#include "GRequestListener.hpp"


class RequestDataBuffer
{
private:
	DataBufferQueue *dataBuffer;
	GRequestListener *listeners;

public:
	RequestDataBuffer();

	void RequestDataBuffer::registerListener(
		GRequestListener *listener);

	void notify(GRequestListener *listeners);

	void write(char *data);

	char read();

	void clear();

	bool isEmpty();

	int size_of();

	char* toString();
};

#endif;