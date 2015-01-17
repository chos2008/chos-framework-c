#include <stdio.h>
#include "../Thread.hpp"
#include "TestEventLockMessageDestination.hpp"

#ifndef TEST_EVENT_LOCK_MESSAGE_PRODUCER
#define TEST_EVENT_LOCK_MESSAGE_PRODUCER

class TestEventLockMessageProducer : public Thread 
{
private:
	TestEventLockMessageDestination *destination;

public: 
	TestEventLockMessageProducer()
	{
		this->destination = NULL;	
	}

	void registerProducer(TestEventLockMessageDestination *destination) 
	{
		this->destination = destination;
	}

	void run()
	{
		while (1) 
		{
			if (destination != NULL) 
			{
				destination->add();
			}
			//Sleep(5000);
		}
	}
};
#endif