#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "log.h"
#include "EventLock.hpp"

const int EventLock::SIGNALED = 1;

const int EventLock::NON_SIGNALED = 0;

EventLock::EventLock()
{
	this->event = CreateEvent(NULL, FALSE, TRUE, NULL);
	if (this->event == NULL) 
	{
		DWORD error = GetLastError();
		warn("create event error %d", error);
	}
	debug("EventLock()");
}

EventLock::EventLock(const char* name) 
{
	this->event = CreateEvent(NULL, FALSE, FALSE, name);
	if (this->event == NULL) 
	{
		DWORD error = GetLastError();
		warn("create event error %d", error);
	}
	else 
	{
		DWORD error = GetLastError();
		if (error == ERROR_ALREADY_EXISTS) 
		{
			debug("event name %s already exists, use the existed event instead.", name);
		}
	}
}

void EventLock::lock()
{
	lock(this->event);
}

void EventLock::lock(HANDLE event)
{
	DWORD e = WaitForSingleObject(event, INFINITE);
	if (e == WAIT_FAILED) 
	{
		DWORD error = GetLastError();
		warn("wait error %d", error);
	}
	else if(e == WAIT_TIMEOUT) 
	{
		debug("wait time out");
	}
	else if(e == WAIT_ABANDONED) 
	{
		debug("wait abandoned");
	}
}

void EventLock::unlock()
{
	this->unlock(this->event);
}

void EventLock::unlock(HANDLE event) 
{
	BOOL isr = SetEvent(this->event);
	if (! isr) 
	{
		DWORD error = GetLastError();
		warn("release event error %d", error);
	}
}

void EventLock::setState(int state)
{
	if (state == EventLock::SIGNALED) 
	{
		int error = SetEvent(this->event);
		if (! error) 
		{
			DWORD e = GetLastError();
			warn("error to set event object to signaled state");
		}
	}
	else if(state == EventLock::NON_SIGNALED) 
	{
		int error = ResetEvent(this->event);
		if (! error) 
		{
			DWORD e = GetLastError();
			warn("error to set event object to nonsignaled state");
		}
	}
}

HANDLE EventLock::getEvent()
{
	return this->event;
}