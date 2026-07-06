// to implement stack using C
#include <stdio.h>
#define size 5

char stack[size];
int top = -1;

// function prototype
void push(char);
void pop();

int main()
{
    int ch;
    char ele, c;

    do
    {
        printf("stack operations");
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the element to push: ");
            scanf(" %c", &ele);
            push(ele);
            break;

        case 2:
            pop();
            break;

        default:
            printf("Invalid choice");
        }

        printf("\nDo you want to continue(y/n): ");
        scanf(" %c", &c);

    } while (c == 'y');

    return 0;
}

void push(char ele)
{
    if (top == size - 1)
    {
        printf("Stack Overflow");
    }
    else
    {
        top = top + 1;
        stack[top] = ele;
    }
}

void pop()
{
    if (top == -1)
        printf("Stack Underflow");
    else
    {
        printf("%c is deleted", stack[top]);
        top = top - 1;
    }
}
