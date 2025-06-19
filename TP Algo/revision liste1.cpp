#include<stdio.h>
#include<stdlib.h>

typedef struct element element;

typedef element* list;

struct element{
	int val;
	list next;
};

list creation(list *head,int n){
	*head=(list)malloc(sizeof(element));
	list current=*head;
	int i=1;
	do{
		printf("Enter the element %d : ",i);
		scanf("%d",&current->val);
		if(n>1){
			current->next=(list)malloc(sizeof(element));
			current=current->next;
		}
		n--;
		i++;	
	}while(n>=1);
	current->next=NULL;
	return *head;
}

void show(list head){
	int i=1;
	while(head!=NULL){
		printf("Element %d : %d\n",i,head->val);
		head=head->next;
		i++;
	}
}

int lenght(list head){
	int i=0;
	while(head!=NULL){
		i++;
		head=head->next;
	}
	return i;
}

void ajouter_fin(list l,int n){
	list nouveau=(list)malloc(sizeof(element));
	nouveau->val=n;
	while(l->next!=NULL){
		l=l->next;
	}
	l->next=nouveau;
	nouveau->next=NULL;
}

list ajouter(list *head,int data,int position){
	if(position==1){
		list nv=(list)malloc(sizeof(element));
		nv->val=data;
		nv->next=*head;
		*head=nv;
	}else if(position<lenght(*head)){
		list nv=(list)malloc(sizeof(element));
		nv->val=data;
		list current = *head;
        int i = 1;

        while (i < position - 1 && current != NULL) {
            current = current->next;
            i++;
        }
        
        nv->next = current->next;
        current->next = nv;
	}else if(position==lenght(*head)){
		ajouter_fin(*head,data);
	}	
}

void supprimer(list *head){
	list current=*head;
	*head=(*head)->next;
	free(current);
}

void supprimer_fin(list *head){
	if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    list current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    list lastNode = current->next;
    current->next = NULL;
    free(lastNode);
}

int search(list l ,int n){
	int i=0;
	while(l!=NULL){
		if(l->val==n){
			i++;
		}
	}
	return i;
}

void fuse(list *l1,list *l2){
	list temp=*l1;
	if(temp==NULL){
		temp=(*l1);
	}else{
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=(*l2);
	}
}

int main(){
	int taille;
	list head,head2;
	printf("Enter the lenght of the list : ");
	scanf("%d",&taille);
	creation(&head,taille);
	creation(&head2,taille);
	//show(head);
	//ajouter(&head,5,4);
	//show(head);
	//supprimer(&head);
	//supprimer_fin(&head);
	fuse(&head,&head2);
	show(head);
	return 0;
}
