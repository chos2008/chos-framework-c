#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../posix/PosixThread.hpp"
#include "../posix/PosixSpinLock.hpp"

int count = 0;

class Up : public PosixThread 
{
	private: 
		PosixSpinLock *lock;

	public: 
		Up()
		{
			lock = new PosixSpinLock();
		}

		void run() 
		{
			for (int i = 0; i < 20; i++)
			{
				lock->lock();
				int t = count;
				//sleep(2);
				t++;
				count = t;
				pthread_t pt = pthread_self();
				printf("Thread %d Up count: %d\n", pt, count);
				lock->unlock();
			}
		}
};

class Down : public PosixThread
{
	public:
		void run()
		{
			for (int i = 0; i < 20; i++)
			{
				int t = count;
				t--;
				count = t;
				printf("Down count: %d\n", count);
			}
		}
};

int main()
{
	PosixThread *t1 = new Up();
	PosixThread *t2 = new Up();
	t1->start();
	t2->start();
	
	int *status = NULL;
	pthread_join(t1->getId(), (void **) &status);
	pthread_join(t2->getId(), (void **) &status);
	
	printf("final count: %d\n", count);
	return 0;
}