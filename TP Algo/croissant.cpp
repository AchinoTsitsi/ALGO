#include <stdio.h>
int croissant(int n){
	if (n==1){
		printf("1");
	}else{
		croissant(n-1);
		printf("%d",n);
	}
}

int main(){
	int n;
	scanf("%d",&n);
	croissant(n);
	return 0;
}
