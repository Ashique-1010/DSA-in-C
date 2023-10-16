#include <stdio.h>

#define SIZE 50

int QUEUE[SIZE];
int front = 0, rear = -1;

void enQueue();
int deQueue();
void display();

void main()
{
    int ch, num;
    char choice;

    do
    {
        printf("select queue operation; 1.enQueue  2.deQueue  3.Display: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                enQueue();
                break;

            case 2:
                num = deQueue();
                printf("THe dequeued element: %d\n", num);
                break;

            case 3:
                display();
                break;
        }
        printf("Do you want to do again(y/n): ");
        scanf(" %c", &choice);
    }while(choice == 'y');
}

void enQueue()
{
    char cho;
    int num, temp, temp_val;
    if(rear > SIZE)
    {
        printf("Overflow condition\n");
    }
    else
    {
         printf("Insert at front or rear(f/r): ");
         scanf(" %c", &cho);
         switch(cho)
         {
             case 'r':
                printf("enter data to insert: ");
                scanf("%d", &num);
                rear++;
                QUEUE[rear] = num;
                break;

            case 'f':
                temp = rear;
                while(temp != front)
                {
                    temp_val = QUEUE[temp];
                    QUEUE[temp+1] = temp_val;
                    temp--;
                }
                printf("enter data to insert: ");
                scanf("%d", &num);
                QUEUE[front] = num;
                rear++;
                break;
         }
    }
}

int deQueue()
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

void display()
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
