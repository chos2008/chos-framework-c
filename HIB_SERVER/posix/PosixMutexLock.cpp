#include <stdio.h>
#include <pthread.h>
#include "PosixMutexLock.hpp"

PosixMutexLock::PosixMutexLock()
{
	int error = pthread_mutex_init(&mutex, NULL);
	if (error)
	{
		printf("mutex init fail, fail to call pthread_mutex_init, error %d\n", error);
	}
}

PosixMutexLock::PosixMutexLock(const char* name)
{
	int error = pthread_mutex_init(&mutex, NULL);
	if (error)
	{
		printf("mutex init fail, fail to call pthread_mutex_init, error %d\n", error);
	}
}

PosixMutexLock::~PosixMutexLock()
{
	int error = pthread_mutex_destroy(&mutex);
	if (error)
	{
		printf("mutex destroy fail, fail to call pthread_mutex_destroy, error %d\n", error);
	}
}

void PosixMutexLock::lock()
{
	lock(&mutex);
}

void PosixMutexLock::lock(pthread_mutex_t* mutex)
{
	int error = pthread_mutex_lock(mutex);
	if (error)
	{
		printf("lock fail, fail to call pthread_mutex_lock, error %d\n", error);
	}
}

void PosixMutexLock::unlock()
{
	unlock(&mutex);
}

void PosixMutexLock::unlock(pthread_mutex_t* mutex)
{
	int error = pthread_mutex_unlock(mutex);
	if (error)
	{
		printf("unlock fail, fail to call pthread_mutex_lock, error %d\n", error);
	}
}

pthread_mutex_t* PosixMutexLock::getMutex()
{
	return &mutex;
}