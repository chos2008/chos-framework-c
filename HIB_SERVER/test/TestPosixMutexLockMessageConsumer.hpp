#include <stdio.h>
#include "../posix/PosixThread.hpp"
#include "TestPosixMutexLockMessageDestination.hpp"

#ifndef TEST_POSIX_MUTEX_LOCK_MESSAGE_CONSUMER
#define TEST_POSIX_MUTEX_LOCK_MESSAGE_CONSUMER

class TestPosixMutexLockMessageConsumer : public PosixThread 
{
private:
	TestPosixMutexLockMessageDestination *destination;
	

public: 
	TestPosixMutexLockMessageConsumer();

	void registerConsumer(TestPosixMutexLockMessageDestination *destination);


	void run();
};
#endif