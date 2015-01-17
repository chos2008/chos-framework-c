#define _WIN32_WINNT 0x0400
#include <stdio.h>
#include <windows.h>
#include "../MutexLock.hpp"

#ifndef MESSAGE_DESTINATION
#define MESSAGE_DESTINATION

class MessageDestination 
{
private: 
	MutexLock lock;

	int i;

public:
	MessageDestination();

	void add();

	void reduce();
};
#endif