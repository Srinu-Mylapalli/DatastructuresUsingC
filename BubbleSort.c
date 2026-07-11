#include <stdio.h>

void bubbleSort(int A[], int n);

int main() {
    int A[] = {1,2,3,4,5}, n = 5;

    bubbleSort(A, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}

void bubbleSort(int A[], int n) {
    int i, j;

    for (i = 0; i < n - 1; i++) {
        int flag = 0;

        for (j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                flag = 1;
            }
        }

        if (flag == 0) {
            break;
        }
    }
}
