/**
 *
 *
 */
//interface

#include "LinkedElement.h"

/*
 *
 *
 */

#ifndef LIST
#define LIST

template<typename T>
class _declspec(dllexport) List {

	protected: 
		LinkedElement<T> *first;

		LinkedElement<T>* tail;

		int length;

	public:
		
		List();

		List(LinkedElement<T> * element);

		List<T> * operator= (const List<T> * list);

		int size();

		int empty();

		int notEmpty();

		void addFirst(const LinkedElement & element);

		void add(const LinkedElement & element);

		LinkedElement<T>* getFirst();
};
#endif;