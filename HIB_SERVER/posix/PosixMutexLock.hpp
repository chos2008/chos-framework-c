#include <pthread.h>
#include "../Lock.hpp"

#ifndef POSIX_MUTEX_LOCK
#define POSIX_MUTEX_LOCK

class PosixMutexLock : public Lock
{

private: 
	pthread_mutex_t mutex;

public:
	PosixMutexLock();

	PosixMutexLock(const char* name);

	~PosixMutexLock();

	void lock();

	void lock(pthread_mutex_t* mutex);

	void unlock();

	void unlock(pthread_mutex_t* mutex);

	pthread_mutex_t* getMutex();
};

#endif