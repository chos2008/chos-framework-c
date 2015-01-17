#include <stdio.h>
#include <stdio.h>

#pragma pack(8)

struct a1 
{
	char a;
	int b;
	char c;
};

struct a2
{
	int a;
	char b;
	char c;
};

//
//
struct a3 
{
	bool a;
	int b;
	bool c;
};

struct a4
{
	int a;
	bool b;
	bool c;
};  


int t(int n) 
{
	int count = 0;
	while (n) 
	{
		count++;
		n = n & (n - 1);
	}
	return count;
}

int main(void)
{
	/*
	int m = t(3);
	printf("i=%d, ret: %d\n", 3, m);

	for (int i = 0; i < 100; i++) 
	{
		printf("i=%d, ret: %d\n", i, t(i));
	}
	*/

	
	//printf("%lf\n", 5.0 % 2); // error C2296: '%' : illegal, left operand has type 'const double'
	//float f = 5.0;
	//printf("%lf\n", f % 2); // error C2296: '%' : illegal, left operand has type 'float'
	//double d = 5.0;
	//printf("%lf\n", d % 2); // error C2296: '%' : illegal, left operand has type 'double'

	
	printf("%d\n", 5 % 2);
	printf("%f\n", 5 % 2);
	printf("%lf\n", 5 % 2);

	printf("------------------------\n");
	
	printf("%d\n", 5 / 2);
	printf("%f\n", 5 / 2);
	printf("%lf\n", 5 / 2);

	printf("------------------------\n");


	printf("%d\n", ((double) 5) / 2);
	printf("%d\n", ((float) 5) / 2);
	printf("%f\n", ((double) 5) / 2);
	printf("%f\n", ((float) 5) / 2);
	printf("%lf\n", ((double) 5) / 2);
	printf("%lf\n", ((float) 5) / 2);

	printf("------------------------\n");
	//
	//
	//
	struct a1 _a1;
	printf("addr _a1: %d, a: %d, b: %d, c: %d\n", &_a1, &_a1.a, &_a1.b, &_a1.c);
    
	printf("sizeof(int): %d, sizeof(a1): %d, sizeof(a2): %d\n", sizeof(int), sizeof(struct a1), sizeof(struct a2));
    
	
	struct a2 _a2;
	printf("addr _a2: %d, a: %d, b: %d, c: %d\n", &_a2, &_a2.a, &_a2.b, &_a2.c);

	printf("sizeof(int): %d, sizeof(a3): %d, sizeof(a4): %d\n", sizeof(int), sizeof(struct a3), sizeof(struct a4));
    
	return 0;
}