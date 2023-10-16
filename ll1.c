/*
    define structure of node
    declare a node var, head ptr, temp ptr to store address of next node
    initialise head ptr to null(0)
    set no of nodes(for n), or continue linking node with user choice(do-while)
    allocate memory for node
    read data and store
    set link of node to null
    if head == null, assign address of first node to, head and to a temporary ptr; temp
    assign the address of first node stored in head to temp  :- temp holds the address of first node(ssame as line above)
    on creation of newnode(second node)
    else assign address of newnode to link of temp.
    (temp had been holding address of first node, so first node is accessed and its link part is assigned the address of newly created node ==> linking)
    temp currently pointing to previous node. access link section of previous node through temp, then assign address of newnode(second) to link of first
    change address of new node to temp, so that in next iteration, while a new node is created it will point to the previous node
    repeat this process.
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *head;

void main()
{
    struct node *new_node, *temp;
    int n;
    printf("How many nodes : ");
    scanf("%d", &n);
    head = NULL;

    for(int i = 0; i < n; i++)
    {
        new_node = (struct node*)malloc(sizeof(struct node*));
        printf("Enter data in node %d: ", i+1);
        scanf("%d", &(new_node-> data));
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
        printf("data in node %d = %d\n", i+1, temp-> data);
        printf("address of temp = %p\n", temp);
        temp = temp-> link;
        printf("address of next node in temp = %p\n", temp);

        printf("address in node %d link = %p\n", i+1, temp);
    }
}
