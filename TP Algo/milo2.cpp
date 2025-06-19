#include <stdio.h>

// Helper function to print the chain
void printChain(int chain[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", chain[i]);
    }
    printf("\n");
}

// Recursive function to find all combinations of 6 numbers in sorted order
void findChains(int arr[], int n, int chain[], int index, int start) {
    // If the chain contains 6 elements, print it
    if (index == 6) {
        printChain(chain, 6);
        return;
    }

    // Loop through the array to find combinations
    for (int i = start; i < n; i++) {
        chain[index] = arr[i];
        findChains(arr, n, chain, index + 1, i + 1);
    }
}

int main() {
    int arr[12]; // Array of 12 ordered integers
    int chain[6]; // To store each valid chain
    
    // Input: Fill the array with 12 integers
    printf("Enter 12 ordered integers: \n");
    for (int i = 0; i < 12; i++) {
        scanf("%d", &arr[i]);
    }

    // Find and print all chains of 6 ordered numbers
    findChains(arr, 12, chain, 0, 0);

    return 0;
}

