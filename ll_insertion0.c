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

    temp = head;
    for(int i = 0; i < n; i++)
    {
        printf("Value in node %d = %d\n", i+1, temp-> data);
        temp = temp-> link;
    }

    /*
    struct node *insert;
    insert = (struct node*)malloc(sizeof(struct node));
    printf("Enter data you want to insert: ");
    scanf("%d", &insert-> data);
    insert-> link = head;
    head = insert;

    temp = head;
    int i = 0;
    while(temp != NULL)
    {
        printf("value in node %d = %d\n", i+1, temp-> data);
        temp = temp-> link;
        i++;
    }
    */

    int m;
    printf("How many nodes you want to insert: ");
    scanf("%d", &m);
    struct node *insert_many, *temp1, *temp2;
    temp1 = NULL;
    for(int i = 0; i < m; i++)
    {
        insert_many = (struct node*)malloc(sizeof(struct node));
        printf("enter data in node: ");
        scanf("%d", &insert_many-> data);
        insert_many-> link = NULL;

        if(temp1 == NULL)
        {
            temp1 = temp2 = insert_many;
        }
        else
        {
            temp2-> link = insert_many;
            temp2 = insert_many;
        }

    }
    //printf("addres in temp2 = %p\n", temp2);
    temp2-> link = head;
    head = temp1;

    temp = head;
    int i = 0;
    while(temp != NULL)
    {
        printf("value in node %d = %d\n", i+1, temp-> data);
        temp = temp-> link;
        i++;
    }

}
