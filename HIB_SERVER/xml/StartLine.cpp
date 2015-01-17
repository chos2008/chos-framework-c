
#include <string>
using namespace std;

#include "StartLine.h"

StartLine::StartLine()/* : version("1.0"), encoding("gb2312")*/ {
	//this("1.0", "gb2312");
	this->version = new string("1.0");
	this->encoding = new string("gb2312");
}

StartLine::StartLine(string* _version)/* : version(version), encoding("gb2312")*/ {
	//this(version, "gb2312");
	this->version = _version;
	this->encoding = new string("gb2312");
}

StartLine::StartLine(string* version, string* encoding) {
	this->version = version;
	this->encoding = encoding;
}

string StartLine::getVersion() {
	return *(this->version);
}

string StartLine::getEncoding() {
	return *(this->encoding);
}

/**
 *
 *
 *
 * <?xml version='1.0'?>
 *
 */
void StartLine::toStream(string* lpStream) {
	string stream = "<?xml ";
	stream = stream + "version=";
	stream = stream + "'";
	stream = stream + *(this->version);
	stream = stream + "'";
	stream = stream + "?>";
	*lpStream = stream;
	return;
}