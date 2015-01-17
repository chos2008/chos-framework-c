#include "gs/RequestDataBuffer.h"
#include "gs/RequestProcessor.h"
#include "net/DataBufferQueue.h"


#ifndef REQUEST_DATA_BUFFER_QUEUE_LISTENER
#define REQUEST_DATA_BUFFER_QUEUE_LISTENER 

class RequestDataBufferQueueListener
{
private: 
	HANDLE *m_hMutex;

	RequestDataBuffer *pBuffer;

	RequestProcessor *processor;

public:

	RequestDataBufferQueueListener(HANDLE *m_hMutex);

	void start();

	void update(RequestDataBuffer *pBuffer);

	RequestDataBuffer* getBuffer();

	HANDLE* getMutex();

	RequestProcessor* getProcessor();

	bool completed(DataBufferQueue & readBuffer);

	void process();
};

#endif;