#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Element Element;

typedef Element* file;

struct Element{
	int val;
	file suivant;
};

bool est_vide(file f){
	return f==NULL;
}

int tete(file f){
	if(!est_vide(f)){
		return f->val;
	}
}

void enfiler(file *f,int v){
	if ((*f)== NULL){
		(*f) = (Element*)malloc(sizeof(Element));
		(*f)->val = v;
		(*f)->suivant = NULL;
	}else{
		enfiler(&((*f)->suivant),v);
	}
}

int defiler(file *f){
	if(!est_vide(*f)){
		file f1 = *f;
		int v = f1->val;
		*f = (*f)->suivant;
		free(f1);
		return v;	
	}
}

void afficher1(file *f) {
    file f1 = NULL;
    while (!est_vide(*f)) {
        int x = defiler(f);
        printf("%d\n", x);
        enfiler(&f1, x);
    }
    while (!est_vide(f1)) {
        int x = defiler(&f1);
        enfiler(f, x);
    }
}

void afficher(file f){
	while(f!=NULL){
		printf("%d\n",f->val);
		f=f->suivant;
	}
}

int main() {
    file f = NULL;

    enfiler(&f, 1);
    enfiler(&f, 2);
    enfiler(&f, 3);

    printf("Elements in the queue:\n");
    afficher(f);

    return 0;
}
