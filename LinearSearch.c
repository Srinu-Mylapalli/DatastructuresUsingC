#include<stdio.h>

int linearSearch(int A[], int n, int key);

int main(){
        int A[] = {10,60,20,90,50,40,70,30,80};
        int n = sizeof(A)/sizeof(A[0]);
        int key = 30;

        int i = linearSearch(A,n,key);

        if(i == -1)
                printf("key is not found in the array\n");
        else
                printf("key found at Index: %d\n",i);
        return 0;

}


int linearSearch(int A[], int n, int key){
        for(int i=0;i<n;i++){
                if(A[i] == key){
                        return i;
                }
        }

        return -1;
}
