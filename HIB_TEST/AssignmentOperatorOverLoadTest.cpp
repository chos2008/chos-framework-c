#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#include "TString.h"


int main(int argc, char* argv[])
{
	/*
	TString s("hello, lxy!");
	s.print();

	TString *s2 = new TString("hello, lxy 2!");
	s2->print();

	TString s3(s);
	s3.print();

	TString *s4 = new TString(s);
	s4->print();


	TString s5("hello, lxy 3!");
	s5.print();

	s5 = s;
	s5.print();
	*/

	//
	//

	
	//TString *s2 = new TString("hello, lxy 2!");
	//s2->print();

	char *s = "hello, world!";
	char *ss = (char *) malloc(sizeof(char) * strlen(s));
	strcpy(ss, s);
	TString *s2 = new TString(ss);
	s2->print();
	
	ss[0] = 'H';
	s2->print();
	
	return 0;
}

