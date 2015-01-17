#include <stdio.h>

class ClassConstructor {

private: 
	int ii;
	char * ss;

public:
	ClassConstructor();

	ClassConstructor(int i);

	ClassConstructor(int i, char* s);
};

ClassConstructor::ClassConstructor() {
    printf("default\n");
}

ClassConstructor::ClassConstructor(int i)/* : ClassConstructor() */{
	printf("int i = %d\n", ii);
}

ClassConstructor::ClassConstructor(int i, char* s)/* : ClassConstructor(i) */{
	printf("int i = %d, char* s = %s\n", ii, ss);
}

void main() {
    printf("aaaaa\n");

	ClassConstructor cc(1);
}