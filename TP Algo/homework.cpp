#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure de la pile
typedef struct {
    char *elements;
    int top;
} Pile;

// Initialiser une pile vide
void initPile(Pile *pile, int taille) {
    pile->elements = (char *)malloc(taille * sizeof(char));
    pile->top = -1;
}

// Empiler un caract�re sur la pile
void empiler(Pile *pile, char element) {
    pile->elements[++(pile->top)] = element;
}

// D�piler un caract�re de la pile
char depiler(Pile *pile) {
    if (pile->top >= 0) {
        return pile->elements[(pile->top)--];
    } else {
        fprintf(stderr, "La pile est vide.\n");
        exit(EXIT_FAILURE);
    }
}

// V�rifier si la pile est vide
int estVide(Pile *pile) {
    return pile->top == -1;
}

// Priorit� des op�rateurs
int priorite(char operateur) {
    switch (operateur) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// Traduire une expression en notation polonaise suffix�e
char *traduireEnNPS(char *expression) {
    int taille = strlen(expression) + 1;  // Taille de l'expression plus un pour le caract�re nul
    Pile pile_operateurs;
    Pile pile_resultat;

    initPile(&pile_operateurs, taille);
    initPile(&pile_resultat, taille);

    // Ajouter des parenth�ses pour simplifier le traitement
    char *expression_modifiee = (char *)malloc((taille + 2) * sizeof(char));
    strcpy(expression_modifiee, "(");
    strcat(expression_modifiee, expression);
    strcat(expression_modifiee, ")");

    for (int i = 0; i < taille + 2; i++) {
        char c = expression_modifiee[i];

        if (isdigit(c)) {
            // Si c est un nombre, l'ajouter au r�sultat
            empiler(&pile_resultat, c);
        } else if (c == '(') {
            // Si c est une parenth�se ouvrante, l'empiler
            empiler(&pile_operateurs, c);
        } else if (c == ')') {
            // Si c est une parenth�se fermante, d�piler jusqu'� la parenth�se ouvrante
            while (pile_operateurs.elements[pile_operateurs.top] != '(') {
                empiler(&pile_resultat, depiler(&pile_operateurs));
            }
            depiler(&pile_operateurs);  // D�piler la parenth�se ouvrante
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            // Si c est un op�rateur
            while (!estVide(&pile_operateurs) &&
                   priorite(pile_operateurs.elements[pile_operateurs.top]) >= priorite(c)) {
                empiler(&pile_resultat, depiler(&pile_operateurs));
            }
            empiler(&pile_operateurs, c);
        }
    }

    // Lib�rer la m�moire allou�e pour l'expression modifi�e
    free(expression_modifiee);

    // La pile_operateurs peut contenir des op�rateurs restants, les ajouter au r�sultat
    while (!estVide(&pile_operateurs)) {
        empiler(&pile_resultat, depiler(&pile_operateurs));
    }

    // Construire la cha�ne de caract�res r�sultat
    char *resultat = (char *)malloc((taille + 1) * sizeof(char));
    int index = 0;
    while (!estVide(&pile_resultat)) {
        resultat[index++] = depiler(&pile_resultat);
    }
    resultat[index] = '\0';

    // Inverser la cha�ne r�sultat, car elle a �t� empil�e � l'envers
    strrev(resultat);

    // Lib�rer la m�moire allou�e pour les piles
    free(pile_operateurs.elements);
    free(pile_resultat.elements);

    return resultat;
}

int main() {
    char expression[] = "5 * ( 2 - 8 ) + 12 / 4";
    char *expression_nps = traduireEnNPS(expression);

    printf("Expression en NPS : %s\n", expression_nps);

    // Lib�rer la m�moire allou�e pour l'expression en NPS
    free(expression_nps);

    return 0;
}

