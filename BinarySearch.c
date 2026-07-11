#include <stdio.h>                                                      #include <math.h>                                                       
int binarySearch(int A[], int n, int key);
                                                                        int main() {                                                                int A[] = {10,20,30,40,50,60,70}, n = 7, key = 70;                  
    int r = binarySearch(A, n, key);

    if (r == -1)
        printf("unsuccessful");
    else                                                                        printf("successful at index %d", r);                                                                                                        return 0;                                                           }                                                                                                                                               int binarySearch(int A[], int n, int key) {                                 int start = 0;                                                          int end = n - 1;

    while (start <= end) {                                                      int mid = (start + end) / 2;

        if (key == A[mid]) {
            return mid;
        } else if (key > A[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return -1;
}
