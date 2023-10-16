#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int QUEUE[SIZE];
int front = -1, rear = -1;

void enQueue();
int deQueue();
void display_Queue();

void main()
{
    int ch, val, num;
    char choice;
    do
    {
        printf("Select opn on QUEUE:  1.Enqueue  2.Dequue  3.Display: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("Enter elemrnt: ");
                scanf("%d", &val);
                enQueue(val);
                break;
            case 2:
                num = deQueue();
                printf("dequeued element: %d\n", num);
                break;
/*
            case 3:
                display_Queue();
                break;
*/
        }
        display_Queue();
        printf("Do you want to continue(y/n): ");
        scanf(" %c", &choice);
    }while(choice == 'y');
}

void enQueue(int n)
{
    if(front == (rear+1)%SIZE)
    {
        printf("Queue is full\n");
    }
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        QUEUE[rear] = n;
    }
    else
    {
        rear = (rear+1)%SIZE;
        QUEUE[rear] = n;
    }
}

int deQueue()
{
    int x;
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else if(front == rear)
    {
        x = QUEUE[front];
        front = rear = -1;
        return x;
    }
    else
    {
        x = QUEUE[front];
        front = (front + 1)%SIZE;
        return x;
    }
}

void display_Queue()
{
    int i = front;
    while(i != rear)
    {
        printf("%d ", QUEUE[i]);
        i = (i+1)%SIZE;
    }
    //printf("%d\n", QUEUE[rear]);
}
