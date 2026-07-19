//implementation of quick sort in c
#include<stdio.h>
#define size 10
int A[]={1,4,2,5,3,0,32,86,9,64},low=0,high=size-1;

int partition(int A[],int,int);
void display(int A[],int,int);
void QuickSort(int A[],int low,int highi);

int main(){


        QuickSort(A,low,high);

        display(A,low,high);
        return 0;
}




void QuickSort(int A[],int low,int high){
        if(low<high){
                int j=partition(A,low,high);
                QuickSort(A,low,j-1);
                QuickSort(A,j+1,high);
        }
}

int partition(int A[],int low,int high){
        int pivot=A[low];
        int i=low,j=high;
        int temp;

        while(i<j){
                while(i<=high && A[i]<=pivot)
                        i++;
                while(A[j]>pivot)
                        j--;
                if(i<j){
                        //int temp;
                        temp=A[i];
                        A[i]=A[j];
                        A[j]=temp;
                }
        }

        temp = A[low];
        A[low]=A[j];
        A[j]=temp;


        return j;
}



void display(int A[],int low,int high){
             for(int i=low;i<=high;i++){
                printf("%d ",A[i]);
        }
}
