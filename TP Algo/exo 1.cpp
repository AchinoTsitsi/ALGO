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

/*void croissant(Liste l) {
    int temp;
    Liste current, index;

    for (index = l; index != NULL; index = index->suivant) {
        for (current = index->suivant; current != NULL; current = current->suivant) {
            if (index->val > current->val) {
                temp = index->val;
                index->val = current->val;
                current->val = temp;
            }
        }
    }
}*/
void croissant(Liste l) {
    if (l == NULL) {
        return; // Base case: empty list
    }

    Liste current = l->suivant;
    while (current != NULL) {
        if (l->val > current->val) {
            // Swap values
            int temp = l->val;
            l->val = current->val;
            current->val = temp;
        }
        current = current->suivant;
    }

    // Recursively call the function for the next element in the list
    croissant(l->suivant);
}

Liste reverse(Liste current, Liste prev) {
    if (current == NULL) {
        return prev; // Return the new head of the reversed list
    }

    Liste next = current->suivant;
    current->suivant = prev;

    // Recursive call for the rest of the list
    return reverse(next, current);
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
    tete=reverse(tete,NULL);
    show(tete);
return 0;
}
