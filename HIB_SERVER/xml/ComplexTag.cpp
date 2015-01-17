
#include <string>

using namespace std;

#include "Tag.h"
#include "ChildTag.h"
#include "ComplexTag.h"


ComplexTag::ComplexTag() {

}

ComplexTag::ComplexTag(const string name) {

}

ComplexTag::ComplexTag(const string name, Tag tag) {

}

ComplexTag::ComplexTag(const string name, ChildTag children) {
	
}

void ComplexTag::setTagName(const string name) {

}

string ComplexTag::getTagName() {
	return NULL;
}

void ComplexTag::setChildTags(ChildTag children) {

}

void ComplexTag::setChildren(ChildTag children) {

}

/*
	ChildTag getChildTags();

	ChildTag getChildren();

	void setChildTags(Tag* children);

	void setChildTags(Tag[] children);

	void appendChild(const Tag* child);
	
	void insertChild(const Tag* child);

	void insertChild(const Tag* child, const Tag* beforeChild);

	void insertChild(const Tag* child, int offset);

	void setChildren(Tag* children);

	void setChildren(Tag[] children);


	Tag* getChildren();

	Tag[] getChildren();
*/
