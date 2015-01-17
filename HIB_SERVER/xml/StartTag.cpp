
#include <string>
using namespace std;

#include "Attribute.h"
#include "LPTagAttribute.h"
#include "StartTag.h"

StartTag::StartTag() {
	this->lpTagAttribute = NULL;
}

StartTag::StartTag(const string name) {
	this->lpTagAttribute = NULL;
	this->name = name;
}

void StartTag::setTagName(const string name) {
	this->name = name;
}

string StartTag::getTagName() {
	return this->name;
}

void StartTag::toStream(string* lpStream) {
	string stream = "<";
	stream = stream + this->name;
	LPTagAttribute* lpLPTagAttribute = this->lpTagAttribute;
	while (lpLPTagAttribute != NULL) {
		Attribute attr = lpLPTagAttribute->getFirstAttribute();
		stream = stream + " ";
		stream = stream + attr.getAttributeName();
		stream = stream + "='";
		stream = stream + attr.getAttributeValue();
		stream = stream + "'";
		lpLPTagAttribute = lpLPTagAttribute->getNext();
	}
	stream = stream + ">";
	*lpStream = stream;
	return;
}

void StartTag::setAttribute(LPTagAttribute* lpTagAttribute) {
	this->lpTagAttribute = lpTagAttribute;
}

void StartTag::appendAttribute(string name, string value) {
	Attribute attribute(name, value);
	this->appendAttribute(attribute);
}

void StartTag::appendAttribute(Attribute attribute) {
	/*
	if (this->lpTagAttribute == NULL) {
		this->lpTagAttribute = new LPTagAttribute(attribute);
		return;
	}
	*/
	
	LPTagAttribute* parent = NULL;
	LPTagAttribute* lpLPTagAttribute = this->lpTagAttribute;
	while (lpLPTagAttribute != NULL) {
		parent = lpLPTagAttribute;
		lpLPTagAttribute = lpLPTagAttribute->getNext();
	}
	
	lpLPTagAttribute = new LPTagAttribute(attribute);
	if (parent != NULL) {
		parent->setNext(lpLPTagAttribute);
	} else {
		this->setAttribute(lpLPTagAttribute);
	}
}