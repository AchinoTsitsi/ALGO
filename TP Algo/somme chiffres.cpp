#include <stdio.h>

int sommeChiffresRecursif(int nombre) {
    if (nombre == 0) {
        return 0;
    } else {
        return (nombre % 10) + sommeChiffresRecursif(nombre / 10);
    }
}

int main() {
    int nombre = 12345;
    int resultat = sommeChiffresRecursif(nombre);
    printf("La somme des chiffres de %d est %d\n", nombre, resultat);
    return 0;
}

