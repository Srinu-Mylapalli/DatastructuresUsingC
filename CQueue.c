// to implement circular queue using C
#include <stdio.h>

#define size 5

int cqueue[size], F = -1, R = -1;

// function prototypes
void insertion(int);
void deletion();
void traverse();

int main(){
    int ch, ele;
    char c;

    do{
        printf("Circular Queue Operations\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Traverse\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &ele);
                insertion(ele);
                break;

            case 2:
                deletion();
                break;

            case 3:
                traverse();
                break;

            default:
                printf("Invalid choice\n");
        }

        printf("\nDo you want to continue(y/n): ");
        scanf(" %c", &c);

    }while(c == 'y');

    return 0;
}

void insertion(int ele){
    if((R + 1) % size == F){
        printf("Circular Queue is full\n");
    }
    else{
        R = (R + 1) % size;
        cqueue[R] = ele;

        if(F == -1)
            F = 0;
    }
}

void deletion(){
    if(F == -1){
        printf("Queue is empty\n");
    }
    else if(F == R){
        printf("Deleted element is %d\n", cqueue[F]);
        F = -1;
        R = -1;
    }
    else{
        printf("Deleted element is %d\n", cqueue[F]);
        F = (F + 1) % size;
    }
}

void traverse(){
    int i;

    if(F == -1){
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are:\n");

    i = F;
    while(1){
        printf("%d ", cqueue[i]);

        if(i == R)
            break;

        i = (i + 1) % size;
    }

    printf("\n");
}
