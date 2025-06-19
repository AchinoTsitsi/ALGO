#include <stdio.h>
int croissant(int n){
	if (n==1){
		printf("1");
	}else{
		printf("%d",n);
		croissant(n-1);
	}
}

int main(){
	int n;
	scanf("%d",&n);
	croissant(n);
	return 0;
}
