// implementation of single linked list in C
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
        printf("Single Linked List Operations\n");
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

    }while(c == 'y');

    return 0;
}

void create(int ele){
    struct node *p;

    p = (struct node *)malloc(sizeof(struct node));
    p->no = ele;
    p->next = NULL;
    head = p;
}

void insertionAtBegin(int ele){
    struct node *p;

    if(head == NULL){
        create(ele);
        return;
    }

    p = (struct node *)malloc(sizeof(struct node));
    p->no = ele;
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
    p->next = NULL;

    q = head;

    while(q->next != NULL){
        q = q->next;
    }

    q->next = p;
}

void insertionAtMiddle(int ele){
    struct node *p, *q;
    int pos, c = 1;

    if(head == NULL){
        create(ele);
        return;
    }

    p = (struct node *)malloc(sizeof(struct node));
    p->no = ele;

    printf("Enter position: ");
    scanf("%d", &pos);

    q = head;

    while(c != pos - 1 && q->next != NULL){
        c++;
        q = q->next;
    }

    p->next = q->next;
    q->next = p;
}

void deletionAtBegin(){
    struct node *q;

    if(head == NULL){
        printf("List is empty\n");
        return;
    }

    q = head;
    head = head->next;
    free(q);
}

void deletionAtEnd(){
    struct node *q, *r;

    if(head == NULL){
        printf("List is empty\n");
        return;
    }

    if(head->next == NULL){
        free(head);
        head = NULL;
        return;
    }

    q = head;

    while(q->next != NULL){
        r = q;
        q = q->next;
    }

    r->next = NULL;
    free(q);
}

void deletionAtMiddle(){
    struct node *q, *r;
    int pos, c = 1;

    if(head == NULL){
        printf("List is empty\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    q = head;

    while(c != pos && q != NULL){
        c++;
        r = q;
        q = q->next;
    }

    if(q == NULL){
        printf("Invalid position\n");
        return;
    }

    r->next = q->next;
    free(q);
}

void traverse(){
    struct node *q;

    if(head == NULL){
        printf("List is empty");
        return;
    }

    for(q = head; q != NULL; q = q->next){
        printf("%d ", q->no);
    }
    printf("\n");
}
