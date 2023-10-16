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
        printf("Enter data in node %d:  ", i+1);
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
    int i = 1;
    while(temp != NULL)
    {
        printf("value in node %d: %d\n", i, temp-> data);
        temp = temp-> link;
        i++;
    }

    struct node *prev_node;
    temp = head;
    while(temp-> link != NULL)
    {
        prev_node = temp;
        temp = temp-> link;
    }
    if(temp == head)
    {
        temp = NULL;
    }
    else
    {
        prev_node-> link = NULL;
    }
    free(temp);

    /*
    temp = head;
    while(temp-> link != NULL)
    {
        temp = temp-> link;
    }
    free(temp-> link);
    temp = NULL;
    */

    printf("After deleting.\n");
    temp = head;
    int j = 1;
    while(temp != NULL)
    {
        printf("value in node %d: %d\n", j, temp-> data);
        temp = temp-> link;
        j++;
    }

}
