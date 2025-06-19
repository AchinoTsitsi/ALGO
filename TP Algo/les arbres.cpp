#include <stdio.h>
#include <stdlib.h>

typedef struct element element;

typedef element* arbre;

struct element{
	int val;
	arbre right;
	arbre left;
};

arbre creation(int n){
	arbre p = (arbre)malloc(sizeof(element));
	p->val=n;
	p->right=NULL;
	p->left=NULL;
	return p;
}

void affichage(arbre p){//croissant we start with right then left for the reverse
	if(p!=NULL){
		affichage(p->left);
		printf("%d",p->val);
		affichage(p->right);
	}
}
