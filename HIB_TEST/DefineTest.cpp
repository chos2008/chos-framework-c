#include <stdio.h>

#define PI 3.14159265
//#define BI "aa"

void main()
{

#if AI < 0
	printf("AI < 0\n");
#elif AI > 0
	printf("AI > 0\n");
#elif AI == 0
	printf("AI == 0\n");
#endif;

	float f = 1.2f;

#if strcmp(BI, "bb") == 0
	printf("strcmp(BI, \"bb\") == 0\n");
#elif strcmp(BI, "bb") != 0
	printf("strcmp(BI, \"bb\") != 0\n");
#endif;

	printf("PI: %lf\n", PI);
}