#include "EventLock.hpp"
#include "Sync.hpp"

Sync::Sync()
{
	lock = new EventLock();
	block = new EventLock();
}

void Sync::wait()
{
	block->setState(EventLock::NON_SIGNALED);
	lock->unlock();
	block->lock();
	lock->lock();
}

void Sync::notify()
{
	block->setState(EventLock::SIGNALED);
}