#include <stdio.h>

#define SIZE 5
int QUEUE[SIZE];
int f = -1, r = -1;

void enQ_front(int);
void enQ_rear(int);
int deQ_front();
int deQ_rear();
void display();

void main()
{
    int ch, num, val;
    char choice;
    do
    {
        printf("Select operation\n1. insert at front\n2.insert at rear\n3.delete from front\n4.delete from rear\n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("ENter data to insert: ");
                scanf("%d", &num);
                enQ_front(num);
                break;
            case 2:
                printf("ENter data to insert: ");
                scanf("%d", &num);
                enQ_rear(num);
                break;
            case 3:
                val = deQ_front();
                printf("dequeued element: %d\n", val);
                break;
            case 4:
                val = deQ_rear();
                printf("dequeued element: %d\n", val);
                break;
            default:
                printf("Invalid input\n");
        }
        display();
        printf("Do you want to continue(y/n): ");
        scanf(" %c", &choice);
    }while(choice == 'y');
}

void enQ_front(int x)
{
    if((f == 0 && r == SIZE-1)||(f == r+1))
    {
        printf("Overflow\n");
    }
    else if(f == -1 && r == -1)
    {
        f = r = 0;
        QUEUE[f] = x;
    }
    else if(f == 0)
    {
        f = SIZE-1;
        QUEUE[f] = x;
    }
    else
    {
        f--;
        QUEUE[f] = x;
    }
}

void enQ_rear(int y)
{
    if((f == 0 && r == SIZE-1)||(f == r+1))
    {
        printf("Overflow\n");
    }
    else if(f == -1 && r == -1)
    {
        f = r = 0;
        QUEUE[r] = y;
    }
    else if(r == SIZE-1)
    {
        r = 0;
        QUEUE[r] = y;
    }
    else
    {
        r++;
        QUEUE[r] = y;
    }
}

int deQ_front()
{
    int z;
    if(f == -1 && r == -1)
    {
        printf("Underflow\n");
    }
    else if(f == r)
    {
        z = QUEUE[f];
        f = r = -1;
        return z;
    }
    else if(f == SIZE-1)
    {
        z = QUEUE[f];
        f = 0;
        return z;
    }
    else
    {
        z = QUEUE[f];
        f++;
        return z;
    }
}

int deQ_rear()
{
    int z;
    if(f == -1 && r == -1)
    {
        printf("Underflow\n");
    }
    else if(f == r)
    {
        z = QUEUE[r];
        f = r = -1;
        return z;
    }
    else if(r == 0)
    {
        z = QUEUE[r];
        r = SIZE-1;
        return z;
    }
    else
    {
        z = QUEUE[r];
        r--;
        return z;
    }
}

void display()
{
    int i = f;
    while(i != r)
    {
        printf("%d ", QUEUE[i]);
        i = (i+1)%SIZE;
    }
    printf("%d\n", QUEUE[r]);
    return;
}
