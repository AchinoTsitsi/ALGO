#include<stdio.h>
#include<stdlib.h>

int main()
{
	int tab[100];
	printf("Enter your numbers ordered and one by one because i am lazy: \n");
	for(int i = 0;i<12;i++){
		scanf("%d",&tab[i]);
	}
	 for (int i = 0; i <= 6; i++) {
        printf("Chain: ");
        for (int j = i; j < i + 6; j++) {
            printf("%d ", tab[j]);
        }
        printf("\n");
    }
	
}
