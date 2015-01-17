#include <stdio.h>
#include "MessageProducer.hpp"
#include "../MutexLock.hpp"
#include "../Thread.hpp"
#include "MessageDestination.hpp"

MessageProducer::MessageProducer()
{
	this->destination = NULL;	
}

void MessageProducer::registerProducer(MessageDestination *destination) 
{
	this->destination = destination;
}

void MessageProducer::run()
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