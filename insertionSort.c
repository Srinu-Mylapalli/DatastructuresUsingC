#include <stdio.h>

void insertionSort(int A[], int n);

int main() {
    int A[] = {16,19,42,40,56}, n = 5;

    insertionSort(A, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}


void insertionSort(int A[], int n) {
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = A[i];
        j = i - 1;

        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j = j - 1;
        }

        A[j + 1] = key;
    }
}
