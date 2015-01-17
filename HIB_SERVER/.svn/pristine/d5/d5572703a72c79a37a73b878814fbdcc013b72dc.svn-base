


#ifndef LINKED_ELEMENT 
#define LINKED_ELEMENT

template<typename T>

class /*_declspec(dllexport)*/ LinkedElement {

	public:

		T data;
		LinkedElement<T> *next;

	/*
	 * Public methods and constructs definitions
	 */
	public:

		/*
		 * Default constructs with none parameter.
		 */
		LinkedElement();

		/*
		 * Constructs with parameter data @c T @c
		 */
		//LinkedElement(const T & data);

		LinkedElement(const T * data);

		LinkedElement<T> & operator= (const LinkedElement<T> & element);

		/*
		 * Constructs with parameter @c data @c {@link T} and 
		 * parameter @c lpNext @c, which the parameter @c lpNext @c 
		 * reference instance of {@link LinkedElement}
		 */
		LinkedElement(const T data, LinkedElement<T>* lpNext);

		/*
		 * Method to get the data @c data @c of {@link LinkedElement}
		 */
		T getData();

		/*
		 * Method to get the next element @c next @c of {@link LinkedElement}
		 */
		LinkedElement<T>* getNext();

		/*
		 * Method to set the next element @c next @c of {@link LinkedElement}
		 */
		void setNext(LinkedElement<T>* next);
};
#endif;