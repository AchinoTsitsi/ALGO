#include <stdio.h>

#define N 24
#define R 12

void printCombination(int arr[], int n, int r, int index, int data[], int i, int *count) {
    if (index == r) {
        printf("%d: ", (*count)++);
        for (int j = 0; j < r; j++) {
            printf("%d ", data[j]);
        }
        printf("\n");
        return;
    }

    if (i >= n) {
        return;
    }

    data[index] = arr[i];
    printCombination(arr, n, r, index + 1, data, i + 1, count);

    printCombination(arr, n, r, index, data, i + 1, count);
}

void generateCombinations(int arr[], int n, int r) {
    int data[r];
    int count = 1;
    printCombination(arr, n, r, 0, data, 0, &count);
}

int main() {
    int arr[N];

    printf("Enter 24 integers:\n");
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    printf("All combinations of 12 numbers from the list:\n");
    generateCombinations(arr, N, R);

    return 0;
}

