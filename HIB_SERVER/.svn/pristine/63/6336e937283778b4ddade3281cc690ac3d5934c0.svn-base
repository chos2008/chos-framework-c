#include "TestPosixMutexLockMessageDestination.hpp"


TestPosixMutexLockMessageDestination::TestPosixMutexLockMessageDestination()
{
	i = 0;
	
}

void TestPosixMutexLockMessageDestination::add()
{
	lock->lock();
	i++;
	printf("[Producer] message %d\n", this->i);

	if (i > 0)
	{
		notify();
	}
	lock->unlock();
}

void TestPosixMutexLockMessageDestination::reduce()
{
	lock->lock();
	if (i <= 0)
	{
		wait();
	}
	i--;
	printf("[Consumer] message %d\n", i);
	
	lock->unlock();
}
