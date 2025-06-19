#include <stdio.h>
#include <stdlib.h>

void pointeur(){
	int* q;
	*q=4;
	printf("%d\n",q);
}

int main()
{
	int *t;
	t=(int *)malloc(sizeof(int));
	*t=5;
	printf("%d\n",*t);
	pointeur();
	return 0;
}
