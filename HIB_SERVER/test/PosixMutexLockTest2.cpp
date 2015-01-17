#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../posix/PosixThread.hpp"
#include "../posix/PosixMutexLock.hpp"

class Counter 
{
	private:
		int num;
		PosixMutexLock *lock;
	public: 
		Counter() 
		{
			num = 0;
			lock = new PosixMutexLock();
		}

		void count() 
		{
			for (int i = 0; i < 20; i++)
			{
				//lock->lock();
				int t = num;
				t++;
				//sleep(1);
				num = t;
				pthread_t pt = pthread_self();
				printf("Thread %d Up count: %d\n", pt, num);
				//lock->unlock();
			}
		}
		int getCount()
		{
			return num;
		}
};


class Up : public PosixThread 
{
	private: 
		Counter *counter;
	public: 
		Up(Counter* counter)
		{
			this->counter = counter;
		}

		void run() 
		{
			counter->count();
		}
};

int main()
{
	Counter *counter = new Counter();
	PosixThread *t1 = new Up(counter);
	PosixThread *t2 = new Up(counter);
	t1->start();
	t2->start();
	
	int *status = NULL;
	pthread_join(t1->getId(), (void **) &status);
	pthread_join(t2->getId(), (void **) &status);
	
	printf("final count: %d\n", counter->getCount());
	return 0;
}