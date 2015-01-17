#ifndef __LOCK
#define __LOCK

class Lock
{
public:
	
	virtual void lock() = 0;

	virtual void unlock() = 0;
};

#endif