#include<stdio.h>
#include<stdlib.h>

typedef struct Element Element;

struct Element {
    int val;
    Element *suivant;
};

typedef Element* Liste;

void creation(Liste *t, int n) {
	if(n==0){
		printf("La liste est vide");
	}else{
    *t = (Element*)malloc(sizeof(Element));
    Liste l = *t;
    int i = 1;
    while (n > 0) {
        printf("Enter element %d : ", i);
        scanf("%d", &l->val);
        if (n > 1) {
            l->suivant = (Element*)malloc(sizeof(Element));
            l = l->suivant;
        } else {
            l->suivant = NULL;
        }
        n--;
        i++;
    }}
}

void show(Liste t) {
    int i = 1;
    while (t != NULL) {
        printf("Le contenu de element %d : %d\n", i, t->val);
        t = t->suivant;
        i++;
    }
}

void croissant(Liste l){
	while(l!=NULL){
		Liste current=l;
		int min=l->val;
		while(current!=NULL){
			if(current->val<min)
			min=current->val;
			current=current->suivant;
		}
		l=l->suivant;
	}
}

int main() {
    Liste tete;
    int n,position,new_data;
    printf("Entrer le nombre d\'element de la liste : ");
    scanf("%d",&n);
    creation(&tete,n);
    show(tete);
    croissant(tete);
    show(tete);
return 0;
}
