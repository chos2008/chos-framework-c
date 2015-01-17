#include "Lock.hpp"
#include "EventLock.hpp"

#ifndef __SYNC
#define __SYNC
class Sync 
{
private:

protected:

	EventLock *lock;

	EventLock *block;

public:

	Sync();

	void wait();

	void notify();

};
#endif