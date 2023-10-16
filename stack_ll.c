// Implementation of stack and its operations

/*
Push()
1.create a node
2.store data into the node
3.set address of first node to null and point top to the first node
4.for second node and others store address of prev node in current node(not null while creating) and assign address of current to top

*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
}*top = NULL;

void Push(int);
int Pop();
void View_stack();

void main()
{
    int ch, num, val;
    char choice;
    do
    {
        printf("Select operation: 1.Push  2.Pop  3.Display:  ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &num);
                Push(num);
                break;
            case 2:
                val = Pop();
                printf("Poooped value = %d\n", val);
                break;
            case 3:
                printf("The created stack:\n");
                View_stack();
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
        printf("Do you want to continue(y/n): ");
        scanf(" %c", &choice);
    } while(choice == 'y');
}

void Push(int x)
{
    struct node *frame, *temp;
    frame = (struct node*)malloc(sizeof(struct node));
    frame-> data = x;

    if(top == NULL)
    {
        frame-> link = NULL;
        temp = top = frame;
    }
    else
    {
        top = frame;
        frame-> link = temp;
        temp = frame;
    }
}

int Pop()
{
    struct node *release;
    release = top;
    int p = top-> data;
    top = top-> link;
    free(release);

    return p;
}

void View_stack()
{
    struct node *tra;
    tra = top;
    while(tra != NULL)
    {
        printf("%d\n", tra-> data);
        tra = tra-> link;
    }
}
