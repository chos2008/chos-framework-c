
#include "Attribute.h"
#include "LPTagAttribute.h"

#ifndef START_TAG 
#define START_TAG

class _declspec(dllexport) StartTag {

protected:
	string name;

	LPTagAttribute* lpTagAttribute;

public:

	StartTag();

	StartTag(const string name);

	void setTagName(string name);

	string getTagName();

	void toStream(string* lpStream);

	void setAttribute(LPTagAttribute* lpTagAttribute);

	void appendAttribute(string name, string value);

	void appendAttribute(Attribute attribute);
};

#endif;