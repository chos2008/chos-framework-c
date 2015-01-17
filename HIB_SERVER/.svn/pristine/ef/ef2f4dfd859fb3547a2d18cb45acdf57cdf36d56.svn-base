/**
 *
 *
 */
//interface

#include "LinkedElement.h"
#include "List.h"

/*
 * Implement of default construct with none parameter, default constructs
 * would construct a empty list collection {@link List}
 * 
 * @see {@link List(const LinkedElement<T> &)
 */

template<typename T>
List<T>::List():/*first(NULL), tail(NULL), */length(0) {
	this->first = NULL;
	this->tail = this->first;
}

/*
 * Implement of construct with parameter @c element @c, this would 
 * instant an instance with the first element value and the tail 
 * element all value @c element @c.
 *
 * @see {@link List()}
 */

template<typename T>
List<T>::List(LinkedElement<T> * element)/* : first(element), tail(element), length(1) */{
	this->first = element;
	if (element == NULL) {
		this->tail = this->first;
		this->length = 0;
		return;
	}
	int size = 1;
	LinkedElement<T> *lpElement = element;
	while (lpElement->getNext() != NULL) {
		size++;
		lpElement = lpElement->getNext();
	}
	this->tail = lpElement;
	this->length = size;
}


template<typename T>
List<T> * List<T>::operator= (const List<T> * list) {
	return this;
}

/*
 * Implement of method to get the size of list collection. The size 
 * value indicates that how many elements in this list collection.
 */
template<typename T> int List<T>::size() {
	return this->length;
}

/*
 * Implement of method to measure whether the list collection is empty
 * or not. 
 * 
 * The size of list collection value zero indicates the list collection 
 * is empty.
 * 
 * @see {@link #notEmpty()}
 */
template<typename T> int List<T>::empty() {
	return !(this->size());
}

/*
 * Implement of method to measure whether the list collection is not
 * empty or not.
 *
 * @see {@link #empty()}
 */
template<typename T> int List<T>::notEmpty() {
	return this->size();
}

/*
 * Implement of method to add an element into the first of list col-
 * lection.
 */
template<typename T>
void List<T>::addFirst(const LinkedElement<T> & element) {
	if (this->notEmpty()) { 
		LinkedElement<T> *lpElement = this->first;
		element.setNext(this->first);
		this->first = element;
	} else {
		this->first = element;
		this->tail = this->first;
	}
	this->length++;
}

/*
 * Implement of method to add an element into the list collection. By 
 * default, the new element added would add into the first of list 
 * collection.
 * 
 * @see {@link #addFirst(const LinkedElement<T> &)}
 */
template<typename T> void List<T>::add(const LinkedElement<T> & element) {
	this->addFirst(element);
}

/*
 * Implement of method to get the first element of list collection
 * 
 * @see {@link #get(const int)}
 */

template<typename T> LinkedElement<T>* List<T>::getFirst() {
	//return this->first;
	
	return NULL;
}
