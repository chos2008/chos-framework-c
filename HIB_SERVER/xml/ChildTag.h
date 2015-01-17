
#include "Tag.h"

#ifndef CHILD_TAG 
#define CHILD_TAG

class _declspec(dllexport) ChildTag {

private:
	Tag tag;

public:

	ChildTag();

	ChildTag(Tag tag);

	void setTag(Tag tag);

	Tag getTag();
};

#endif;