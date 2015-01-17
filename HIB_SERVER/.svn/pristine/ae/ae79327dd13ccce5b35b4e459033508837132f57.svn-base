#include <stdio.h>
#include "DestinationMessage.hpp"
#include "Queue.hpp"

Queue::Queue(char* id)
{
	this->id = id;
}

char* Queue::getId() 
{
	return this->id;
}

int Queue::de()
{
	if (destination.empty())
	{
		return 0;
	}
	int message = destination.front();
	destination.pop();
	return message;
}

void Queue::en(int message)
{
	destination.push(message);

	printf("empty: %s, size of destination %d\n", destination.empty() ? "true" : "false", destination.size());
}