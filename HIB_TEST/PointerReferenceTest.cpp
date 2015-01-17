#include <stdio.h>
void main()
{
	//int &r; // error C2530: 'r1' : references must be initialized
	//int &r = NULL; // error C2440: 'initializing' : cannot convert from 'const int' to 'int &'

	int *p;
	printf("%ld\n", &p);
	printf("%ld\n", p);
	//printf("%d\n", *p); // error, not read

	char* s = "abcdef";
	char *pc = s;
	printf("%c\n", *(++pc));

	int i = 1;
	int *p1 = &i;
	int &r1 = i;

	printf("Address of i: %ld, value of i: %d\n", &i, i);

	printf("Address of p1: %ld, value of p1: %d, value of p1 to point: %d\n", &p1, p1, *p1);

	printf("Address of r1: %ld, value of r1: %d\n", &r1, r1);

	int j = 2;
	r1 = j;
	printf("Address of j: %ld, value of j: %d\n", &j, j);
	printf("Address of r1: %ld, value of r1: %d\n", &r1, r1);
}