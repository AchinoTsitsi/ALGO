#include <stdio.h>

int sommePositifs(int tableau[], int taille) {
    if (taille == 0) {
        return 0;
    }

    int sommeRestante = sommePositifs(tableau, taille - 1);
    if (tableau[taille - 1] > 0) {
        return tableau[taille - 1] + sommeRestante;
    } else {
        return sommeRestante;
    }
}

int main() {
    int tableau[100],taille;
    
    scanf("%d",&taille);
    
    for(int i=0;i<taille;i++){
    	scanf("%d",&tableau[i]);
	}

    int resultat = sommePositifs(tableau, taille);
    printf("La somme des éléments positifs du tableau est : %d\n", resultat);

    return 0;
}

