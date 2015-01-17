#include "TestEventLockMessageDestination.hpp"
#include "TestEventLockMessageProducer.hpp"
#include "TestEventLockMessageConsumer.hpp"

void main()
{
	///*
	TestEventLockMessageDestination *destination = new TestEventLockMessageDestination();

	TestEventLockMessageProducer *producer = new TestEventLockMessageProducer();
	producer->registerProducer(destination);
	producer->start();

	TestEventLockMessageConsumer *consumer = new TestEventLockMessageConsumer();
	consumer->registerConsumer(destination);
	consumer->start();

	ExitThread(0);

}
