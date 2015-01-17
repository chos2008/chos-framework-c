#include <vector>
#include "Observer.hpp"

#ifndef OBSERVABLE
#define OBSERVABLE
class Observable
{
	private:
		std::vector<Observer *> observers;

	public:
		Observable();

		void registerObserver(Observer &o);

		void deregisterObserver(Observer &o);

		void notifyObservers();

		void notifyObservers(void *arg);

		void clearObservers();

		int getCountOfObserver();
};
#endif