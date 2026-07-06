//to implement sorted array using C
#include <stdio.h>
#define capacity 5

int A[capacity], n = 0;

// function prototype
void insertion(int);
void deletion(int);
void traverse();

int main()
{
    int ch, ele;
    char c;

    do
    {
        printf("Sorted Array operations");
        printf("\n1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Traverse\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &ele);
            insertion(ele);
            break;

        case 2:
            printf("Enter the element to delete: ");
            scanf("%d", &ele);
            deletion(ele);
            break;

        case 3:
            traverse();
            break;

        default:
            printf("Invalid choice");
        }

        printf("\nDo you want to continue(y/n): ");
        scanf(" %c", &c);
    }
    while (c == 'y');

    return 0;
}

void insertion(int ele)
{
    int pos, i;

    if (n == capacity)
    {
        printf("Array is full, insertion is not possible");
    }
    else
    {
        for (i = 0; i <= n - 1; i++)
        {
            if (A[i] > ele)
            {
                pos = i;
                break;
            }
        }

        if (i == n)
        {
            A[i] = ele;
        }
        else
        {
            for (int j = n - 1; j >= pos; j--)
            {
                A[j + 1] = A[j];
            }
            A[pos] = ele;
        }

        n++;
    }
}

void deletion(int ele)
{
    int pos = -1, i;

    if (n == 0)
    {
        printf("No element in Array, deletion not possible");
    }
    else
    {
        for (i = 0; i <= n - 1; i++)
        {
            if (A[i] == ele)
            {
                pos = i;
                break;
            }
        }

        if (pos == -1)
        {
            printf("Given element not available in the Array, deletion not possible");
        }
        else
        {
            for (i = pos + 1; i <= n - 1; i++)
            {
                A[i - 1] = A[i];
            }
            n--;
        }
    }
}

void traverse()
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}
