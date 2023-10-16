#include <stdio.h>
#include <stdlib.h>

//void display_node(struct node *temp, struct node *head);

struct node
{
    int data;
    struct node *link;
}*head;

void main()
{
    struct node *new_node, *temp, *next_node;
    int n, pos;

    printf("enter number of nodes: ");
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

    temp = head;
    int p = 1;
    while(temp != NULL)
    temp =  temp-> link;
    {
        printf("Value in node %d: %d\n", p, temp-> data);
        p++;
    }

    temp = head;
    printf("Nodes of the linked list: \n");
    printf("|%.1p|-> ", head);
    while(temp->link != NULL)
    {
        printf("|%d|%p| -> ", temp-> data, temp-> link);
        temp = temp-> link;
    }
    printf("|%d|%p|\n", temp-> data, temp-> link);

    //display_node(temp, head);

    printf("Enter position of node to delete: ");
    scanf("%d", &pos);

    temp = head;
    int i = 1;
    while(i < pos-1)
    {
        temp = temp-> link;
    }
    next_node = temp-> link;
    temp-> link = next_node-> link;
    free(next_node);

    temp = head;
    int q = 1;
    while(temp != NULL)
    {
        printf("Value in node %d: %d\n", i, temp-> data);
        temp =  temp-> link;
        q++;
    }
}

/*
void display_node(struct node *temp, struct node *head)
{
    temp = head;
    printf("Nodes of the linked list: \n");
    printf("|%.1p|-> ", head);
    while(temp->link != NULL)
    {
        printf("|%d|%p| -> ", temp-> data, temp-> link);
        temp = temp-> link;
    }
    printf("|%d|%p|\n", temp-> data, temp-> link);

}
*/
