#include<pthread.h>
#include<iostream>

using std::cout;
using std::endl;
using std::cin;

class ABClock
{
public:
	virtual ~ABClock() {}
	
	virtual void lock() = 0;
	
	virtual void unlock() = 0;
};

class MutexLock: public ABClock
{
public:
	MutexLock() { 
		pthread_mutex_init(&alock, NULL);
	}
	
	~MutexLock() { 
		pthread_mutex_destroy( &alock);
	}
	
	inline void lock() { 
		pthread_mutex_lock(&alock);
	}
	
	inline void unlock() { 
		pthread_mutex_unlock( &alock);
	}

private:
	pthread_mutex_t alock;
};

int main()
{
	cout<<"hello"<<endl;
	MutexLock thelock;
	thelock.lock();
	cout<< "locked"<<endl;
	thelock.unlock();
	int a;
	cin>>a;
	return 0;
}