#include<stdio.h>
#include<stdlib.h>

typedef struct Element Element;

typedef Element* Liste;

struct Element {
    int val;
    Liste suivant;
};

typedef struct node node;

typedef node* pile;

struct node {
    int vale;
    pile next;
};

/*oid creation(Liste *t, int n) {
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
}*/

Liste creation(Liste* t,int i) {
	int n;
        *t = (Element*)malloc(sizeof(Element));
        Liste l = *t;
        
        printf("Enter element %d: ", i);
        scanf("%d", &l->val);
        printf("ajouter oui ou non:");
        scanf("%d",&n);

        if (n == 1) {
            l->suivant = creation(&(l->suivant), i + 1);   
        } else {
            l->suivant = NULL;
        }
        return *t;
}

void show(Liste t) {
    int i = 1;
    while (t != NULL) {
        printf("Le contenu de element %d : %d\n", i, t->val);
        t = t->suivant;
        i++;
    }
}

void sho(Liste t){
	if(t->suivant==NULL){
		printf("%d\n",t->val);
	}else{
		show(t->suivant);
		printf("%d",t->val);
	}
}

int longeur(Liste t){
	if(t==NULL){
		return 0;
	}else{
		return 1+longeur(t->suivant);
	}
}

int pair(Liste t) {
    int i = 0;
    while (t != NULL) {
        if(t->val%2==0){
        	i++;
        	t = t->suivant;
		}else{
        	t = t->suivant;
    }
    }
    return i;
}

void insertAt(Liste *t, int value, int position) {
    if (position < 1) {
        printf("Invalid position. Position should be greater than or equal to 1.\n");
        return;
    }

    Element *newElement = (Element*)malloc(sizeof(Element));
    newElement->val = value;

    if (position == 1) {
        newElement->suivant = *t;
        *t = newElement;
    } else {
        Element *current = *t;
        int i = 1;

        while (i < position - 1 && current != NULL) {
            current = current->suivant;
            i++;
        }

        if (current == NULL) {
            printf("Invalid position. Position exceeds the length of the list.\n");
            free(newElement);
            return;
        }

        newElement->suivant = current->suivant;
        current->suivant = newElement;
    }
}

void ajouter_debut(Liste *l,int n){
    	Liste nouveau=(Element*)malloc(sizeof(Element));
    	nouveau->val=n;
    	nouveau->suivant=*l;
    	*l=nouveau;
}

void ajouter_fin(Liste l,int n){
	Liste nouveau=(Element*)malloc(sizeof(Element));
	nouveau->val=n;
	while(l->suivant!=NULL){
		l=l->suivant;
	}
	l->suivant=nouveau;
	nouveau->suivant=NULL;
}

void ajouter_milieu(Liste *l,int n,int k){
	Liste p=(Element*)malloc(sizeof(Element));
	p->val=n;
	Liste q=*l;
	int pos=1;
	while (pos < k-1){
		q=q->suivant;
		pos++;
	}
	p->suivant=q->suivant;
	q->suivant=p;	
}

int min(Liste l){
	int min=l->val;
	while(l!=NULL){
		if(l->val<min){
			min=l->val;
		}
		l=l->suivant;
	}
	return min;
}

pile empiler(pile *p, int v) {
    pile q = (pile)malloc(sizeof(node));
    q->vale = v;
    q->next = *p;
    *p = q; 
    return q;
}

int depiler(pile *p){
	int v = (*p)->vale;
	pile q = *p;
	(*p) = (*p)->next;
	free(q);
	return v;
}

Liste inverse(Liste *l){
	Liste p,q,r;
	p=NULL;
	r=(*l);
	while(r != NULL){
		q=r;
		r=q->suivant;
		q->suivant=p;
		p=q;
	}
	return q;
}

Liste invers(Liste *l){
	pile p=NULL;
	Liste t=(*l);
	Liste r=(*l);
	while(t!=NULL){
		empiler(&p,t->val);
		t=t->suivant;
	}
	while(p!=NULL){
		r->val=depiler(&p);
		r=r->suivant;
	}
	return r;
}

void inv(Liste *l){
	Liste p=NULL,n=NULL;
	Liste current=(*l);
	while(current != NULL){
		n=current->suivant;
		current->suivant=p;
		p=current;
		current=n;
	}
	(*l)=p;
}

int main() {
    Liste tete;
    int n,position,new_data;
   // printf("Entrer le nombre d\'element de la liste : ");
   // scanf("%d",&n);
    creation(&tete,1);
    show(tete);
    printf("La longeur de la liste est %d\n",longeur(tete));
    printf("le nombre des valeurs pairs dans la liste est %d\n",pair(tete));
    //printf("enter a new value and a position for it :\n");
    //scanf("%d",&new_data);
    //insertAt(&tete,new_data,position);
    //ajouter_debut(&tete,8);
    //ajouter_fin(tete,7);
    //ajouter_milieu(&tete,6,2);
    //show(tete);
    //printf("%d",min(tete));
    //show(invers(&tete));
    invers(&tete);
    show(tete);
return 0;
}
