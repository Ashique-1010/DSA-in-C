#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
}*head, *tail;

void display_nodes();
void main()
{
    struct node *new_node, *current, *next_node;
    int n;
    printf("How many nodes: ");
    scanf("%d", &n);

    head = NULL;
    for(int i = 0; i < n; i++)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
        printf("Enter data in node %d: ", i+1);
        scanf("%d", &new_node-> data);
        new_node-> prev = NULL;
        new_node-> next = NULL;

        if(head == NULL)
        {
            head = tail = new_node;
        }
        else
        {
            tail-> next = new_node;
            new_node-> prev = tail;
            tail = tail-> next;
        }
    }

    display_nodes();

    current = head;
    while(current != NULL)
    {
        next_node = current-> next;
        current-> next = current-> prev;
        current-> prev = next_node;
        current = next_node;
    }
    current = head;
    head = tail;
    tail = current;

    display_nodes();
}

void display_nodes()
{
    struct node *temp;
    temp = head;
    while(temp != NULL)
    {
        printf("%d--", temp-> data);
        temp = temp-> next;
    }
    printf("\n");
}
