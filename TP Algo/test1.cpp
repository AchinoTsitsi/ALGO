#include<stdio.h>

int fac(int n){
	if(n==1){
		return 1;
	}else{
		return n*fac(n-1);
	}
}

int sn(int n){
	if(n==1){
		return 1;
	}else if(n%2==0){
		return sn(n-1)-fac(n);
	}else{
		return sn(n-1)+fac(n);
	}
}

int main(){
	printf("%d",sn(5));
	return 0;
}
