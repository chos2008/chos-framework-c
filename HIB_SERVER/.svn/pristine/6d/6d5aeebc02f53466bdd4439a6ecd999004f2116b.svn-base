#include <windows.h>
#include "Lock.hpp"

#ifndef _EVENT_LOCK
#define _EVENT_LOCK

class EventLock : public Lock
{

private: 
	
	HANDLE event;

public:
	const static int SIGNALED;

	const static int NON_SIGNALED;

	EventLock();

	EventLock(const char* name);

	virtual void lock();

	void lock(HANDLE event);

	virtual void unlock();

	void unlock(HANDLE event);

	void setState(int state);

	HANDLE getEvent();
};

#endif