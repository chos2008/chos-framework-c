

#include "LinkedElement.h"

/*
 * Implement of default construct with none parameter, default
 * constructs would instant a instance with empty data which data value 
 * @c NULL @c, and the next element @c NULL @c
 */
template<typename T>
LinkedElement<T>::LinkedElement(): data(NULL), next(NULL) {
	
}

/*
 * Implement of construct with parameter @c data @c {@link T}, 
 * this would instant a instance with data value @c data @c, and
 * the next element  @c NULL @c
 */
/*
template<typename T> 
LinkedElement<T>::LinkedElement(const T & data):data(data), next(NULL) {
	
}
*/

template<typename T> LinkedElement<T>::LinkedElement(const T * data) : data(*data), next(NULL) {

}

template<typename T>
LinkedElement<T> & LinkedElement<T>::operator= (const LinkedElement<T> & element) {
	/*
	this->data = element->data;
	this->next = NULL;
	LinkedElement<T> *lpNext = element.next;
	while (*lpNext != NULL) {
		this->next = new LinkedElement<T>(lpNext->data);
		lpNext = lpNext->next;
	}
	*/
	
	return *this;
}

/*
 * Implement of construct with parameter @c data @c and @c lpNext @c, 
 * this would instant a instance with data value @c data @c, and 
 * the next element value @c lpNext @c
 */
template<typename T>
LinkedElement<T>::LinkedElement(const T data, LinkedElement<T>* lpNext):data(data), next(lpNext) {
	
}

/*
 * Implement of method {@link #getData()} to get the data of 
 * {@link LinkedElement}
 */

template<typename T> T LinkedElement<T>::getData() {
	return this->data;
}


/*
 * Implement of method {@link #getNext()} to get the next element of 
 * {@link LinkedElement}
 */

template<typename T> LinkedElement<T>* LinkedElement<T>::getNext() {
	return this->next;
}


template<typename T> void LinkedElement<T>::setNext(LinkedElement<T>* next) {
	
	this->next = next;
	/*
	LinkedElement<string> e2("bbb");
	this->next = &e2;
	*/
}