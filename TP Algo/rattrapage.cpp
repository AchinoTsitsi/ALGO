#include <stdio.h>
#include <math.h>

int f(int a,int b){
	int r,z;
	r=0;
	z=1;
	while(a!=0){
		r=r+(a%10)*z;
		z=z*b;
		a=a/10;
	}
	return r;
}

int convert(int num,int base,int power){
	if(num==0){
		return 0;
	}else{
		return (num%10)*pow(base,power)+(num/10,base,power+1);
	}
}

int main()
{
	int a,b;
	printf("Entrer deux entiers positifs :\n");
	scanf("%d%d",&a,&b);
	printf("Le resultat est %d.\n",f(a,b));
	printf("Le resultat est %d.",convert(a,b,0));
	return 0;
}
