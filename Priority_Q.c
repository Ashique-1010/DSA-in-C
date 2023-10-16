#include <stdio.h>

#define SIZE 10
int arr[SIZE];
int prio[SIZE];
int nums = 0, deq = 0;

void enQueue();
int deQueue();
void shift_right(int * , int);
void display();

void main()
{
    int ch, val;
    char choice;
    do
    {
        printf("Choose operation: 1.enqueue  2.dequeue: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                enQueue();
                break;
            case 2:
                val = deQueue();
                printf("dequeued element: %d\n", val);
                break;
            default:
                printf("Invalid input\n");
        }
        display();
        printf("continue(y/n): ");
        scanf(" %c", &choice);
    }while(choice == 'y');
}

void enQueue()
{
    int num, pr;
    if(nums > SIZE)
    {
        printf("Queue is full\n");
    }
    else if(nums == 0)
    {
        printf("ENter number: ");
        scanf("%d", &num);
        printf("Enter priority: ");
        scanf("%d", &pr);
        nums++;
        arr[0] = num;
        prio[0] = pr;
    }
    else
    {
        printf("ENter number: ");
        scanf("%d", &num);
        printf("Enter priority: ");
        scanf("%d", &pr);
        nums++;
        for(int i = 0; i < nums; i++)
        {
            if(pr <= prio[i])
            {
                if(i == nums-1 && i < SIZE)
                {
                    arr[i] = num;
                    prio[i] = pr;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                shift_right(arr, i);
                shift_right(prio, i);
                arr[i] = num;
                prio[i] = pr;
                break;
            }
        }
    }
}

int deQueue()
{
    if(deq > nums-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int x = arr[deq];
        deq++;
        return x;
    }
}

void shift_right(int array[], int limit)
{
    for(int i = nums+1; i > limit; i--)
    {
        array[i] = array[i-1];
    }
}

void display()
{
    printf("Values: \n");
    for(int i = deq; i < nums; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nPriority: \n");
    for(int i = deq; i < nums; i++)
    {
        printf("%d ", prio[i]);
    }
    printf("\n");
}
