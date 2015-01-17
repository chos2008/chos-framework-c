/*
 *
 *
 * @author ada
 * @version 1.0
 * @since 1.0
 */
#include <queue>
#include "Observable.hpp"
#include "Destination.hpp"
#include "DestinationMessage.hpp"

#ifndef __QUEUE
#define __QUEUE
class Queue : public Destination, Observable
{
	private: 
		char* id;

		std::queue<int> destination;

	public: 
		Queue(char* id);

		virtual char* getId();

		int de();

		void en(int message);
};
#endif