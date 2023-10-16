#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*front = NULL, *rear = NULL;

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
    struct node *new_node, *temp;
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to insert: ");
    scanf("%d", &new_node-> data);

    if(rear == NULL)
    {
        front = rear = new_node;
    }
    else
    {
        rear-> next = new_node;
        rear = new_node;
        rear-> next = NULL;
    }
}

int Dequeue()
{
    int x;
    struct node *temp;
    x = front-> data;
    temp = front;
    front = front-> next;
    free(temp);
    return x;
}

void Display_queue()
{
    struct node *temp;
    temp = front;
    while(temp != NULL)
    {
        printf("%d ", temp-> data);
        temp = temp-> next;
    }
    printf("\n");
}
