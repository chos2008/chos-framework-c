#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i;
	int *pn=(int *)malloc(5*sizeof(int));
	printf("%p\n",pn);
	printf("%d\n", sizeof(*pn));

	for(i=0;i<5;i++)
		scanf("%d",&pn[i]);
	
	pn=(int *)realloc(pn,10*sizeof(int));
	printf("%p\n",pn);
	
	for(i=0;i<5;i++)
		printf("%3d",pn[i]);
	printf("\n");
	free(pn);
	return 0;
}