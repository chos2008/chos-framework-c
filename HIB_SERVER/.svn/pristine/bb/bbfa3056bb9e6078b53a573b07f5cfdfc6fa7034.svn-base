#include <stdio.h>
#include "../MutexLock.hpp"
#include "../Thread.hpp"
#include "MessageDestination.hpp"

#ifndef MESSAGE_PRODUCER
#define MESSAGE_PRODUCER

class MessageProducer : public Thread 
{
private:
	MessageDestination *destination;

public: 
	MessageProducer();

	void registerProducer(MessageDestination *destination);

	void run();
};
#endif