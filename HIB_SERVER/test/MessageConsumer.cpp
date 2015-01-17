#include "MessageConsumer.hpp"
#include "MessageDestination.hpp"

MessageConsumer::MessageConsumer()
{
	this->destination = NULL;	
}

void MessageConsumer::registerConsumer(MessageDestination *destination) 
{
	this->destination = destination;
}


void MessageConsumer::run() 
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