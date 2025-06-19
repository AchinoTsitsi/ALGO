#include<stdio.h>
#include<stdlib.h>

typedef struct element element;

typedef element* liste;

typedef struct bliste bliste;

struct element{
	int val;
	liste next;
	liste prev;
};

struct bliste{
	liste start;
	liste end;
};

bliste creation(){
	bliste l;
	liste p,q;
	int rep;
	p=(element*)malloc(sizeof(element));
	p->prev=NULL;
	l.start=p;
	do{
		scanf("%d",p->val);
		scanf("%d",rep);
		if(rep==0){
			p->next=NULL;
			l.end=p;
		}else{
			q=(element*)malloc(sizeof(element));
			p->next=q;
			q->prev=p;
			p=q;
		}
	}while(rep!=0);
	return l;
}

void affichage(bliste l){
	liste p=l.start;
	while(p!=NULL){
		printf("%d\n",p->val);
		p=p->next;
	}
}

void affichage_rec(liste l){
	while(l!=NULL){
		printf("%d\n",l->val);
		affichage_rec(l->next);
	}
}

void affichage_invers(bliste l){
	liste p=l.end;
	while(p!=NULL){
		printf("%d\n",p->val);
		p=p->prev;
	}
}

void insertAt(bliste l,int value, int position) {
    liste newElement = (element*)malloc(sizeof(element));
    newElement->val = value;

    if (position == 1) {
        newElement->next = l.start;
        newElement->prev = NULL;

        if (l.start != NULL) {
            l.start->prev = newElement;
        }

        l.start = newElement;
    } else {
        liste current = l.start;
        int i = 1;

        while (i < position - 1 && current != NULL) {
            current = current->next;
            i++;
        }

        if (current == NULL) {
            printf("Invalid position. Position exceeds the length of the list.\n");
            free(newElement);
            return;
        }
		newElement->next = current->next;
        newElement->prev = current;

        if (current->next != NULL) {
            current->next->prev = newElement;
        }

        current->next = newElement;
    }
}

int main(){
	creation();
	return 0;
}

