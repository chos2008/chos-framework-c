#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void main()
{
	int n = 1;
	printf("sizeof(int n): %d, sizeof(int): %d\n", sizeof(n), sizeof(int));

	printf("....................\n");

	int *p;
	printf("sizeof(int *p): %d, sizeof(int *): %d\n", sizeof(p), sizeof(int *));

	printf("....................\n");

	printf("p: %d\n", p);
	//printf("p: %d\n", *p); // ERROR

	printf("....................\n");

	p = &n;	
	printf("p: %d\n", p);
	printf("p: %d\n", *p);

	printf("....................\n");

	int *p2;
	printf("p2: %d\n", p2);
	//assert(p2 < 0);  //ERROR
	//printf("p2: %d\n", *p2); // ERROR
	//p2 = (int *) realloc(p2, 10 * sizeof(int)); // ERROR

	printf("....................\n");

	printf("p2: %d\n", p2);
	//printf("p2: %d\n", *p2); // ERROR

	printf("....................\n");

	p2 = (int *) calloc(10, sizeof(int));
	printf("p2: %d\n", p2);
	printf("p2: %d\n", *p2);
	
	printf("....................\n");

	p2 = (int *) realloc(p2, 10 * sizeof(int));
	printf("p2: %d\n", p2);
	printf("p2: %d\n", *p2);

	printf("....................\n");
	*p2 = 8899;
	p2 = (int *) realloc(p2, 10 * sizeof(int));
	printf("p2: %d\n", p2);
	printf("p2: %d\n", *p2);

}