// To implement priority queue using C
#include <stdio.h>

#define size 5

int queue[size], F = -1, R = -1;

// function prototypes
void enqueue(int);
void delete();
void traverse();

int main(){
    int ch, ele;
    char c;

    do{
        printf("\nPriority Queue Operations\n");
        printf("1. Enqueue\n");
        printf("2. Delete\n");
        printf("3. Traverse\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &ele);
                enqueue(ele);
                break;

            case 2:
                delete();
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

void enqueue(int ele){
    int i;

    if(R == size - 1){
        printf("Queue is full\n");
    }
    else{
        if(F == -1){
            F = R = 0;
            queue[R] = ele;
        }
        else{
            // Shift elements to maintain priority order
            for(i = R; i >= F && queue[i] < ele; i--){
                queue[i + 1] = queue[i];
            }

            queue[i + 1] = ele;
            R++;
        }
    }
}

void delete(){
    if(F == -1){
        printf("Queue is empty\n");
    }
    else{
        printf("Deleted element is %d\n", queue[F]);

        if(F == R){
            F = -1;
            R = -1;
        }
        else{
            F = F + 1;
        }
    }
}

void traverse(){
    int i;

    if(F == -1){
        printf("Queue is empty\n");
        return;
    }

    printf("Priority Queue elements are:\n");

    for(i = F; i <= R; i++){
        printf("%d ", queue[i]);
    }

    printf("\n");
}
