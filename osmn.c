#include <stdio.h>
#include <stdlib.h>

typedef struct node_s
{
    struct node_s *left;
    struct node_s *right;
    int value;
} node;

node *allocate(int value);
node *planTree(int value);
void insert(node *root, int value);
void printPreOrder(node *root);
void printInOrder(node *root);
void printPostOrder(node *root);

int main(void)
{
    int c, n, x, value;
    scanf("%d", &c);
    for (x = 1; x <= c; x++)
    {
        scanf("%d", &n);
        scanf("%d", &value);
        node *root = planTree(value);
        while (--n)
        {
            scanf("%d", &value);
            insert(root, value);
        }
        printf("Case %d:\n", x);
        printf("Pre.:");
        printPreOrder(root);
        printf("\n");
        printf("In..:");
        printInOrder(root);
        printf("\n");
        printf("Post:");
        printPostOrder(root);
        printf("\n\n");
        free(root);
    }
    return 0;
}

node *allocate(int value)
{
    node *new = (node *)malloc(sizeof(node));
    new->value = value;
    return new;
}

node *planTree(int value)
{
    node *root = allocate(value);
    root->left = root->right = NULL;
    return root;
}

void insert(node *root, int value)
{
    if (value <= root->value)
    {
        if (root->left == NULL)
        {
            node *leave = allocate(value);
            leave->left = leave->right = NULL;
            root->left = leave;
            return;
        }
        else
        {
            insert(root->left, value);
        }
    }
    else
    {
        if (root->right == NULL)
        {
            node *leave = allocate(value);
            leave->left = leave->right = NULL;
            root->right = leave;
            return;
        }
        else
        {
            insert(root->right, value);
        }
    }
    return;
}

void printPreOrder(node *root)
{
    if (root == NULL)
        return;
    printf(" %d", root->value);
    printPreOrder(root->left);
    printPreOrder(root->right);
    return;
}

void printInOrder(node *root)
{
    if (root == NULL)
        return;
    printInOrder(root->left);
    printf(" %d", root->value);
    printInOrder(root->right);
    return;
}

void printPostOrder(node *root)
{
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf(" %d", root->value);
    return;
}
