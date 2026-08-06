#include <stdio.h>
                                                                             void selectionSort(int A[], int n);

int main() {
    int A[] = {100,25,36,44,15}, n = 5;
                                                                                 selectionSort(A, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }                                                                        
    return 0;
}

                                                                             
void selectionSort(int A[], int n) {
    int i, j, min;

    for (i = 0; i < n - 1; i++) {                                                    min = i;

        for (j = i + 1; j <= n - 1; j++) {
            if (A[min] > A[j]) {
                min = j;                                                                 }
        }

        if (min != i) {
            int temp = A[min];                                                           A[min] = A[i];
            A[i] = temp;
        }
    }
}
