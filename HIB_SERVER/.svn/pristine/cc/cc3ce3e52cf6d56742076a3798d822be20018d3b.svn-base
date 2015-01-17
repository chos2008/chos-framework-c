#include <pthread.h>
#include "PosixMutexLock.hpp"

#ifndef POSIX_SYNC
#define POSIX_SYNC
class PosixSync 
{
private:

protected:

	PosixMutexLock *lock;

	pthread_cond_t block;

public:

	PosixSync();

	void wait();

	void notify();

};
#endif