#include <stdio.h>
#include "PosixSync.hpp"

PosixSync::PosixSync()
{
	lock = new PosixMutexLock();
	int error = pthread_cond_init (&block, NULL);
	if (error)
	{
		printf("condition variable init fail, fail to call pthread_cond_init, error %d\n", error);
	}
}

void PosixSync::wait()
{
	int error = pthread_cond_wait(&block, lock->getMutex());
	if (error)
	{
		printf("condition variable wait fail, fail to call pthread_cond_wait, error %d\n", error);
	}
}

void PosixSync::notify()
{
	int error = pthread_cond_signal(&block);
	if (error)
	{
		printf("condition variable signal fail, fail to call pthread_cond_signal, error %d\n", error);
	}
}