// Implementation of Circular Doubly Linked List in C

#include <stdio.h>
#include <stdlib.h>

struct node{
    int no;
    struct node *next;
    struct node *pre;
} *head = NULL;

// Function prototypes
void create(int);

void insertionAtBegin(int);
void insertionAtEnd(int);
void insertionAtMiddle(int);

void deletionAtBegin();
void deletionAtEnd();
void deletionAtMiddle();

void traverse();

int main()
{
    int ch, ele;
    char c;

    do{
        printf("\nCircular Doubly Linked List Operations\n");
        printf("1. Insertion At Begin\n");
        printf("2. Insertion At End\n");
        printf("3. Insertion At Middle\n");
        printf("4. Deletion At Begin\n");
        printf("5. Deletion At End\n");
        printf("6. Deletion At Middle\n");
        printf("7. Traverse\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d",&ele);
                insertionAtBegin(ele);
                break;

            case 2:
                printf("Enter element: ");
                scanf("%d",&ele);
                insertionAtEnd(ele);
                break;

            case 3:
                printf("Enter element: ");
                scanf("%d",&ele);
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
                printf("Invalid Choice\n");
        }

        printf("\nCurrent List : ");
        traverse();

        printf("\nDo you want to continue (y/n): ");
        scanf(" %c",&c);

    }while(c=='y' || c=='Y');

    return 0;
}

// Create first node
void create(int ele)
{
    struct node *p;

    p = (struct node*)malloc(sizeof(struct node));

    p->no = ele;
    p->next = p;
    p->pre = p;

    head = p;
}

// Insertion at beginning
void insertionAtBegin(int ele)
{
    if(head == NULL)
    {
        create(ele);
        return;
    }

    struct node *p,*q;

    p = (struct node*)malloc(sizeof(struct node));
    p->no = ele;

    q = head->pre;

    p->next = head;
    p->pre = q;

    q->next = p;
    head->pre = p;

    head = p;
}

// Insertion at end
void insertionAtEnd(int ele)
{
    if(head == NULL)
    {
        create(ele);
        return;
    }

    struct node *p,*q;

    p = (struct node*)malloc(sizeof(struct node));
    p->no = ele;

    q = head->pre;

    p->next = head;
    p->pre = q;

    q->next = p;
    head->pre = p;
}

// Insertion at middle
void insertionAtMiddle(int ele)
{
    int pos,i;

    if(head == NULL)
    {
        create(ele);
        return;
    }

    printf("Enter position: ");
    scanf("%d",&pos);

    if(pos <= 1)
    {
        insertionAtBegin(ele);
        return;
    }

    struct node *p=head;

    for(i=1;i<pos-1 && p->next!=head;i++)
        p=p->next;

    struct node *q=(struct node*)malloc(sizeof(struct node));

    q->no=ele;

    q->next=p->next;
    q->pre=p;

    p->next->pre=q;
    p->next=q;
}

// Deletion at beginning
void deletionAtBegin()
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }

    if(head->next==head)
    {
        free(head);
        head=NULL;
        return;
    }

    struct node *p=head;
    struct node *q=head->pre;

    head=head->next;

    q->next=head;
    head->pre=q;

    free(p);
}

// Deletion at end
void deletionAtEnd()
{
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }

    if(head->next==head)
    {
        free(head);
        head=NULL;
        return;
    }

    struct node *p=head->pre;

    p->pre->next=head;
    head->pre=p->pre;

    free(p);
}

// Deletion at middle
void deletionAtMiddle()
{
    int pos,i;

    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d",&pos);

    if(pos==1)
    {
        deletionAtBegin();
        return;
    }

    struct node *p=head;

    for(i=1;i<pos && p->next!=head;i++)
        p=p->next;

    if(p==head)
    {
        printf("Invalid Position\n");
        return;
    }

    p->pre->next=p->next;
    p->next->pre=p->pre;

    free(p);
}

// Traverse
void traverse()
{
    if(head==NULL)
    {
        printf("List is empty");
        return;
    }

    struct node *p=head;

    do
    {
        printf("%d ",p->no);
        p=p->next;
    }while(p!=head);

    printf("\n");
}
