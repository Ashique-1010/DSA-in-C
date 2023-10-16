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
    int count = 0, choice = 1;

    temp = NULL;
    while(choice == 1)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        printf("Enter data in node: ");
        scanf("%d", &new_node-> data);
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
        count++;
        printf("Do you want to continue(1 or 0)");
        scanf("%d", &choice);
    }
    printf("%d nodes have been created.\n", count);

    temp = head;
    int i = 0;
    while(temp != NULL)
    {
        printf("Value in node %d = %d\n", i+1, temp-> data);
        temp = temp-> link;
        i++;
    }

    int pos;
    printf("which postion do you want to insert: ");
    scanf("%d", &pos);

    if(pos > count)
    {
        printf("invalid position\n");
    }
    else
    {
        struct node *insert;
        insert = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &insert-> data);

        temp = head;
        for(int i = 1; i < pos-1; i++)
        {
            temp = temp-> link;
        }
        insert-> link = temp-> link;
        temp->link = insert;
    }

    temp = head;
    int j = 1;
    while(temp != NULL)
    {
        printf("Value in node %d = %d\n", j, temp-> data);
        temp = temp-> link;
        j++;
    }
}
