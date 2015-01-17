#include <stdio.h>
#include "PosixSpinLock.hpp"

#ifdef __PTHREAD_WIN32
PosixSpinLock::PosixSpinLock()
{
	int error = pthread_spin_init(&spinlock, PTHREAD_PROCESS_PRIVATE);
	if (error)
	{
		printf("spin lock init fail, fail to call pthread_spin_init, error %d\n", error);
	}
}

PosixSpinLock::PosixSpinLock(const char* name)
{
	int error = pthread_spin_init(&spinlock, PTHREAD_PROCESS_PRIVATE);
	if (error)
	{
		printf("spin lock init fail, fail to call pthread_spin_init, error %d\n", error);
	}
}

PosixSpinLock::~PosixSpinLock()
{
	int error = pthread_spin_destroy(&spinlock);
	if (error)
	{
		printf("spin lock destroy fail, fail to call pthread_spin_destroy, error %d\n", error);
	}
}

void PosixSpinLock::lock()
{
	lock(&spinlock);
}

void PosixSpinLock::lock(pthread_spinlock_t* spinlock)
{
	int error = pthread_spin_lock(spinlock);
	if (error)
	{
		printf("spin lock fail, fail to call pthread_spin_lock, error %d\n", error);
	}
}

void PosixSpinLock::unlock()
{
	unlock(&spinlock);
}

void PosixSpinLock::unlock(pthread_spinlock_t* spinlock)
{
	int error = pthread_spin_unlock(spinlock);
	if (error)
	{
		printf("spin unlock fail, fail to call pthread_spin_unlock, error %d\n", error);
	}
}

pthread_spinlock_t* PosixSpinLock::getSpinLock()
{
	return &spinlock;
}
#endif