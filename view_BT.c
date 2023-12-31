

#include <stdio.h>
#include <stdlib.h>

#define COUNT 10

struct node
{
    int data;
    struct node *left, *right;
};

struct node* create_node();
void print2DUtil(struct node* root, int space);
void print2D(struct node* root);

void main()
{
    struct node *root;
    root = create_node();
    print2D(root);
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
