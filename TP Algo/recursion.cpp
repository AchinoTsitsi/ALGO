#include <stdio.h>

int convbase10(int n,int base){
	if (n==0){
		return 0;
	}else{
		int x=n%10;
		return x+convbase10(n/10,base)*base;
	}
}

int main(){
	printf("%d",convbase10(100,16));
	return 0;
}
