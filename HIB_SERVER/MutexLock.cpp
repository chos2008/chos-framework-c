#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "log.h"
#include "MutexLock.hpp"

MutexLock::MutexLock()
{
	this->mutex = CreateMutex(NULL, FALSE, NULL);
	if (this->mutex == NULL) 
	{
		DWORD error = GetLastError();
		warn("create mutex error %d", error);
	}
	debug("MutexLock()");
}

MutexLock::MutexLock(const char* name) 
{
	this->mutex = CreateMutex(NULL, FALSE, name);
	if (this->mutex == NULL) 
	{
		DWORD error = GetLastError();
		warn("create mutex error %d", error);
	}
	else 
	{
		DWORD error = GetLastError();
		if (error == ERROR_ALREADY_EXISTS) 
		{
			debug("mutex name %s already exists, use the existed mutex instead.", name);
		}
	}
}

void MutexLock::lock()
{
	lock(this->mutex);
}

void MutexLock::lock(HANDLE mutex)
{
	DWORD event = WaitForSingleObject(mutex, INFINITE);
	if (event == WAIT_FAILED) 
	{
		DWORD error = GetLastError();
		warn("wait error %d", error);
	}
	else if(event == WAIT_TIMEOUT) 
	{
		debug("wait time out");
	}
	else if(event == WAIT_ABANDONED) 
	{
		debug("wait abandoned");
	}
}

void MutexLock::unlock()
{
	this->unlock(this->mutex);
}

void MutexLock::unlock(HANDLE mutex) 
{
	BOOL isr = ReleaseMutex(this->mutex);
	if (! isr) 
	{
		DWORD error = GetLastError();
		warn("release mutex error %d", error);
	}
}

HANDLE MutexLock::getMutex()
{
	return this->mutex;
}