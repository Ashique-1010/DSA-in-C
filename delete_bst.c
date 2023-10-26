/*
binary search tree

create nbinary tree with usual method
    recusrively call for each subtree
    accpet value for root node
        from next node, check greater or less
            if value less create left child
            else create right child
        always compare with root node, and go down the hierarchy

maintain root node, while new node value. check with root node,
                    if less check with left child, if greater check with right child
                        until adress of child becomes null.
*/
//check with traversal method, recursion bitcomplex will work on it
#include <stdio.h>
#include <stdlib.h>
#define COUNT 10

struct node
{
    int data;
    struct node *left, *right;
}*root = NULL;

void insert_node();
struct node* search_node(int n, struct node *temp);
void delete_node(int);
void InOrder(struct node *ptr);
void print2DUtil(struct node* ptr1, int space);
void print2D(struct node* ptr2);
struct node* get_parent(struct node *child, struct node *parent);
int child_number(struct node *ptr);
struct node* get_inorder_successor(struct node *current_node);

void main()
{
    int ch, num;
    char choice;
    struct node *succ, *addr;
    do
    {
        printf("Select option: 1.Insert  2.Search  3.Delete 4.Display  5.inordersucc  :  ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                insert_node();
                break;

            case 2:
                printf("Enter number to search: ");
                scanf("%d", &num);
                search_node(num, root);
                break;

            case 3:
                printf("Enter number to delete: ");
                scanf("%d", &num);
                delete_node(num);
                break;

            case 4:
                printf("Inorder of bst:\n");
                InOrder(root);
                printf("\n");
                print2D(root);
                break;

            case 5:
                printf("Enter value to get inorder successor: ");
                scanf("%d", &num);
                addr = search_node(num, root);
                printf("address of %d in tree is %p\n", num, addr);
                succ = get_inorder_successor(addr);
                printf("Inorder successor of %d is %d\n", num, succ-> data);
                break;

            default:
                printf("Invalid\n");
        }
        printf("continue(y/n): ");
        scanf(" %c", &choice);
    }while(choice == 'y');


}

void insert_node()
{
    int x;
    struct node *new_node, *temp;
    printf("Enter data for tree, (-1) to exit: ");
    scanf("%d", &x);

    new_node = (struct node*)malloc(sizeof(struct node));
    if(x == -1)
    {
        free(new_node);
        return;
    }
    new_node-> data = x;
    new_node-> left = NULL;
    new_node-> right = NULL;

    if(root == NULL)
    {
        root = new_node;
        return;
    }
    else
    {
        temp = root;
        while(temp != NULL)
        {
            if(x < temp-> data)
            {
                if(temp-> left == NULL)
                {
                    temp-> left = new_node;
                    return;
                }
                else
                {
                    temp = temp-> left;
                }
            }
            else
            {
                if(temp-> right == NULL)
                {
                    temp-> right = new_node;
                    return;
                }
                else
                {
                    temp = temp-> right;
                }
            }
        }
    }
}


void InOrder(struct node *ptr)
{
    if(ptr == NULL)
    {
        return;
    }
    InOrder(ptr-> left);
    printf("%d ", ptr-> data);
    InOrder(ptr-> right);
}

void print2DUtil(struct node* ptr1, int space)
{
    // Base case
    if (ptr1 == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(ptr1->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", ptr1->data);

    // Process left child
    print2DUtil(ptr1->left, space);
}

// Wrapper over print2DUtil()
void print2D(struct node* ptr2)
{
    // Pass initial space count as 0
    print2DUtil(ptr2, 0);
}

struct node* search_node(int n, struct node *temp )
{
    if(n == temp-> data)
    {
        printf("%d is found\n", n);
        return temp;
    }
    if((temp-> left == NULL && temp-> right == NULL) && (n != temp-> data))
    {
        printf("%d is not found\n", n);
        return NULL;
    }
    else if(n < temp-> data)
    {
        search_node(n, temp-> left);
    }
    else if(n > temp-> data)
    {
        search_node(n, temp-> right);
    }
    else
    {
        printf("not found\n");
        return NULL;
    }

}

void delete_node(int n)
{
    struct node *daddy, *kid, *node, *Ino;
    node = search_node(n, root);

    if(child_number(node) == 0)
    {
        daddy = get_parent(node, root);
        kid = node;
        if(daddy-> left == node)
        {
            daddy-> left = NULL;
            printf("%d is deleted\n", node-> data);
            free(kid);
        }
        if(daddy-> right == node)
        {
            daddy-> right = NULL;
            printf("%d is deleted\n", node-> data);
            free(kid);
        }
    }
    if(child_number(node) == 1)
    {
        daddy = get_parent(node, root);
        kid = node;
        if(daddy-> left == node)
        {
            if(node-> left != NULL)
            {
                daddy->left = node-> left;
                printf("%d is deleted\n", node-> data);
                free(kid);
            }
            else
            {
                daddy-> left = node-> right;
                printf("%d is deleted\n", node-> data);
                free(kid);
            }
        }
        if(daddy-> right == node)
        {
            if(node-> left != NULL)
            {
                daddy->right = node-> left;
                printf("%d is deleted\n", node-> data);
                free(kid);
            }
            else
            {
                daddy-> right = node-> right;
                printf("%d is deleted\n", node-> data);
                free(kid);
            }
        }
    }
    if(child_number(node) == 2)
    {
        Ino = get_inorder_successor(node);
        daddy = node;
        if(Ino-> left == NULL && Ino-> right == NULL)
        {
            Ino-> left = node-> left;
            Ino-> right = node-> right;
        }
        else
        {
            Ino-> left = node-> left;
        }
        free(daddy);
        printf("%d is deleted\n", node-> data);
    }
}

int child_number(struct node *ptr)
{
    if(ptr-> left == NULL && ptr-> right == NULL)
    {
        return 0;
    }
    else if((ptr-> left != NULL && ptr-> right == NULL) || (ptr-> left == NULL && ptr-> right != NULL))
    {
        return 1;
    }
    else if(ptr-> left != NULL && ptr-> right != NULL)
    {
        return 2;
    }
    else
    {
        return -1;
    }
}

struct node* get_parent(struct node *child, struct node *parent)
{

    if(parent-> left == child || parent-> right == child)
    {
        return parent;
    }
    else if(child-> data < parent-> data)
    {
        get_parent(child, parent-> left);
    }
    else if(child-> data > parent-> data)
    {
        get_parent(child, parent-> right);
    }
    else
    {
        return NULL;
    }
}

struct node* get_inorder_successor(struct node *current_node)
{
    struct node *temp, *Ino;

    if(current_node-> right-> left == NULL)
    {
        return current_node-> right;
    }
    else
    {
        temp = current_node-> right-> left;
        while(temp != NULL)
        {
            Ino = temp;
            temp = temp-> left;
        }
        return Ino;
    }
}
