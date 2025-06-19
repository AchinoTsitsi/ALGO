#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Element Element;

typedef Element* pile;

struct Element{
	int val;
	pile suivant;
};

bool est_vide(pile p){
	return p==NULL;
}

char sommet(pile p){
	if(!est_vide(p)){
		return p->val;
	}
}

pile empiler(pile *p, char v) {
    pile q = (Element*)malloc(sizeof(Element));
    q->val = v;
    q->suivant = *p;
    *p = q; 
    return q;
}

int depiler(pile *p){
	if(!est_vide(*p)){
	int v = (*p)->val;
	pile q = *p;
	(*p) = (*p)->suivant;
	free(q);
	return v;
}
}

int main()
{
	pile p=NULL;
	empiler(&p,'s');
	empiler(&p,'f');
	empiler(&p,'e');
	printf("%c est le sommet",sommet(p));
	depiler(&p);
	printf("%c est le sommet",sommet(p));
	return 0;
	
}
