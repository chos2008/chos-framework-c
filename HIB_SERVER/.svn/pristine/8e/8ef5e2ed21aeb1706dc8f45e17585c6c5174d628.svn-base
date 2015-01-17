/*
 * DOCUMENT!
 *
 * @author a.da
 * @since 1.0
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ernie.h"



int random_select_with_seed(int n, int seed)
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


int random_select(int n) 
{
	int seed = time(NULL);
	return random_select_with_seed(n, seed);
}

int random_select_t(int n) 
{
	/*
	static seed = time(NULL);
	int s = rand_select_with_seed(n, seed);
	seed++;
	return s;
	*/
	return 1;
}