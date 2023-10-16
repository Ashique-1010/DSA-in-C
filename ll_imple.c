#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
}*head;

void main()
{
    struct node *new_node, *temp;
    int d;
    for(int i = 0; i < 3; i++)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        printf("Enter number to node %d: ", i+1);
        scanf("%d", &d);

        if(head == NULL)
        {
            head = new_node;     // if head has null as value, give address of new node as value
            new_node-> data = d;    // save the data into newnode
            new_node-> link = NULL;  // assign link part(address of next node) of new node null value
        }
        else
        {
            printf("value in head: %p\n", *head);
            temp = head;     // temp given value or address of head?     temp is given address of head
            printf("value in temp: %p\n", *temp);
            while(temp-> link != NULL)      //access link of head(link of node) if it is null, goto link of next node
            {
                temp = temp-> link;
            }
            new_node-> data = d;
            new_node-> link = NULL;
            temp-> link = new_node;
        }
    }
    temp = head;
    for(int i = 0; i < 3; i++)
    {
        printf("value in node %d = %d\n", i+1, temp-> data);
        temp = temp-> link;
    }
}
