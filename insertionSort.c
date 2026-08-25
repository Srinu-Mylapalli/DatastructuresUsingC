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

/*
Time complexity: O(n^2) -worst case, O(n^2) -average case, O(n) -best case
Space complexity: O(1)

we iteratively insert each element of an unsorted list into its correct position in a sorted portion of the list.
*/
