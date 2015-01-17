#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int rand_select_with_seed(int n, int seed)
{
	int i, random, s = 0;
	float p = ((float) 100) / n;
	float temp = 0.0;

	//srand(time(NULL));
	srand(seed);
	
	random = rand() % 100;
	
	//printf("p=%f\n", p);
	for (i = 0; i < n; i++)
	{
		if (random <= temp) 
		{
			s = i;
			break;
		}
		//printf("%f\t", temp);
		temp += p;
	}
	/*
	if (i >= n)
	{
		printf("\n******************************\n");
	}
	*/
	return s;
}


int rand_select(int n) 
{
	int t = time(NULL);
	return rand_select_with_seed(n, t);
}

void main()
{
	int i;

	printf("\n-----------------------\n");
	for (i = 1; i <= 50; i++) 
	{
		int s = rand_select_with_seed(10, i);
		printf("%d ", s);
	}
	printf("\n-----------------------\n");


	printf("Maximum value returned by rand: %d\n", RAND_MAX);
	printf("RAND_MAX % 100: %d\n", RAND_MAX % 100);

	//srand(rand());
	srand(time(NULL));
	for (i = 0; i < 10; i++)
	{
		int random = rand();
		printf("%d\t", random);
	}
	printf("\n");

	for (i = 0; i < 10; i++)
	{
		int random = rand();
		printf("%d\t", random);
	}
	printf("\n");

	for (i = 0; i < 10; i++)
	{
		int random = rand() % 100;
		printf("%d\t", random);
	}
	printf("\n");

}