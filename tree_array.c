/*
initialise array to store elements of tree
node at i will have left child at 2*i+1 and right child at 2*i+2
recieve rootnode
    ask user for left or right based on yes or no
        insert left child at 2*i+1 and right child at 2*i+2
        leave blank or __ on empty nodes
        ask child of next node
            if __ goto next node
*/


#include <stdio.h>

#define SIZE 15

char TREE[SIZE];
void display();

void main()
{
    int root_pos = 0, node_count, l_pos, r_pos;
    char root, left, right, choice, ch;
    printf("Enter root node: ");
    scanf(" %c", &root);
    TREE[root_pos] = root;

    do
    {

        printf("do you want left child for %c (y/n): ", TREE[root_pos]);
        scanf(" %c", &ch);
        l_pos = 2*root_pos+1;
        TREE[l_pos] = '_';
        if(ch == 'y')
        {
            printf("Enter value in left child: ");
            scanf(" %c", &left);
            TREE[l_pos] = left;
        }

        printf("do you want right child for %c (y/n): ", TREE[root_pos]);
        scanf(" %c", &ch);
        r_pos = 2*root_pos+2;
        TREE[r_pos] = '_';
        if(ch == 'y')
        {
            printf("Enter value in right child: ");
            scanf(" %c", &right);
            TREE[r_pos] = right;
        }

        display();
        node_count++;
        if(node_count == SIZE)
        {
            break;
        }
        printf("childre assigned for %c, do you want to continue(y/n): ", TREE[root_pos]);
        scanf(" %c", &choice);
        do
        {
            root_pos++;
        }while(TREE[root_pos] == '_');
    }while(choice == 'y');
}

void display()
{
    for(int i = 0; i < SIZE; i++)
    {
        printf("%c ", TREE[i]);
    }
    printf("\n");
}
