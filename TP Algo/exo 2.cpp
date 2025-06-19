#include <stdio.h>

void reverse(int tab[],int start,int end){
	while(start<=end){
		int temp=tab[start];
		tab[start]=tab[end];
		tab[end]=temp;
		reverse(tab,start+1,end-1);
	}
}

int main()
{
	int tab[100];
	for(int i=0;i<5;i++){
		scanf("%d",&tab[i]);
	}
	reverse(tab,0,4);
	for(int i=0;i<5;i++){
		printf("%d ",tab[i]);
	}
	return 0;
}
