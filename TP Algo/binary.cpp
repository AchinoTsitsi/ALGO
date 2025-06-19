#include <stdio.h>

int binary(int n){
	if(n==0){
		return 0;
	}else{
		return n%2+10*binary(n/2);
	}
}

int main(){
	int n;
	scanf("%d",&n);
	printf("%d",binary(n));
	return 0;
}
