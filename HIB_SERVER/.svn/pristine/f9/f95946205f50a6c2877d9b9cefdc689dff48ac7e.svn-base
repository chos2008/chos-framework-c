/**
 * 
 *
 * @author a.da
 * @since 1.0
 */
#include <stdio.h>
#include <assert.h>
#include <windows.h>
#include "log.h"
#include "RequestDataBufferQueueListener.h"

DWORD WINAPI RequestDataBufferQueueListenerCallback(LPVOID args);

RequestDataBufferQueueListener::RequestDataBufferQueueListener(
	HANDLE *m_hMutex)
{
	this->m_hMutex = m_hMutex;
	this->pBuffer = NULL;
	this->processor = new RequestProcessor();
}

void RequestDataBufferQueueListener::start() 
{
	DWORD threadID;
	CreateThread(NULL, 
		0, 
		RequestDataBufferQueueListenerCallback, 
		(LPVOID) this, 
		0, 
		&threadID);
	logdebug("Thread Request Data Buffer Listener started...\n");
}

void RequestDataBufferQueueListener::update(RequestDataBuffer *pBuffer) 
{
	this->pBuffer = pBuffer;
}

RequestDataBuffer* RequestDataBufferQueueListener::getBuffer() 
{
	return this->pBuffer;
}

HANDLE* RequestDataBufferQueueListener::getMutex()
{
	return this->m_hMutex;
}

RequestProcessor* RequestDataBufferQueueListener::getProcessor()
{
	return this->processor;
}

bool RequestDataBufferQueueListener::completed(DataBufferQueue & readBuffer)
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

void RequestDataBufferQueueListener::process()
{
	///*
	DataBufferQueue readBuffer;
	bool isComplete = false;
	while (1) 
	{
		WaitForSingleObject(&this->m_hMutex, INFINITE);
		
		
		if (this->pBuffer != NULL && (! this->pBuffer->isEmpty())) 
		{

			char c = this->pBuffer->read();
			//assert (c != NULL); // ensure read available character data from buffer!
			

			readBuffer.enqueue(c);

			isComplete = this->completed(readBuffer);
			if (isComplete) 
			{
				/*
				printf("========================================\n");
				printf("%s\n", readBuffer.toString());
				readBuffer.clear();
				printf("========================================\n");
				 */
				this->processor->process(readBuffer.toString());
				readBuffer.clear();
			}
		}
		

		// Release mutex
		BOOL release = ReleaseMutex(&this->m_hMutex);
		/*
		if (release)
		{
			logdebug("Success to release mutex...\n");
		}
		else
		{
			logdebug("Fail to release mutex...\n");
		}
		*/
	}
	//*/
}

DWORD WINAPI RequestDataBufferQueueListenerCallback(LPVOID args) 
{
	RequestDataBufferQueueListener *listener = 
		(RequestDataBufferQueueListener *) args;
	listener->process();
	return 0;
}
