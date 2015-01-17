

/*
 * 
 */
//interface 

#include<string>
using namespace std;
#include "../collection/LinkedElement.h"
#include "../collection/List.h"
#include "CPPHttpMessage.h"

/**
 * 
 *
 */
#ifndef HTTP_HEADER
#define HTTP_HEADER
class _declspec(dllexport) HttpHeader : public HttpMessage {

public:
	static const char* COMMA;

private:

	string name;

	List<string>* value;

public:

	HttpHeader(string name, string value);

	HttpHeader(string name, List<string>* value);

	/*virtual*/ int getHeaderType();

	string getHeaderName();

	List<string> * getHeaderValue();

	string toTextStream();
};
#endif;