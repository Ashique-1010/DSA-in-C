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
        printf("Overflow condotion\n");
    }
    else
    {
        int num;
        printf("Enter data to insert: ");
        scanf("%d", &num);
        rear++;
        QUEUE[rear] = num;
    }
}

int Dequeue()
{
    int n;
    char ch;
    printf("Delete from front or rear(f/r): ");
    scanf(" %c", &ch);
    switch(ch)
    {
        case 'f':
            n = QUEUE[front];
            front++;
            return n;
        case 'r':
            n = QUEUE[rear];
            rear--;
            return n;
    }
}

void Display_queue()
{
    int i = front;
    while(i != rear+1)
    {
        printf("%d ", QUEUE[i]);
        i++;
    }
    printf("\n");
}
