#include "TestPosixMutexLockMessageDestination.hpp"
#include "TestPosixMutexLockMessageProducer.hpp"
#include "TestPosixMutexLockMessageConsumer.hpp"

int main()
{
	TestPosixMutexLockMessageDestination *destination = new TestPosixMutexLockMessageDestination();

	TestPosixMutexLockMessageProducer *producer = new TestPosixMutexLockMessageProducer();
	producer->registerProducer(destination);
	producer->start();

	TestPosixMutexLockMessageConsumer *consumer = new TestPosixMutexLockMessageConsumer();
	consumer->registerConsumer(destination);
	consumer->start();

	pthread_exit(NULL);
	return 0;
}
