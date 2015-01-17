#include <stdlib.h>
#include <vector>
#include "Observable.hpp"

Observable::Observable()
{
	
}

void Observable::registerObserver(Observer &o) 
{
	observers.push_back(&o);
}

void Observable::deregisterObserver(Observer &o) 
{
	for (std::vector<Observer *>::iterator iter = observers.begin(); iter != observers.end(); ++iter)
	{
		if (*iter == &o)
		{
			observers.erase(iter);
			break;
		}
	}
}

void Observable::notifyObservers()
{
	notifyObservers(NULL);
}

void Observable::notifyObservers(void *arg)
{
	for(std::vector<Observer *>::iterator iter = observers.begin(); iter != observers.end(); ++iter)
	{
		Observer *observer = (Observer *) (*iter);
		observer->update(this, arg);
	}
}

void Observable::clearObservers()
{
	observers.clear();
}


int Observable::getCountOfObserver()
{
	return observers.size();
}