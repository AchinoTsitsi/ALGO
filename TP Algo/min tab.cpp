#include<stdio.h>
#include<stdlib.h>

int min(tab[],int i,int n){
	while(tab[i]!=NULL){
		if(tab[i]<n){
			int min=tab[i];
		}
		min(tab,i+1,min);
	}
	return min;
}

int main(){
	int tab=[1,2,3,4,5];
	printf("%d",min(tab,0,1));
	return 0;
}
