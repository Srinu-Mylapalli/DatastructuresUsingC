//implementation of merge sort in c

#include<stdio.h>
#define size 20


void mergeSort(int A[],int low,int high);
void merge(int A[],int low,int mid,int high);



int main(){

        int low=0,high=size-1;
        int A[size]={5,7,2,8,4,2,1,9,6,9,57,64,35,97,53,13,89,34,97,54};

        mergeSort(A,low,high);

        for(int i=low;i<=high;i++){
                printf("%d,",A[i]);

        }



        return 0;
}










void mergeSort(int A[],int low,int high){
        if(low<high){
                int mid= (low+high)/2;
                mergeSort(A,low,mid);
                mergeSort(A,mid+1,high);
                merge(A,low,mid,high);

        }
}




void merge(int A[],int low,int mid,int high){
        int i=low,j=mid+1,k=0,B[size];
        while(i<=mid && j<=high){
                if(A[i]<=A[j]){
                        B[k]=A[i];
                        i++;
                        k++;
                }
                else{
                        B[k]=A[j];
                        j++;
                        k++;
                }
        }
        while(i<=mid){
                B[k]=A[i];
                i++; k++;
        }
        while(j<=high){
                B[k]=A[j];
                j++; k++;
        }
        k=0;

        for(int i=low;i<=high;i++){
                A[i]=B[k];
                k=k+1;
        }
}
