#include <windows.h>
#include "Lock.hpp"

#ifndef _MUTEX_LOCK
#define _MUTEX_LOCK

class MutexLock : public Lock
{

private: 
	
	HANDLE mutex;

public:
	MutexLock();

	MutexLock(const char* name);

	void lock();

	void lock(HANDLE mutex);

	void unlock();

	void unlock(HANDLE mutex);

	HANDLE getMutex();
};

#endif