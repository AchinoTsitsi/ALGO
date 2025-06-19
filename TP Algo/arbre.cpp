#include <stdio.h>
#include <stdlib.h>

// Structure d'un noeud de l'arbre binaire
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Fonction pour créer un nouveau noeud
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Fonction pour insérer une valeur dans l'arbre
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Fonction pour afficher les valeurs de l'arbre par ordre croissant
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Fonction pour calculer la taille de l'arbre
int treeSize(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        return treeSize(root->left) + 1 + treeSize(root->right);
    }
}

// Fonction pour calculer la somme des noeuds de l'arbre
int treeSum(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        return root->data + treeSum(root->left) + treeSum(root->right);
    }
}

// Fonction pour libérer la mémoire occupée par les noeuds de l'arbre
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct Node* root = NULL;
    int n, val;

    printf("Entrez le nombre d'éléments dans l'arbre : ");
    scanf("%d", &n);

    printf("Entrez les valeurs de l'arbre :\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Affichage par ordre croissant :\n");
    inorderTraversal(root);
    printf("\n");

    printf("Taille de l'arbre : %d\n", treeSize(root));
    printf("Somme des noeuds de l'arbre : %d\n", treeSum(root));

    // Libérer la mémoire occupée par les noeuds de l'arbre
    freeTree(root);

    return 0;
}


