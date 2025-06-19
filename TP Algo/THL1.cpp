#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool inL1(char *mot){
	int i=0,j=0,current=0;
	while(mot [current] != '\0'){
		if(mot[current] == 'a') i++; 
		else if(mot[current] == 'b') j++;
		else return false;
		if(mot[current] == 'b' && mot[current+1] == 'a') return false;
		current++;	
	}
	return i>=j;
}

bool inL2(char *mot){
	int i=0,j=0,current=0;
	while(mot [current] != '\0'){
		if(mot[current ]== 'a') i++; 
		else if(mot[current] == 'b') j++;
		else return false;
		current++;	
	}
	return i>0 && j>0;
}

bool inL3(char *mot){
	int i=0,j=0,current=0;
	while(mot [current] != '\0'){
		if(mot[current]=='a') i++;
		else if (mot[current]=='b') j++;
		else return false;
		current++;	
	}
	return i>0 && j>0 && current<=3;
}

bool inL4(char *mot){
	int i=0,current=0;
	while(mot [current] != '\0'){
		if(mot[current] == 'a') i++; 
		if(mot[current] != 'a' && mot[current] != 'b' ) return false;
		if(mot[current] == 'b' && mot[current+1] == 'a') return false;
		current++;	
	}
	return i>=2;
}

bool inL5(char *mot){
	int i=0,j=0,k=0,current=0;
	while(mot [current] != '\0'){
		if(mot[current]=='a') i++; 
		else if(mot[current]=='b') j++;
		else if(mot[current]=='c') k++;
		else return false;
		if(mot[current]=='b'&&mot[current+1]=='a' || mot[current]=='c'&&mot[current+1]=='a' || mot[current]=='c'&&mot[current+1]=='b' ) return false;
		current++;	
	}
	return i>=2 && i==k;
}

int main(){
	char mot[100];
	scanf("%s",mot);
	if(inL4(mot) == true) printf("appartient");
	else printf("appartient pas");
}
