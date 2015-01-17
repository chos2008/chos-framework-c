#define _WIN32_WINNT 0x0400
#include <stdio.h>
#include <windows.h>
#include "../Sync.hpp"


#ifndef TEST_EVENT_LOCK_MESSAGE_DESTINATION
#define TEST_EVENT_LOCK_MESSAGE_DESTINATION

class TestEventLockMessageDestination : public Sync
{
private: 

	int i;

public:
	TestEventLockMessageDestination()
	{
		i = 0;
	}

	void add()
	{
		lock->lock();
		i++;
		printf("[Producer] message %d\n", this->i);
		
		if (i > 0) 
		{
			this->notify();
		}
		
		lock->unlock();
	}

	void reduce()
	{
		lock->lock();
		if (i <= 0) 
		{
			this->wait();
		}
		
		i--;
		printf("[Consumer] message %d\n", i);
		
		lock->unlock();
	}
};
#endif