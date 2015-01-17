
#include "Attribute.h"

#ifndef LP_TAG_ATTRIBUTE 
#define LP_TAG_ATTRIBUTE

class _declspec(dllexport) LPTagAttribute {

private:
	Attribute firstAttribute;
	LPTagAttribute *next;

public:

	LPTagAttribute();

	LPTagAttribute(const string name, const string value);

	LPTagAttribute(const string name, const string value, const string nextName, const string nextValue);
/*
	LPTagAttribute(const string name, const string value, Attribute nextAttribute);
*/
	LPTagAttribute(Attribute attribute);
/*
	LPTagAttribute(Attribute attribute, Attribute nextAttribute);
*/

/*
	int operator ==(LPTagAttribute lpTagAttribute);

	int operator !=(LPTagAttribute lpTagAttribute);
*/

	void setFirstAttribute(Attribute attribute);

	Attribute getFirstAttribute();

	void setNextAttribute(Attribute nextAttribute);

	void setNext(LPTagAttribute* next);

	LPTagAttribute* getNext();

	Attribute getNextAttribute();

};
#endif;