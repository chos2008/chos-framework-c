/*
 *
 *
 * @author ada
 * @version 1.0
 */
#ifdef PTHREAD_WIN32
#define __PTHREAD_WIN32

#include <pthread.h>
#include "../Lock.hpp"

#ifndef POSIX_SPIN_LOCK
#define POSIX_SPIN_LOCK

class PosixSpinLock 
{
private:

	pthread_spinlock_t spinlock;

public:

	PosixSpinLock();

	PosixSpinLock(const char* name);

	~PosixSpinLock();

	void lock();

	void lock(pthread_spinlock_t* mutex);

	void unlock();

	void unlock(pthread_spinlock_t* mutex);

	pthread_spinlock_t* getSpinLock();
};
#endif
#endif