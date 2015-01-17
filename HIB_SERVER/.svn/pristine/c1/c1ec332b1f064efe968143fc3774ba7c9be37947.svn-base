#include <unistd.h>
#include "TestPosixMutexLockMessageProducer.hpp"

TestPosixMutexLockMessageProducer::TestPosixMutexLockMessageProducer()
{
	this->destination = NULL;	
}

void TestPosixMutexLockMessageProducer::registerProducer(TestPosixMutexLockMessageDestination *destination) 
{	
	this->destination = destination;
}

void TestPosixMutexLockMessageProducer::run()
{
	while (1) 
	{
		if (destination != NULL) 
		{
			destination->add();
		}
		//sleep(5);
	}
}
