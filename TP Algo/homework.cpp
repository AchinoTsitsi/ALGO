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

// Empiler un caractère sur la pile
void empiler(Pile *pile, char element) {
    pile->elements[++(pile->top)] = element;
}

// Dépiler un caractère de la pile
char depiler(Pile *pile) {
    if (pile->top >= 0) {
        return pile->elements[(pile->top)--];
    } else {
        fprintf(stderr, "La pile est vide.\n");
        exit(EXIT_FAILURE);
    }
}

// Vérifier si la pile est vide
int estVide(Pile *pile) {
    return pile->top == -1;
}

// Priorité des opérateurs
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

// Traduire une expression en notation polonaise suffixée
char *traduireEnNPS(char *expression) {
    int taille = strlen(expression) + 1;  // Taille de l'expression plus un pour le caractère nul
    Pile pile_operateurs;
    Pile pile_resultat;

    initPile(&pile_operateurs, taille);
    initPile(&pile_resultat, taille);

    // Ajouter des parenthèses pour simplifier le traitement
    char *expression_modifiee = (char *)malloc((taille + 2) * sizeof(char));
    strcpy(expression_modifiee, "(");
    strcat(expression_modifiee, expression);
    strcat(expression_modifiee, ")");

    for (int i = 0; i < taille + 2; i++) {
        char c = expression_modifiee[i];

        if (isdigit(c)) {
            // Si c est un nombre, l'ajouter au résultat
            empiler(&pile_resultat, c);
        } else if (c == '(') {
            // Si c est une parenthèse ouvrante, l'empiler
            empiler(&pile_operateurs, c);
        } else if (c == ')') {
            // Si c est une parenthèse fermante, dépiler jusqu'à la parenthèse ouvrante
            while (pile_operateurs.elements[pile_operateurs.top] != '(') {
                empiler(&pile_resultat, depiler(&pile_operateurs));
            }
            depiler(&pile_operateurs);  // Dépiler la parenthèse ouvrante
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            // Si c est un opérateur
            while (!estVide(&pile_operateurs) &&
                   priorite(pile_operateurs.elements[pile_operateurs.top]) >= priorite(c)) {
                empiler(&pile_resultat, depiler(&pile_operateurs));
            }
            empiler(&pile_operateurs, c);
        }
    }

    // Libérer la mémoire allouée pour l'expression modifiée
    free(expression_modifiee);

    // La pile_operateurs peut contenir des opérateurs restants, les ajouter au résultat
    while (!estVide(&pile_operateurs)) {
        empiler(&pile_resultat, depiler(&pile_operateurs));
    }

    // Construire la chaîne de caractères résultat
    char *resultat = (char *)malloc((taille + 1) * sizeof(char));
    int index = 0;
    while (!estVide(&pile_resultat)) {
        resultat[index++] = depiler(&pile_resultat);
    }
    resultat[index] = '\0';

    // Inverser la chaîne résultat, car elle a été empilée à l'envers
    strrev(resultat);

    // Libérer la mémoire allouée pour les piles
    free(pile_operateurs.elements);
    free(pile_resultat.elements);

    return resultat;
}

int main() {
    char expression[] = "5 * ( 2 - 8 ) + 12 / 4";
    char *expression_nps = traduireEnNPS(expression);

    printf("Expression en NPS : %s\n", expression_nps);

    // Libérer la mémoire allouée pour l'expression en NPS
    free(expression_nps);

    return 0;
}

