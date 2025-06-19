#include <stdio.h>

int maximum(int tab[],int index,int taille,int n){
	if(tab[index]>=n){
		n=tab[index];
	}
	maximum(tab,index+1,taille,n);
	return n;
}

int main(){
	int tab[100],n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&tab[i]);
	}
	printf("le max %d",maximum(tab,0,n,tab[0]));
	return 0;	
}
