
#include "StartTag.h"

#ifndef TAG
#define TAG

class _declspec(dllexport) Tag : public StartTag {

protected:
	//string name; // --
	


public:

	/*
	 * Default constructs, used to construct a default tag 
	 * element <code>Tag</code> instance.
	 */
	Tag();

	/*
	 * Construct a tag element <code>Tag</code> instance with passed
	 * param name <code>name</code>
	 *
	 * @param name  The tag element <code>Tag</code> with name
	 */
	Tag(const string name);

	//Tag(const string name, const string c);

	/*
	 * The name of tag element <code>Tag</code> instance to set
	 *
	 * @param name  name of tag element
	 * @return  none
	 */
	void setTagName(const string name);

	/*
	 * The name of tag element @c Tag @c instance to get
	 *
	 * @return name of tag element.
	 */
	string getTagName();

	/*
	 * Output this tag element @c Tag @c to a characters stream
	 *
	 * @param lpStream string characters stream pointer, 
	 *    element characters streams would be output the 
	 *    target stream.
	 * @return none
	 */
	void toStream(string* lpStream);
};

#endif;