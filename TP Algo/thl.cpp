#include <stdio.h>
#include <string.h>

// Fonction pour vérifier si une chaîne appartient à L1
int isInL1(char *str) {
    int count_a = 0, count_b = 0;
    int i = 0;
    
    while (str[i] != '\0') {
        if (str[i] == 'a')
            count_a++;
        else if (str[i] == 'b')
            count_b++;
        else
            return 0; // caractère invalide
        
        if (count_a < count_b)
            return 0; // i < j n'est pas respecté
        
        i++;
    }
    
    return 1; // appartient à L1
}

// Fonction pour vérifier si une chaîne appartient à L2
int isInL2(char *str) {
    int i = 0;
    
    while (str[i] != '\0') {
        if (str[i] != 'a' && str[i] != 'b')
            return 0; // caractère invalide
        
        i++;
    }
    
    return 1; // appartient à L2
}

// Fonction pour vérifier si une chaîne appartient à L3
int isInL3(char *str) {
    if (strlen(str) <= 3)
        return 1; // longueur <= 3
    
    return 0; // longueur > 3
}

// Fonction pour vérifier si une chaîne appartient à L4
int isInL4(char *str) {
    int count_a = 0, count_b = 0;
    int i = 0;
    
    while (str[i] != '\0') {
        if (str[i] == 'a')
            count_a++;
        else if (str[i] == 'b')
            count_b++;
        else
            return 0; // caractère invalide
        
        i++;
    }
    
    if (count_a >= 2 && count_b >= 1)
        return 1; // i >= 2
    
    return 0; // i < 2 ou j < 1
}

// Fonction pour vérifier si une chaîne appartient à L5
int isInL5(char *str) {
    int count_a = 0, count_b = 0, count_c = 0;
    int i = 0;
    
    while (str[i] != '\0') {
        if (str[i] == 'a')
            count_a++;
        else if (str[i] == 'b')
            count_b++;
        else if (str[i] == 'c')
            count_c++;
        else
            return 0; // caractère invalide
        
        i++;
    }
    
    if (count_a >= 2 && count_b >= 2 && count_c == count_b)
        return 1; // i >= 2, j >= 0, et j == i
    
    return 0; // conditions non satisfaites
}

int main() {
    char words[][10] = {"", "a", "ab", "aa", "aaabb", "bba", "abba", "aba", "aabb", "abb"};
    int i;
    
    printf("Mots\t\tL1\tL2\tL3\tL4\tL5\n");
    
    for (i = 0; i < 10; i++) {
        printf("%s\t\t%d\t%d\t%d\t%d\t%d\n", words[i],
               isInL1(words[i]), isInL2(words[i]), isInL3(words[i]), isInL4(words[i]), isInL5(words[i]));
    }
    
    return 0;
}

