#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

typedef struct element element;

typedef element* arbre;

struct element{
	int val;
	arbre left;
	arbre right;
};

arbre creation(int n) {
    arbre nouveau = (arbre)malloc(sizeof(element));
    nouveau->val = n;
    nouveau->left = nouveau->right = NULL;
    return nouveau;
}

arbre insert(arbre racine, int n) {
    if (racine == NULL) {
        return creation(n);
    }

    if (n < racine->val) {
        racine->left = insert(racine->left, n);
    } else if (n > racine->val) {
        racine->right = insert(racine->right, n);
    }

    return racine;
}

void affichage(arbre racine) {
    if (racine != NULL) {
        affichage(racine->left);
        printf("%d ", racine->val);
        affichage(racine->right);
    }
}

int taille(arbre racine){
	if (racine == NULL){
		return 0;
	}else{
		return taille(racine->left)+1+taille(racine->right);
	}
}

int pair(arbre racine,int x){
	if (racine == NULL){
		return 0;
	}else{
		if(racine->val%2==0){
			x=1;
		}
		return x+pair(racine->left,0)+pair(racine->right,0);
	}
}

int somme(arbre racine){
	if(racine == NULL){
		return 0;
	}else{
		return racine->val+somme(racine->left)+somme(racine->right);
	}
}

void liberter(arbre racine) {
    if (racine != NULL) {
        liberter(racine->left);
        liberter(racine->right);
        free(racine);
    }
}

int hauteur(arbre racine){
	if(racine==NULL){
		return 0;
	}else{
		int x=hauteur(racine->left);
		int y=hauteur(racine->right);
		if(x>=y){
			return x+1;
		}else{
			return y+1;
		}
	}
}

int min(arbre racine){
	while(racine->left!=NULL){
		racine=racine->left;
	}
	return racine->val;
}

void prefixe(arbre racine){
	if(racine==NULL){
		return;
	}
	prefixe(racine->left);
	prefixe(racine->right);
	printf("%d",racine->val);

}

bool search(arbre racine ,int v){
	if(racine==NULL){
		return false;
	}
	if(racine->val==v){
		return true;
	}
	return search(racine->left,v) || search(racine->right,v);
}

bool degenerer(arbre racine){
	if(racine->left!=NULL&&racine->right!=NULL){
		return false;
	}
	if(racine==NULL || (racine->left==NULL||racine->right==NULL) ){
		return true;
	}
	return degenerer(racine->left) && degenerer(racine->right);
}

int main ()
{
	arbre racine = NULL;
    int n, data;

    printf("Entrez le nombre d'éléments dans l'arbre : ");
    scanf("%d", &n);

    printf("Entrez les valeurs de l'arbre :\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        racine = insert(racine, data);
    }

    printf("Affichage par ordre croissant :\n");
	affichage(racine);
    printf("\n");
    
    printf("la taille est :%d\n",taille(racine));
    
    printf("la somme egale :%d\n",somme(racine));
    
    //liberter(racine);
    
    printf("la hauteur egale  :%d\n",hauteur(racine));
    
    printf("le min egale :%d\n",min(racine));
    
    prefixe(racine);
    
    bool a=search(racine,7);
    
    if(a==true){
    	printf("exicte");
	}else{
		printf("no");
	}
	
	bool b=search(racine,6);
	
    if(b==true){
    	printf("exicte");
	}else{
		printf("no");
	}
	
	bool c=degenerer(racine);
	
    if(c==true){
    	printf("de");
	}else{
		printf("node");
	}
	
	printf("%d",pair(racine,0));
    
    return 0;
	
}
