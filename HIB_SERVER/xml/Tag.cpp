#include <string>
using namespace std;

#include "StartTag.h"
#include "Tag.h"


Tag::Tag() {
	
}

Tag::Tag(const string name) {
	this->name = name;
}

	//Tag(const string name, const string c);

void Tag::setTagName(const string name) {
	this->name = name;
}

string Tag::getTagName() {
	return this->name;
}

void Tag::toStream(string* lpStream) {
	/*
	string stream = StartTag::toStream();
	stream = stream + "</";
	stream = stream + this->name;
	stream = stream + ">";
	return stream;
	*/
	StartTag::toStream(lpStream);
	return;
}