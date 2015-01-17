

#include <string>

using namespace std;

#include "Tag.h"
#include "SimpleTag.h"

SimpleTag::SimpleTag() {

}

SimpleTag::SimpleTag(const string name) {
	this->name = name;
}

SimpleTag::SimpleTag(const string name, const string cdata) {
	this->name = name;
	this->cdata = cdata;
}

void SimpleTag::setTagName(const string name) {
	this->name = name;
}

string SimpleTag::getTagName() {
	return this->name;
}

void SimpleTag::setCData(const string cdata) {
	this->cdata = cdata;
}

string SimpleTag::getCData() {
	return this->cdata;
}

void SimpleTag::toStream(string* lpStream) {
	Tag::toStream(lpStream);
	*lpStream = *lpStream + this->cdata;
	*lpStream = *lpStream + "</";
	*lpStream = *lpStream + this->name;
	*lpStream = *lpStream + ">";
	return;
}
