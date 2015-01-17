#include <unistd.h>
#include "TestPosixMutexLockMessageConsumer.hpp"

TestPosixMutexLockMessageConsumer::TestPosixMutexLockMessageConsumer()
{
	this->destination = NULL;	
}

void TestPosixMutexLockMessageConsumer::registerConsumer(TestPosixMutexLockMessageDestination *destination) 
{
	this->destination = destination;
}

void TestPosixMutexLockMessageConsumer::run() 
{
	while (1)
	{
		if (destination != NULL) 
		{
			this->destination->reduce();
		}
		//sleep(1);
	}
}