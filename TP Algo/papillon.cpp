#include<stdio.h>

int papillon(int n){
	if(n==0){
		return 150;
	}else{
		return papillon(n-1)-(papillon(n-1)*0.2)+50;
		
	}
}

int haliston(int n,int taille){
	
	if(n==1){
		printf("%d",1);
		return taille+1;
	}else{
		printf("%d ",n);
		if(n%2==0){
			haliston(n/2,taille+1);
		}else{
			haliston(3*n+1,taille+1);
		}
}
}

int main()
{

	//printf("%d",papillon(1));
	printf("\n%d",haliston(5,0));
	return 0;
}
