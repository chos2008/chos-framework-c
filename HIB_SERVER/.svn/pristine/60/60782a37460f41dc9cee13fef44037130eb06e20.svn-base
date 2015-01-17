#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string>
using namespace std;
#include "log.h"
#include "RequestDataBuffer.h"

RequestDataBuffer::RequestDataBuffer()
{
	try
	{
		this->dataBuffer = new DataBufferQueue();
	}
	catch(bad_alloc &e)
	{
		//失败以后，要么abort要么重分配
		error("\nbad_alloc++++++++++++++++++++++%s\n", e.what());
		this->dataBuffer = NULL;
	}
	
	this->listeners = NULL;//new GameServerRequestDataBufferQueueListener[8];
}

void RequestDataBuffer::registerListener(GRequestListener *listener)
{
	this->listeners = listener;
}

void RequestDataBuffer::notify(GRequestListener *listeners) 
{
	if (this->listeners != NULL) 
	{
		listeners->update(this);
	}
}

void RequestDataBuffer::write(char *data)
{
	this->dataBuffer->enqueue(data);
	this->notify(this->listeners);
}

char RequestDataBuffer::read()
{
	return this->dataBuffer->dequeue();
}

void RequestDataBuffer::clear() 
{
	this->dataBuffer->clear();
}

bool RequestDataBuffer::isEmpty()
{
	return this->dataBuffer->isEmpty();
}

int RequestDataBuffer::size_of()
{
	return this->dataBuffer->size_of();
}

char* RequestDataBuffer::toString()
{

	return this->dataBuffer == NULL ? NULL : this->dataBuffer->toString();
}