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
    printf("hoe many nodes: ");
    scanf("%d", &n);

    head = NULL;
    for(int i = 0; i < n; i++)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        printf("enter data into node %d: ", i+1);
        scanf("%d",  &new_node-> data);
        new_node-> link = NULL;

        if(head == NULL)
        {
            head = temp = new_node;
        }
        else
        {
            temp-> link = new_node;
            temp = new_node;
        }
    }

    struct node *insert;
    printf("enter value in node: ");
    scanf("%d", &insert-> data);
    insert-> link = NULL;

    temp = head;
    while(temp-> link != NULL)
    {
        temp = temp-> link;
    }
    temp-> link = insert;

    temp = head;
    for(int i = 0; i < n+1; i++)
    {
        printf("value in node %d: %d\n", i+1, temp-> data);
        temp = temp-> link;
    }
/*
    struct node *insert_many, *temp_head, *temp1;
    int m;
    printf("how many nodes more: ");
    scanf("%d", &m);

    temp_head = NULL;
    for(int i = 0; i < n; i++)
    {
        printf("Enter value in node: ");
        scanf("%d", &insert_many-> data);
        insert_many-> link = NULL;

        if(temp_head == NULL)
        {
            temp_head = temp1 = insert_many;
        }
        else
        {
            temp1-> link = insert_many;
            temp1 = insert_many;
        }
    }

    temp = head;
    while(temp-> link != NULL)
    {
        temp = temp-> link;
    }
    temp-> link = temp_head;

    temp = head;
    while(temp != NULL)
    {
        printf("Value in node = %d\n", temp-> data);
        temp = temp-> link;
    }

*/
}
