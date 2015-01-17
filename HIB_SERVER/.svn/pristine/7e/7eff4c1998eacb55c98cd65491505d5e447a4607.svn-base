#include <stdio.h>
#include <assert.h>
#include "../lang/Observer.hpp"
#include "../lang/Observable.hpp"

class GenericObserver : public Observer
{
	void update(Observable* const o, void *arg)
	{
		char *command = (char *) arg;
		printf("[COMMAND] %s\n", command);
	}
};

void testGetCountOfObserver() 
{
	printf("test getCountOfObserver\n");
	Observable o;
	int count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 0);
}

void testRegisterObserver()
{
	printf("test registerObserver\n");
	Observable o;
	int count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 0);

	
	Observer *observer1 = new GenericObserver();
	o.registerObserver(*observer1);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 1);


	Observer *observer2 = new GenericObserver();
	o.registerObserver(*observer2);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 2);


	Observer *observer3 = new GenericObserver();
	o.registerObserver(*observer3);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 3);


	Observer *observer4 = new GenericObserver();
	o.registerObserver(*observer4);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 4);


	Observer *observer5 = new GenericObserver();
	o.registerObserver(*observer5);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 5);


	Observer *observer6 = new GenericObserver();
	o.registerObserver(*observer6);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 6);


	Observer *observer7 = new GenericObserver();
	o.registerObserver(*observer7);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 7);


	Observer *observer8 = new GenericObserver();
	o.registerObserver(*observer8);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 8);
}

void testDeregisterObserver()
{
	printf("test deregisterObserver\n");
	Observable o;
	int count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 0);

	
	Observer *observer1 = new GenericObserver();
	o.registerObserver(*observer1);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 1);


	Observer *observer2 = new GenericObserver();
	o.registerObserver(*observer2);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 2);


	Observer *observer3 = new GenericObserver();
	o.registerObserver(*observer3);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 3);


	Observer *observer4 = new GenericObserver();
	o.registerObserver(*observer4);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 4);


	Observer *observer5 = new GenericObserver();
	o.registerObserver(*observer5);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 5);


	Observer *observer6 = new GenericObserver();
	o.registerObserver(*observer6);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 6);


	Observer *observer7 = new GenericObserver();
	o.registerObserver(*observer7);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 7);


	Observer *observer8 = new GenericObserver();
	o.registerObserver(*observer8);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 8);


	o.deregisterObserver(*observer1);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 7);


	o.deregisterObserver(*observer2);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 6);


	o.deregisterObserver(*observer3);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 5);


	o.deregisterObserver(*observer4);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 4);


	o.deregisterObserver(*observer5);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 3);


	o.deregisterObserver(*observer6);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 2);


	o.deregisterObserver(*observer7);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 1);


	o.deregisterObserver(*observer8);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 0);
}

void testNotifyObservers()
{
	printf("test notifyObservers\n");
	Observable o;
	int count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 0);

	
	Observer *observer1 = new GenericObserver();
	o.registerObserver(*observer1);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 1);

	o.notifyObservers((void *) "fight");

	Observer *observer2 = new GenericObserver();
	o.registerObserver(*observer2);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 2);

	o.notifyObservers((void *) "fight");

	Observer *observer3 = new GenericObserver();
	o.registerObserver(*observer3);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 3);

	o.notifyObservers((void *) "fight");

	Observer *observer4 = new GenericObserver();
	o.registerObserver(*observer4);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 4);

	o.notifyObservers((void *) "fight");

	Observer *observer5 = new GenericObserver();
	o.registerObserver(*observer5);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 5);

	o.notifyObservers((void *) "fight");


	Observer *observer6 = new GenericObserver();
	o.registerObserver(*observer6);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 6);

	o.notifyObservers((void *) "fight");


	Observer *observer7 = new GenericObserver();
	o.registerObserver(*observer7);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 7);

	o.notifyObservers((void *) "fight");


	Observer *observer8 = new GenericObserver();
	o.registerObserver(*observer8);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 8);

	o.notifyObservers((void *) "fight");

	o.deregisterObserver(*observer1);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 7);

	o.notifyObservers((void *) "fight");

	o.deregisterObserver(*observer2);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 6);

	o.notifyObservers((void *) "fight");

	o.deregisterObserver(*observer3);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 5);

	o.notifyObservers((void *) "fight");

	o.deregisterObserver(*observer4);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 4);

	o.notifyObservers((void *) "fight");

	o.deregisterObserver(*observer5);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 3);

	o.notifyObservers((void *) "fight");

	o.deregisterObserver(*observer6);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 2);

	o.notifyObservers((void *) "fight");

	o.deregisterObserver(*observer7);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 1);

	o.notifyObservers((void *) "fight");

	o.deregisterObserver(*observer8);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 0);

	o.notifyObservers((void *) "fight");
}

void testNotifyObserversDefault()
{
	printf("test notifyObservers default\n");
	Observable o;
	int count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 0);

	
	Observer *observer1 = new GenericObserver();
	o.registerObserver(*observer1);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 1);

	o.notifyObservers();

	Observer *observer2 = new GenericObserver();
	o.registerObserver(*observer2);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 2);

	o.notifyObservers();

	Observer *observer3 = new GenericObserver();
	o.registerObserver(*observer3);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 3);

	o.notifyObservers();

	Observer *observer4 = new GenericObserver();
	o.registerObserver(*observer4);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 4);

	o.notifyObservers();

	Observer *observer5 = new GenericObserver();
	o.registerObserver(*observer5);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 5);

	o.notifyObservers();


	Observer *observer6 = new GenericObserver();
	o.registerObserver(*observer6);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 6);

	o.notifyObservers();


	Observer *observer7 = new GenericObserver();
	o.registerObserver(*observer7);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 7);

	o.notifyObservers();


	Observer *observer8 = new GenericObserver();
	o.registerObserver(*observer8);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 8);

	o.notifyObservers();

	o.deregisterObserver(*observer1);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 7);

	o.notifyObservers();

	o.deregisterObserver(*observer2);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 6);

	o.notifyObservers();

	o.deregisterObserver(*observer3);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 5);

	o.notifyObservers();

	o.deregisterObserver(*observer4);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 4);

	o.notifyObservers();

	o.deregisterObserver(*observer5);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 3);

	o.notifyObservers();

	o.deregisterObserver(*observer6);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 2);

	o.notifyObservers();

	o.deregisterObserver(*observer7);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 1);

	o.notifyObservers();

	o.deregisterObserver(*observer8);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 0);

	o.notifyObservers();
}

void testClearObservers()
{
	printf("test clearObservers\n");
	Observable o;
	int count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 0);

	
	Observer *observer1 = new GenericObserver();
	o.registerObserver(*observer1);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 1);

	o.notifyObservers();

	Observer *observer2 = new GenericObserver();
	o.registerObserver(*observer2);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 2);

	o.notifyObservers();

	Observer *observer3 = new GenericObserver();
	o.registerObserver(*observer3);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 3);

	o.notifyObservers();

	Observer *observer4 = new GenericObserver();
	o.registerObserver(*observer4);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 4);

	o.notifyObservers();

	Observer *observer5 = new GenericObserver();
	o.registerObserver(*observer5);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 5);

	o.notifyObservers();


	Observer *observer6 = new GenericObserver();
	o.registerObserver(*observer6);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 6);

	o.notifyObservers();


	Observer *observer7 = new GenericObserver();
	o.registerObserver(*observer7);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 7);

	o.notifyObservers();


	Observer *observer8 = new GenericObserver();
	o.registerObserver(*observer8);
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 8);

	o.notifyObservers();

	o.clearObservers();
	count = o.getCountOfObserver();
	printf("%d observers\n", count);
	assert(count == 0);

	o.notifyObservers();
}

struct _struct
{
	char c;
	short sts;
};

int main()
{
	printf("Test design pattern Observer\n");

	testGetCountOfObserver();
	testRegisterObserver();
	testDeregisterObserver();
	testNotifyObservers();
	testNotifyObserversDefault();
	testClearObservers();

	printf("sizeof(_struct): %d\n", sizeof(struct _struct));
	return 0;
}