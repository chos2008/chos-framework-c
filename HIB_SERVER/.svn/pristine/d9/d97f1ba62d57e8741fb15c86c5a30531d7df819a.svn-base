#define _WIN32_WINNT 0x0400
#include <stdio.h>
#include <windows.h>
#include "MessageDestination.hpp"

MessageDestination::MessageDestination()
{
	i = 0;
}

void MessageDestination::add()
{
	lock.lock();
	i++;
	printf("[Producer] message %d\n", this->i);
	lock.unlock();
}

void MessageDestination::reduce()
{
	lock.lock();
	i--;
	printf("[Consumer] message %d\n", i);
	lock.unlock();
}