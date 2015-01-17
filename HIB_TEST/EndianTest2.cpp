#include <stdio.h>

void main()
{
	char s[10] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};

	//printf("%s\n", s);
	//printf("%s\n", s);
	
	short *ps = (short *) s;
	printf("sizeof(short): %d\n", sizeof(short));
	printf("%d(0x%x)\n", *ps, *ps);
	ps++;
	printf("%d(0x%x)\n", *ps, *ps);
	ps++;
	printf("%d(0x%x)\n", *ps, *ps);
	ps++;
	printf("%d(0x%x)\n", *ps, *ps);

	int *pi = (int *) s;
	printf("sizeof(int): %d\n", sizeof(int));
	printf("%d(0x%x)\n", *pi, *pi);
	pi++;
	printf("%d(0x%x)\n", *pi, *pi);
	pi++;
	printf("%d(0x%x)\n", *pi, *pi);
	pi++;
	printf("%d(0x%x)\n", *pi, *pi);

}
