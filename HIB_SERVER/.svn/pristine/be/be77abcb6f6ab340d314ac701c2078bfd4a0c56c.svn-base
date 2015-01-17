#include <stdio.h>
#include "../Thread.hpp"
#include "TestEventLockMessageDestination.hpp"

#ifndef TEST_EVENT_LOCK_MESSAGE_CONSUMER
#define TEST_EVENT_LOCK_MESSAGE_CONSUMER

class TestEventLockMessageConsumer : public Thread 
{
private:
	TestEventLockMessageDestination *destination;
	

public: 
	TestEventLockMessageConsumer()
	{
		this->destination = NULL;	
	}

	void registerConsumer(TestEventLockMessageDestination *destination) 
	{
		this->destination = destination;
	}


	void run() 
	{
		while (1)
		{
			if (destination != NULL) 
			{
				this->destination->reduce();
			}
			//Sleep(500);
		}
	}
};
#endif