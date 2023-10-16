#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
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
        printf("Enter data in node %d: ");
        scanf("%d", &new_node-> data);
        new_node-> prev = NULL;
        new_node-> next = NULL;

        if(head == NULL)
        {
            head = temp = new_node;
        }
        else
        {
            temp-> next = new_node;
            new_node-> prev = temp;
            temp = new_node;
        }
    }

    printf("The linked list: \n");
    temp = head;
    while(temp-> next != NULL)
    {
        printf("%d-> ", temp-> data);
        temp = temp-> next;
    }
    printf("%d\n", temp-> data);

    printf("The created linked list: \n");
    temp = head;
    printf("|%p|--> ", head);
    while(temp-> next != NULL)
    {
        printf("|%p| %d |%p|--> ", temp-> prev, temp-> data, temp-> next);
        temp = temp-> next;
    }
    printf("|%p| %d |%p|\n", temp-> prev, temp-> data, temp-> next);

    temp = head;
    for(int i = 0; i < n; i++)
    {
        temp = temp-> next;
        free(temp);
    }

}
