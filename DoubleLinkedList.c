// implementation of double linked list in C
#include <stdio.h>
#include <stdlib.h>
/*
struct node{
    int no;
    struct node *next;
} *head = NULL;
*/
// function prototypes
void create(int);

void insertionAtBegin(int);
void insertionAtEnd(int);
void insertionAtMiddle(int,int);

void deletionAtBegin();
void deletionAtEnd();
void deletionAtMiddle();

void traverse();

int main(){
    int ch, ele,pos;
    char c;

    do{
        printf("Double Linked List Operations\n");
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
                printf("Enter the element and position to insert at middle: ");
                scanf("%d %d", &ele,&pos);
                insertionAtMiddle(ele,pos);
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







/*
struct node{
        int no;
        struct node *next;
        struct node *pre;
};

struct node *head=NULL;

void create(int ele){
        struct node *p=(struct node *)malloc(sizeof(struct node));
        p->no=ele;
        p->pre=head;
        p->next=NULL;
        head=p;
}

void end_insertion(int ele){
        struct node *temp=head;
        struct node *p=(struct node *)malloc(sizeof(struct node));
p->no=ele;
p->next=NULL;
if(head==NULL){
        head=p;
}
while(temp->next!=NULL){
        temp=temp->next;
}
temp->next=p;
p->pre=temp;
}



----------------
*/

struct node{
        struct node *pre;
        int no;
        struct node *next;
} *head = NULL, *tail=NULL;

void create(int ele){
        struct node *p;
        p=(struct node *)malloc(sizeof(struct node));
        p->no=ele;
        p->pre=NULL;
        p->next=NULL;
        head=tail=p;
}

void insertionAtBegin(int ele){
        struct node *p;
        p=(struct node *)malloc(sizeof(struct node));
        p->no=ele;
        p->next=head;
        head->pre=p;
        p->pre=NULL;
        head=p;
}

void insertionAtEnd(int ele){
        struct node *p;
        p=(struct node *)malloc(sizeof(struct node));
        p->no=ele;
        p->pre=tail;
        p->next=NULL;
        tail=p;
}



void insertionAtMiddle(int ele,int pos){
struct node *p,*pre;
p=(struct node *)malloc(sizeof(struct node));
p->no=ele;
struct node *tmp=head;
if(pos==1){
        head=p;
        free(tmp);
        p->next=p->pre=NULL;
}
//for(int i=1;i<pos-1;i++){


while(c!=pos-1){
        tmp=tmp->next;
        c++;
}
pre=tmp->next;
}




void deletionAtBegin(){
        struct node *q;
        q=head;
        head=head->next;
        head->pre=NULL;
        free(q);
}

void deletionAtEnd(){
        struct node *q;
        q=tail;
        tail=tail->pre;
        tail->next=NULL;
        free(q);
}


void deletionAtMiddle(int pos){
        struct node *p,*q,*r;
        int c=1;
        q=head;
        while(c!=pos){
                c++;
                q=q->next;
        }
        p=q->pre;
        r=q->next;
        p->next=r;
        r->pre=p;
        free(q);
}


void traverse(){
        while(head!=NULL){
                printf("%d",head->no);
                head=head->next;
        }
}
