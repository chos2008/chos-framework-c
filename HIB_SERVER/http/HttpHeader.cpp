
#include <string>
using namespace std;

#include "log.h"
 
#include "../collection/List.h"
#include "../collection/LinkedElement.h"
//#include "LinkedElement.cpp"
//#include "../collection/List.cpp"
#include "HttpHeader.h"

//#include "TestClass.h"

/**
 * CONST VARIABLES DEFINITIONS, THE CONST VARIABLES 
 * DEFINITIONS LIST FOLLOW.
 * 
 * SEE EACH CONST VARIABLE DEFINITIONS FOR DETAILS
 */

/**
 * COMMA             = <US-ASCII COMMA, space (?)>
 * <p>
 * Comma character can represents as character ',', and it can be 
 * represented as ascii code <num>?</num> also as it's ascii code
 * is number <num>?</num>
 */
const char* HttpHeader::COMMA = ",";

/**
 * Construct an instance {@link HttpHeader} with the given header 
 * field name @c name @c and header field value @c value @c
 * 
 * @param name  the header field name passed
 * @param value the header field values passed
 */
HttpHeader::HttpHeader(string name, string value)/* : name(name) */ {
	this->name = name;

	/*
	TestClass* tc = new TestClass();
	LinkedElement<TestClass>* element = new LinkedElement<TestClass>(*tc);

	TestClass* tc2 = new TestClass();
	LinkedElement<TestClass>* element2 = new LinkedElement<TestClass>(tc2);
	*/


	
	LinkedElement<string> *e;
	//e = new LinkedElement<string>(&value);
/*
	this->value = new List<string>(e);
*/	
}

/**
 * Construct an instance {@link HttpHeader} with the given header 
 * field name @c name @c and header field value @c value @c
 * 
 * @param name  the header field name passed
 * @param value the header field values passed
 */
HttpHeader::HttpHeader(string name, List<string>* value) {
	this->name = name;
	this->value = value;
}

int HttpHeader::getHeaderType() {
	return 0;
}

/**
 * Implement of method {@link #getHeaderValue()} to get the value(s) of 
 * the header name field.
 * 
 * @see {@link HttpHeader}
 */
List<string> * HttpHeader::getHeaderValue() {
	return this->value;
}

/**
 * Implement of method {@link #toTextStream() to output the text 
 * stream of http message header. Including http request and http resp-
 * onse
 */
string HttpHeader::toTextStream() {
	/*
	string textStream = this->name;
	textStream = textStream + ":";
	if (this->value != NULL) {

		List<string> * list = this->getHeaderValue();

		if (list != NULL) {
			textStream = textStream + this->SP;

			LinkedElement<string> * iterator = list->getFirst();

			int size = list->size();
			int c = 0;
			while(iterator != NULL) {
				logdebug("-- ");
				string data = iterator->getData();
				textStream = textStream + data;
				if (c < size - 1) {
					textStream = textStream + this->COMMA;
				}
				printf("%s\n", data.c_str());
				iterator = iterator->getNext();
				c++;
			}

		}
	}
	return textStream;
	*/
	return NULL;
} 