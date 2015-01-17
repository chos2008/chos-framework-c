
#include <string>
using namespace std;


#include "Attribute.h"
#include "LPTagAttribute.h"

LPTagAttribute::LPTagAttribute() {

}

LPTagAttribute::LPTagAttribute(const string name, const string value) {
	Attribute attribute(name, value);
	this->firstAttribute = attribute;
	this->next = NULL;
}

LPTagAttribute::LPTagAttribute(const string name, const string value, const string nextName, const string nextValue) {
	Attribute attribute(name, value);
	this->firstAttribute = attribute;
	
	LPTagAttribute lpTagAttribute(nextName, nextValue);
	this->next = &lpTagAttribute;
}

/*
	LPTagAttribute(const string name, const string value, Attribute nextAttribute);
*/
LPTagAttribute::LPTagAttribute(Attribute attribute) {
	this->firstAttribute = attribute;
	this->next = NULL;
}
/*
	LPTagAttribute(Attribute attribute, Attribute nextAttribute);
*/
/*
int LPTagAttribute::operator ==(LPTagAttribute lpTagAttribute) {
	
	Attribute fa = lpTagAttribute.getFirstAttribute();
	if (this->firstAttribute != fa) {
		return 0;
	}
	LPTagAttribute lpNext = this->next;
	LPTagAttribute _lpNext = lpTagAttribute.getNext();
	while (lpNext != NULL && _lpNext != NULL) {
		Attribute firstAttribute = (*lpNext).getFirstAttribute();
		Attribute _firstAttribute = (*_lpNext).getFirstAttribute();
		if (firstAttribute != _firstAttribute) {
			return 0
		}
		lpNext = lpNext.getNext();
		_lpNext = _lpNext.getNext();
	}
	
	return 1;
}

int LPTagAttribute::operator !=(LPTagAttribute lpTagAttribute) {
	if (this == &lpTagAttribute) {
		return 0;
	}
	return 1;
}
*/

void LPTagAttribute::setFirstAttribute(Attribute attribute) {
	this->firstAttribute = attribute;
}

Attribute LPTagAttribute::getFirstAttribute() {
	return this->firstAttribute;
}

void LPTagAttribute::setNextAttribute(Attribute nextAttribute) {
	
	LPTagAttribute lpTagAttribute(nextAttribute);

	LPTagAttribute* parent = this;
	LPTagAttribute* lpNext = this->next;
	while (lpNext != NULL) {
		parent = lpNext;
		lpNext = lpNext->next;
	}
	lpNext = new LPTagAttribute(lpTagAttribute);
	parent->setNext(lpNext);
}

void LPTagAttribute::setNext(LPTagAttribute* next) {
	this->next = next;
}

LPTagAttribute* LPTagAttribute::getNext() {
	return this->next;
}

Attribute LPTagAttribute::getNextAttribute() {
	return this->next->firstAttribute;
}
