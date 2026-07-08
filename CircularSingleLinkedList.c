// implementation of circular single linked list in C
#include <stdio.h>
#include <stdlib.h>

struct node{
    int no;
    struct node *next;
} *head = NULL;

// function prototypes
void create(int);

void insertionAtBegin(int);
void insertionAtEnd(int);
void insertionAtMiddle(int);

void deletionAtBegin();
void deletionAtEnd();
void deletionAtMiddle();

void traverse();

int main(){
    int ch, ele;
    char c;

    do{
        printf("Circular Single Linked List Operations\n");
        printf("1. insertionAtBegin\n");
        printf("2. insertionAtEnd\n");
        printf("3. insertionAtMiddle\n");
        printf("4. deletionAtBegin\n");
        printf("5. deletionAtEnd\n");
        printf("6. deletionAtMiddle\n");
        printf("7. Traverse\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                printf("Enter the element to insert at beginning: ");
                scanf("%d", &ele);
                insertionAtBegin(ele);
                break;

            case 2:
                printf("Enter the element to insert at end: ");
                scanf("%d", &ele);
                insertionAtEnd(ele);
                break;

            case 3:
                printf("Enter the element to insert at middle: ");
                scanf("%d", &ele);
                insertionAtMiddle(ele);
                break;

            case 4:
                deletionAtBegin();
                break;

            case 5:
                deletionAtEnd();
                break;

            case 6:
                deletionAtMiddle();
                break;

            case 7:
                traverse();
                break;

            default:
                printf("Invalid choice\n");
        }

        printf("\nCurrent List: ");
        traverse();

        printf("\nDo you want to continue(y/n): ");
        scanf(" %c", &c);

    } while(c == 'y');

    return 0;
}

void create(int ele){
    struct node *p;

    p = (struct node *)malloc(sizeof(struct node));
    p->no = ele;
    p->next = p;
    head = p;
}

void insertionAtBegin(int ele){
    struct node *p, *q;

    if(head == NULL){
        create(ele);
        return;
    }

    p = (struct node *)malloc(sizeof(struct node));
    p->no = ele;

    q = head;
    while(q->next != head){
        q = q->next;
    }

    q->next = p;
    p->next = head;
    head = p;
}

void insertionAtEnd(int ele){
    struct node *p, *q;

    if(head == NULL){
        create(ele);
        return;
    }

    p = (struct node *)malloc(sizeof(struct node));
    p->no = ele;

    q = head;
    while(q->next != head){
        q = q->next;
    }

    q->next = p;
    p->next = head;
}

void insertionAtMiddle(int ele){
    int pos, i;
    struct node *p, *q;

    if(head == NULL){
        create(ele);
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos <= 1){
        insertionAtBegin(ele);
        return;
    }

    p = (struct node *)malloc(sizeof(struct node));
    p->no = ele;

    q = head;
    for(i = 1; i < pos - 1 && q->next != head; i++){
        q = q->next;
    }

    p->next = q->next;
    q->next = p;
}

void deletionAtBegin(){
    struct node *p, *q;

    if(head == NULL){
        printf("List is empty\n");
        return;
    }

    if(head->next == head){
        free(head);
        head = NULL;
        return;
    }

    q = head;
    while(q->next != head){
        q = q->next;
    }

    p = head;
    q->next = head->next;
    head = head->next;
    free(p);
}

void deletionAtEnd(){
    struct node *p, *q;

    if(head == NULL){
        printf("List is empty\n");
        return;
    }

    if(head->next == head){
        free(head);
        head = NULL;
        return;
    }

    p = head;
    while(p->next != head){
        q = p;
        p = p->next;
    }

    q->next = head;
    free(p);
}

void deletionAtMiddle(){
    int pos, i;
    struct node *p, *q;

    if(head == NULL){
        printf("List is empty\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos <= 1){
        deletionAtBegin();
        return;
    }

    q = head;
    for(i = 1; i < pos - 1 && q->next != head; i++){
        q = q->next;
    }

    if(q->next == head){
        printf("Invalid position\n");
        return;
    }

    p = q->next;
    q->next = p->next;
    free(p);
}

void traverse(){
    struct node *q;

    if(head == NULL){
        printf("List is empty\n");
        return;
    }

    q = head;
    do{
        printf("%d ", q->no);
        q = q->next;
    } while(q != head);

    printf("\n");
}
