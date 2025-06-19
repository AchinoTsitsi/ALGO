#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct module{
	char matier[30];
	int confission;
	struct module* modulesuivant;
};

int main(){
	struct module*tete=NULL;
	
	tete=(struct module*)malloc(sizeof(struct module));
	
	struct module*ptr= tete;
	char reponse;
	
	do{
		printf("entrer le module:");
		scanf("%s",&ptr->matier);
		printf("entrer le confission:");
		scanf("%d",& ptr->confission);
		
		printf("vous volez entrer une autre matiere:");
		scanf("%c",&reponse);
		if(reponse=='y'){
			ptr->modulesuivant=(struct module*)malloc(sizeof(struct module));
			ptr=ptr->modulesuivant;
		}else{
			ptr->modulesuivant=NULL;
		}
	}while(reponse=='y');
	
	
	return 0;
}
