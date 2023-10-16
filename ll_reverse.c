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
    int n;
    printf("How many nodes: ");
    scanf("%d", &n);

    head = NULL;
    for(int i = 0; i < n; i++)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        printf("Enter data in node %d: ", i+1);
        scanf("%d", &new_node-> data);
        new_node-> link = NULL;

        if(head == NULL)
        {
            temp = head = new_node;
        }
        else
        {
            temp-> link = new_node;
            temp = new_node;
        }
    }

    printf("The created linked list: \n");
    temp = head;
    while(temp-> link != NULL)
    {
        printf("%d-> ", temp-> data);
        temp = temp-> link;
    }
    printf("%d\n", temp->data);

    struct node *prev_node, *current_node, *next_node;
    prev_node = NULL;
    current_node = next_node = head;
    while(next_node != NULL)
    {
        next_node = next_node-> link;
        current_node-> link = prev_node;
        prev_node = current_node;
        current_node = next_node;
    }
    head = prev_node;

    printf("The reversed linked list: \n");
    temp = head;
    while(temp-> link != NULL)
    {
        printf("%d-> ", temp-> data);
        temp =  temp-> link;
    }
    printf("%d\n", temp-> data);

    temp = head;
    for(int i = 0; i < n; i++)
    {
        temp = temp-> link;
        free(temp);
    }
}
