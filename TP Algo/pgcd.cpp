#include <stdio.h>

int pgcd(int a,int b){
	while(a!=b){
	if(a>b){
		return pgcd(a-b,b);
	}else{
		return pgcd(a,b-a);
	}}
	return a;
}

int main()
{
	printf("%d",pgcd(15,20));
	return 0;
}
