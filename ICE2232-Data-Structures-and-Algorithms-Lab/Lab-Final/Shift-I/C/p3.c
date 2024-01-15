#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct BST
{
    struct Node *root;
};

struct BST *bstInitialize()
{
    struct BST *bst = (struct BST *)malloc(sizeof(struct BST));
    bst->root = NULL;
    return bst;
}

void insert(struct Node **root, int val)
{
    if ((*root) == NULL)
    {
        *root = (struct Node *)malloc(sizeof(struct Node));
        if( *root == NULL )
        {
            perror("Memory Allocation failed!\n");
            exit(1);
        }
        (*root)->data = val;
        (*root)->left = (*root)->right = NULL;
        return;
    }
    if (val < (*root)->data)
        insert(&(*root)->left, val);
    else
        insert(&(*root)->right, val);
    return;
}

void printGreater(struct Node **root, int val)
{
    if (*root == NULL)
        return;
    printGreater(&(*root)->left, val);
    if( (*root)->data >= val )
        printf("%d ", (*root)->data);
    printGreater(&(*root)->right, val);
    return;
}

void preOrder(struct Node **root)
{
    if (*root == NULL)
        return;
    printf("%d ", (*root)->data);
    preOrder(&(*root)->left);
    preOrder(&(*root)->right);
    return;
}

void inOrder(struct Node **root)
{
    if (*root == NULL)
        return;
    inOrder(&(*root)->left);
    printf("%d ", (*root)->data);
    inOrder(&(*root)->right);
    return;
}

void postOrder(struct Node **root)
{
    if (*root == NULL)
        return;
    postOrder(&(*root)->left);
    printf("%d ", (*root)->data);
    postOrder(&(*root)->right);
    return;
}

int main()
{
    struct BST *bst = bstInitialize();

    int choice = -1, val;
    do
    {
        printf("1. Insert\n");
        printf("2. Pre-order\n");
        printf("3. In-order\n");
        printf("4. Post-Order\n");
        printf("5. Print greater than given value\n");
        printf("0. End program\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter a value: ");
            scanf("%d", &val);
            insert(&bst->root, val);
        }
        else if (choice == 2)
            preOrder(&bst->root);
        else if (choice == 3)
            inOrder(&bst->root);
        else if (choice == 4)
            postOrder(&bst->root);
        else if (choice == 5)
        {
            printf("Enter a value: ");
            scanf("%d", &val);
            printGreater(&bst->root, val);
        }
        else if (choice != 0)
            printf("Wrong choice! try again!\n");
        printf("\n");
    } while (choice != 0);
    return 0;
}