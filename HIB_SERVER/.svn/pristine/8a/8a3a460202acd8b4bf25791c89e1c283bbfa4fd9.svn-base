#include <stdio.h>
#include <assert.h>
#include <windows.h>
#include "log.h"
#include "GRequestListener.hpp"

GRequestListener::GRequestListener(
	MutexLock *mutex)
{
	this->mutex = mutex;
	this->pBuffer = NULL;
	this->processor = new RequestProcessor();
}

void GRequestListener::run() 
{
	this->process();
}

void GRequestListener::update(RequestDataBuffer *pBuffer) 
{
	this->pBuffer = pBuffer;
}

RequestDataBuffer* GRequestListener::getBuffer() 
{
	return this->pBuffer;
}

RequestProcessor* GRequestListener::getProcessor()
{
	return this->processor;
}

bool GRequestListener::completed(DataBufferQueue & readBuffer)
{
	int size = readBuffer.size_of();
	if (size >= 4) 
	{
		return (
		readBuffer.element(size - 4) == '\r' &&
		readBuffer.element(size - 3) == '\n' &&

		readBuffer.element(size - 2) == '\r' &&
		readBuffer.element(size - 1) == '\n' );
	}
	return false;
}

void GRequestListener::process()
{
	///*
	DataBufferQueue readBuffer;
	bool isComplete = false;
	while (1) 
	{
		this->mutex->lock();
		
		if (this->pBuffer != NULL && (! this->pBuffer->isEmpty())) 
		{

			char c = this->pBuffer->read();
			//assert (c != NULL); // ensure read available character data from buffer!
			

			readBuffer.enqueue(c);

			isComplete = this->completed(readBuffer);
			//printf("----:%s\n", readBuffer.toString());
			if (isComplete) 
			{
				this->processor->process(readBuffer.toString());
				readBuffer.clear();
			}
		}
		

		// Release mutex
		this->mutex->unlock();
	}
	//*/
}