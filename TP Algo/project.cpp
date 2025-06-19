#include <stdio.h>
#include <stdbool.h>

int somme(int matrice[][100],int lignes,int colones,int base_lignes,int base_colones ) {

    if (lignes == base_lignes) {
        return 0;
    }

    if (colones == base_colones) {
        return somme(matrice, lignes, colones, base_lignes+1, 0);
    }

    int S= matrice[base_lignes][base_colones];
    return S+ somme(matrice, lignes, colones, base_lignes, base_colones+ 1);
}

bool recherche(int matrice[][100],int lignes,int colones,int base_lignes,int base_colones,int valeur) {

    if (lignes == base_lignes) {
        return false;
    }

    if (colones == base_colones) {
        return recherche(matrice, lignes, colones, base_lignes+1, 0,valeur);
    }

    if (matrice[base_lignes][base_colones]==valeur){
    	return true;
	}
	
	return recherche(matrice, lignes, colones, base_lignes, base_colones + 1, valeur);
}

int main(){
    int matrice[100][100],lignes, colones;

    printf("Entrer le nombre de lignes: ");
    scanf("%d", &lignes);
    printf("Entrer le nombre de colones: ");
    scanf("%d", &colones);
    
    printf("Entrer les elements de la matrice:\n");
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colones; j++) {
        	printf("Element [%d][%d]:",i,j);
            scanf("%d", &matrice[i][j]);
        }
    }

    int resultas = somme(matrice, lignes, colones, 0, 0);
    printf("La somme des elements de la matrice: %d\n", resultas);
    
    int valeur;
    printf("Entrer une valeur pour la rechercher : ");
    scanf("%d",&valeur);
    if(recherche(matrice, lignes, colones, 0, 0,valeur)==true){
    	printf("%d exicte dans la matrice.\n",valeur);
    }else{
    	printf("%d exicte pas dans la matrice.\n",valeur);
	}
		
    return 0;
}

