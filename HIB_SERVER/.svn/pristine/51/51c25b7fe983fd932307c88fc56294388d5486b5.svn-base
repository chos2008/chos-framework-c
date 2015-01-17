

#include "Tag.h"

#ifndef SIMPLE_TAG 
#define SIMPLE_TAG

class _declspec(dllexport) SimpleTag : public Tag {

private:
	string cdata;

public:

	SimpleTag();

	SimpleTag(const string name);

	SimpleTag(const string name, const string cdata);

	void setTagName(const string name);

	string getTagName();

	void setCData(const string cdata);

	string getCData();

	void toStream(string* lpStream);

};
#endif;