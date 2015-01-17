
#include <string>
using namespace std;

#include "Attribute.h"

Attribute::Attribute() {
	
}

Attribute::Attribute(const string name, const string value) {
	this->name = name;
	this->value = value;
}

/*
int Attribute::operator ==(Attribute attribute) {
	const char* lpName = this->name.c_str();
	const char* lpValue = this->value.c_str();
	const char* _lpName = attribute.getAttributeName().c_str();
	const char* _lpValue = attribute.getAttributeValue().c_str();
	// strcmp, ����Ƚϵ������ַ�����ȣ� ��strcmp�Ľ��Ϊ0
	int r = strcmp(lpName, _lpName);
	int _r = strcmp(lpValue, _lpValue);
	// ��� r & _r ��Ϊ0�Ļ��� ����ȡ�
	return !(r + _r);
}

int Attribute::operator !=(Attribute attribute) {
	if (this == &attribute) {
		return 0;
	}
	return 1;
}
*/

void Attribute::setAttributeName(const string name) {
	this->name = name;
}

string Attribute::getAttributeName() {
	return this->name;
}

void Attribute::setAttributeValue(const string value) {
	this->value = value;
}

string Attribute::getAttributeValue() {
	return this->value;
}
