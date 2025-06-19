#include <stdio.h>
#include <stdlib.h>

typedef struct element element;

typedef element* liste;

struct element {
    int val;
    liste next;
    liste prev;
};

int longeur(liste t){
	if(t==NULL){
		return 0;
	}else{
		return 1+longeur(t->next);
	}
}

void inverse(liste l,liste k){
	int temp;
	for(int i=0;i<longeur(l)/2;i++){
		temp=l->val;
		l->val=k->val;
		k->val=temp;
		l=l->next;
		k=k->prev;
	}
}

void pair(liste l){
	int n;
	for(liste a=l;a==NULL;a=a->next){
		for(liste b=a->next;b==NULL;b=b->next){
			if(a->val %2==0 && b->val%2!=0){
				// just swap using n
			}
		}
	}
}
