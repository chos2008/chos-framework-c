


#include "Tag.h"
#include "ChildTag.h"

class _declspec(dllexport) ComplexTag : public Tag {
	
private:

	ChildTag children;

public:

	ComplexTag();

	ComplexTag(const string name);

	ComplexTag(const string name, Tag tag);

	ComplexTag(const string name, ChildTag children);

	void setTagName(const string name);

	string getTagName();

	void setChildTags(ChildTag children);

	void setChildren(ChildTag children);
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
};