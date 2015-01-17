#include <stdio.h>

double div(int x, int y)
{

	if (y == 0)
	{
		throw y;
	}

	return x/y;
}

void main()
{
	int x = 10;
	int y = 5;

	double z = 0;
	
	try 
	{
		z = div(x, y);
		printf("z=%lf\n", z);
	
		y = 3;
		z = div(x, y);
		printf("z=%lf\n", z);
	
		y = 0;
		z = div(x, y);
		printf("z=%lf\n", z);
	}
	catch(int)
	{
		printf("%s %s, %s, %s, %s, line:%d, Illegal argument: %d\n", __DATE__, __TIME__, __FILE__, "__FUNCTION__", "__func__", __LINE__, y);
	}
}