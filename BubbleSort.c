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

/*
Time complexity: O(n^2) -worst, O(n^2) -average, O(n) -best -the best case occurs when the array is already sorted.
Space complexity: O(1)
*/

/*
process:
1.compare: Start at index 0 and compare the first two adjacent elements.
2.swap: If the first element is larger than the second, swap them. If not, do nothing.
3.move: Move to the next adjacent pair (index 1 and 2) and repeat.
4.Repeat: Continue until the end of the array. By the end of this first "pass," the largest number will have migrated to the absolute end.
5.loop: Repeat the entire process for the remaining unsorted elements until no more swaps are needed.
*/

/*
the sorting here is done on the basis of the largest to the smallest element.
The largest element is first kept in the last location in the array. Then the second largest element in the second last location as so on.
simply, it bubbles the largest element into correct & sorted order.
*/
