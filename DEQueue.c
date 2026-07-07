// implementation of double ended queue using C
#include <stdio.h>

#define size 5

int DQ[size], F = -1, R = -1;

// function prototypes
void insertionatR(int);
void insertionatF(int);
void deleteatR();
void deleteatF();
void traverse();

int main(){
    int ch, ele;
    char c;

    do{
        printf("Double Ended Queue Operations\n");
        printf("1. insertionatR\n");
        printf("2. insertionatF\n");
        printf("3. deleteatF\n");
        printf("4. deleteatR\n");
        printf("5. Traverse\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                printf("Enter the element to insertionatR: ");
                scanf("%d", &ele);
                insertionatR(ele);
                break;

            case 2:
                printf("Enter the element to insertionatF: ");
                scanf("%d", &ele);
                insertionatF(ele);
                break;

            case 3:
                deleteatF();
                break;

            case 4:
                deleteatR();
                break;

            case 5:
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

void insertionatR(int ele){
    if((F == 0 && R == size - 1) || ((R + 1) % size == F))
        printf("DEQueue is full\n");
    else if(F == -1 && R == -1){
        F = R = 0;
        DQ[R] = ele;
    }
    else{
        R = (R + 1) % size;
        DQ[R] = ele;
    }
}

void insertionatF(int ele){
    if((F == 0 && R == size - 1) || ((R + 1) % size == F))
        printf("DEQueue is full\n");
    else if(F == -1 && R == -1){
        F = R = 0;
        DQ[F] = ele;
    }
    else if(F == 0){
        F = size - 1;
        DQ[F] = ele;
    }
    else{
        F = F - 1;
        DQ[F] = ele;
    }
}

void deleteatF(){
    if(F == -1 && R == -1)
        printf("DEQueue is empty, deletion is not possible\n");
    else if(F == R){
        printf("Deleted element is %d\n", DQ[F]);
        F = R = -1;
    }
    else if(F == size - 1){
        printf("Deleted element is %d\n", DQ[F]);
        F = 0;
    }
    else{
        printf("Deleted element is %d\n", DQ[F]);
        F = F + 1;
    }
}

void deleteatR(){
    if(F == -1 && R == -1)
        printf("DEQueue is empty, deletion is not possible\n");
    else if(F == R){
        printf("Deleted element is %d\n", DQ[R]);
        F = R = -1;
    }
    else if(R == 0){
        printf("Deleted element is %d\n", DQ[R]);
        R = size - 1;
    }
    else{
        printf("Deleted element is %d\n", DQ[R]);
        R = R - 1;
    }
}

void traverse(){
    int i;

    if(F == -1){
        printf("DEQueue is empty\n");
        return;
    }

    printf("DEQueue elements are:\n");

    i = F;
    while(1){
        printf("%d ", DQ[i]);

        if(i == R)
            break;

        i = (i + 1) % size;
    }

    printf("\n");
}
