#include <stdio.h>
#include "../MutexLock.hpp"
#include "../Thread.hpp"
#include "MessageDestination.hpp"

#ifndef MESSAGE_CONSUMER
#define MESSAGE_CONSUMER
class MessageConsumer : public Thread 
{
private:
	MessageDestination *destination;
	

public: 
	MessageConsumer();

	void registerConsumer(MessageDestination *destination);


	void run();
};
#endif