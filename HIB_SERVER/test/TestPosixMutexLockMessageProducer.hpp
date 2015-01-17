#include <stdio.h>
#include "../posix/PosixThread.hpp"
#include "TestPosixMutexLockMessageDestination.hpp"

#ifndef TEST_POSIX_MUTEX_LOCK_MESSAGE_PRODUCER
#define TEST_POSIX_MUTEX_LOCK_MESSAGE_PRODUCER

class TestPosixMutexLockMessageProducer : public PosixThread 
{
private:
	TestPosixMutexLockMessageDestination *destination;

public: 
	TestPosixMutexLockMessageProducer();

	void registerProducer(TestPosixMutexLockMessageDestination *destination);

	void run();
};
#endif