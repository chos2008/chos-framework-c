#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TString.h"


TString::TString(const char *s) 
{
	
	this->data = (char *) malloc(sizeof(char) * strlen(s));
	strcpy(this->data, s);
	

	// bad implementation!
	//this->data = (char *) s;
}

TString::TString(TString &s)
{
	this->data = (char *) malloc(sizeof(char) * strlen(s.data));
	strcpy(this->data, s.data);
}

TString& TString::operator=(const TString& s) 
{
	//this->data = (char *) malloc(sizeof(char) * strlen(s.data));
	//strcpy(this->data, s.data);

	this->data = s.data;
	return *this;
}

bool TString::operator ==(const TString &s)
{
	/*
	if (strcmp(this->data, s.data) == 0)
	{
		return true;
	}
	return false;
	*/
	return this->data == s.data;
}

void TString::print()
{
	printf("%s\n", this->data);
}
