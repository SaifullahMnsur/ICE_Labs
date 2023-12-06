// ICE2232 - Data Structures and Algorithms Lab
// Exam - 2022
// Lab Test: 2
// Set: 1
// Problem No: 1
// Solution by: Saifullah (ICE 21)

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *right, *left;
};

// insert a value into the BST
void insert(struct Node **root, int val)
{
    // when root is null, we can attach our node their
    if ((*root) == NULL)
    {
        *root = (struct Node *)malloc(sizeof(struct Node));
        if( *root == NULL ) // due to memory overflow or system error
        {
            perror("Memory Allocation failed!\n");
            exit(1);
        }
        (*root)->data = val; // assign value
        (*root)->left = (*root)->right = NULL; // assign left and right subtree
        return;
    }
    // if the value is less than current root's data then the value must be placed in left subtree
    if (val < (*root)->data)
        insert(&(*root)->left, val);
    // if the value is not less than current root's data then the value must be placed in right subtree
    else
        insert(&(*root)->right, val);
    return;
}

// in-order traversal processes data in ascending order
void inOrder(struct Node **root)
{
    // after reacher end of a subtree, return
    if (*root == NULL)
        return;
    // go to left subtree
    inOrder(&(*root)->left);
    // process data, in this case print
    printf("%d ", (*root)->data);
    // go to right subtree
    inOrder(&(*root)->right);
}

// find the node with given value
struct Node *find(struct Node **root, int val)
{
    if ((*root)->data == val)
        return *root;
    if (val < (*root)->data)
        return find(&(*root)->left, val);
    else
        return find(&(*root)->right, val);
}

// calculate height of the node of the given value
int calHeight(struct Node **root, int ht)
{
    if (*root == NULL)
        return ht-1;
    int left = calHeight(&(*root)->left, ht+1);
    int right = calHeight(&(*root)->right, ht+1);
    if( left > right )
        return left;
    else
        return right;
}
int findHeight(struct Node **root, int val)
{
    // find the node of given value
    struct Node *valNode = find(&(*root), val);
    // if the value is not found
    if( valNode == NULL )
    {
        printf("%d is not found in the BST\n\n");
        return 0;
    }
    // return the height
    return calHeight(&valNode, 0);
}
int main()
{
    struct Node *bstRoot = NULL;
    int choose, val, height;
    do
    {
        printf("\n1: insert\n");
        printf("2: In-order Traverse\n");
        printf("3: Height of a node\n");
        printf("-1: Exit\n\n");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            // insert a value into the BST at it's correct position
            printf("Enter value to insert: ");
            scanf("%d", &val);
            insert(&bstRoot, val);
            break;
        case 2:
            // traverse the BST in-order
            printf("In-order traversal is: ");
            inOrder(&bstRoot);
            printf("\n\n");
            break;
        case 3:
            // find the height of the node of a given value
            // height is the maximum distance from a given node to any leaf node
            printf("Enter a value of node: ");
            scanf("%d", &val);
            height = findHeight(&bstRoot, val);
            printf("Height of %d is : %d", val, height);
            break;
        case -1:
            printf("\nEnding program!\n\n");
        default:
            break;
        }
    } while (choose != -1);
    return 0;
}