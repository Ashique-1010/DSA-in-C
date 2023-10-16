/*
recursively implement creation of nodes

construct a function to create root node
    recieve data for node
    set anchor condition to return to function call
        recusrively call create function for left child
        recursively call create function for right child
    after creation of all nodes, the recusdive calls will return adrress of root node
This will create all left nodes then right nodes
*/

#include <stdio.h>
#include <stdlib.h>

#define COUNT 10

struct node
{
    int data;
    struct node *left, *right;
};

struct node* create_node();
void PreOrder(struct node *);
void InOrder(struct node *);
void PostOrder(struct node *);
void print2D(struct node* root);
void print2DUtil(struct node* root, int space);

void main()
{
    struct node *root;
    root = create_node();
    print2D(root);
    printf("\n");
    printf("PreOrder of tree:    ");
    PreOrder(root);
    printf("\nInOrder of tree:   ");
    InOrder(root);
    printf("\nPostorder of tree: ");
    PostOrder(root);
}

struct node* create_node()
{
    int x;
    struct node *new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter data to node(-1 for no node): ");
    scanf("%d", &x);

    if(x == -1)
    {
        return NULL;
    }
    new_node-> data = x;

    printf("Enter left child of %d: \n", x);
    new_node-> left = create_node();
    printf("Enter right child of %d: \n", x);
    new_node-> right = create_node();

    return new_node;
}

void PreOrder(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    printf("%d ", root-> data);
    PreOrder(root-> left);
    PreOrder(root-> right);
}

void InOrder(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    InOrder(root-> left);
    printf("%d ", root-> data);
    InOrder(root-> right);
}

void PostOrder(struct node *root)
{
    if(root == NULL)
    {
        return;
    }
    PostOrder(root-> left);
    PostOrder(root-> right);
    printf("%d ", root-> data);
}

// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(struct node* root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(struct node* root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}
