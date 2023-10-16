#include <stdio.h>

#define MAX 50

int QUEUE[MAX];
int front = 0;
int rear = -1;

void Enqueue();
int Dequeue();
void Display_queue();

void main()
{
    int ch, num;
    char choice;
    do
    {
        printf("Select opn on QUEUE:  1.Enqueue  2.Dequue  3.Display: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                Enqueue();
                break;
            case 2:
                num = Dequeue();
                printf("dequeued element: %d\n", num);
                break;
            case 3:
                Display_queue();
                break;
        }
        printf("Do you want to continue(y/n): ");
        scanf(" %c", &choice);
    }while(choice == 'y');
}

void Enqueue()
{
    if(rear > MAX)
    {
        printf("Overflow condition\n");
    }
    else
    {
        int x;
        printf("Enter data to insert to queue: ");
        scanf("%d", &x);
        rear++;
        QUEUE[rear] = x;
    }
}

int Dequeue()
{
    if(front > rear)
    {
        printf("Underflow condition\n");
    }
    else
    {
        int y = QUEUE[front];
        front++;
        return y;
    }
}

void Display_queue()
{
    int i = front;
    printf("The queue: \n|");
    while(QUEUE[i] != '\0')
    {
        printf("%d |", QUEUE[i]);
        i++;
    }
    printf("\n");
}
