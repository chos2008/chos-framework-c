#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
	char msg[] = "Now is the time\n";
	char* cp;
	for(cp = msg; cp[0]; cp++)
	{
		printf("%c(%d)\n", cp[0], cp[0]);
	}

	char* p1 = msg;
	while (*p1) 
	{
		printf("%c(%d)\n", *p1, *p1);
		p1++;
	}
}