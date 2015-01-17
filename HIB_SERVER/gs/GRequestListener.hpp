#include "../Thread.hpp"
#include "../MutexLock.hpp"
#include "RequestDataBuffer.h"
#include "RequestProcessor.h"
#include "../net/DataBufferQueue.h"

#ifndef G_REQUEST_LISTENER
#define G_REQUEST_LISTENER 

class RequestDataBuffer;

class GRequestListener : public Thread
{
private: 
	MutexLock *mutex;

	RequestDataBuffer *pBuffer;

	RequestProcessor *processor;

public:

	GRequestListener(MutexLock *mutex);

	void update(RequestDataBuffer *pBuffer);

	RequestDataBuffer* getBuffer();

	RequestProcessor* getProcessor();

	bool completed(DataBufferQueue & readBuffer);

	void process();

	void run();
};

#endif