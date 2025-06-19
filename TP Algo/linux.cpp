#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Nombre de parametres : %d\n", argc - 1); // argc inclut le nom du programme lui-même
    for (int i = 1; i < argc; i++) {
        printf("Parametre %d : %s\n", i, argv[i]);
    }
    return 0;
}
