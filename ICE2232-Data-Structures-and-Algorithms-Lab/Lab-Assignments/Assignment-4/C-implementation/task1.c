// ICE2232 - Data Structures and Algorithms Lab
// Exam - 2022
// Assignment: 4

// Task: 1
// Solution by: Saifullah (ICE 21)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct Node
{
    int data;
    struct Node *right, *left; // left and right node's pointer
};

void deallocate(struct Node **root)
{
    if ((*root) == NULL)
        return;
    // going deeper into the BST
    deallocate(&(*root)->left);  // deallocating left subtree
    deallocate(&(*root)->right); // deallocating right subtree
    // at the deepest point delete the node
    free(*root);
    // set the pointer null
    (*root) = NULL;
}
void setValue(struct Node *root, int val)
{
    root->data = val;
    root->left = NULL;
    root->right = NULL;
    return;
}

void insert(struct Node **root, int val)
{
    if (*root == NULL)
    {
        *root = (struct Node *)malloc(sizeof(struct Node)); // when no node is present in the BST, set new value's node as root
        setValue(*root, val);
        return;
    }

    if (val < (*root)->data)          // if val is less than current root's value
        insert(&(*root)->left, val);  // the val must be at the left subtree
    else                              // if val is not less than current root's value
        insert(&(*root)->right, val); // tha val must be at the right subtree
    return;
}

bool find(struct Node *root, int val)
{
    if (root == NULL) // if no node is available
        return false;
    if (root->data == val) // if current root's value is equal to val
        return true;

    if (val < root->data)               // if val is less than current root's value
        return find(root->left, val);  // the val must be at the left subtree
    else                                   // if val is not less than current root's value
        return find(root->right, val); // tha val must be at the right subtree
}

int pathLength(struct Node *root, int depth)
{
    if (root == NULL)
        return 0;

    int leftDepth = pathLength(root->left, depth + 1);   // calculating path length of left subtree
    int rightDepth = pathLength(root->right, depth + 1); // calculating path length of right subtree

    return depth + leftDepth + rightDepth;
}

void preOrder(struct Node *root)
{
    if (root == NULL) // if no node is available
        return;

    printf("%d ", root->data); // processesing before going deeper, it is called pre order

    preOrder(root->left);  // going into left subtree
    preOrder(root->right); // going into right subtree
}

void inOrder(struct Node *root)
{
    if (root == NULL) // if no node is available
        return;

    inOrder(root->left); // going into left subtree

    printf("%d ", root->data); // processesing between going deeper left and right, it is called in order

    inOrder(root->right); // going into right subtree
}

void postOrder(struct Node *root)
{
    if (root == NULL) // if no root is available
        return;

    postOrder(root->left);  // going into left subtree
    postOrder(root->right); // going into right subtree

    printf("%d ", root->data); // processesing after going deeper, it is called post order
}

int main()
{
    struct Node *bstRoot = NULL;

    printf("Instructions:\n");
    printf("ins : insert into the BST\n");
    printf("f : find the integer into the BST\n");
    printf("p : path length of the BST\n");
    printf("pre : Pre-Order traversal\n");
    printf("in : In-Order traversal\n");
    printf("post : Post-Order traversal\n");
    printf("0 : exit\n\n");

    char input[50];
    int val;
    do
    {
        scanf("%s", input);
        if (strcmp(input, "ins") == 0)
        {
            scanf("%d", &val);
            insert(&bstRoot, val);
        }
        else if (strcmp(input, "f") == 0)
        {
            scanf("%d", &val);
            if (find(bstRoot, val) == true)
                printf("Yes\n");
            else
                printf("No\n");
        }
        else if (strcmp(input, "p") == 0)
            printf("Path length of the given BST: %d\n", pathLength(bstRoot, 0));
        else if (strcmp(input, "pre") == 0)
            preOrder(bstRoot);
        else if (strcmp(input, "in") == 0)
            inOrder(bstRoot);
        else if (strcmp(input, "post") == 0)
            postOrder(bstRoot);
        else if (strcmp(input, "0") != 0)
            printf("Wrong input! try again!\n");
        printf("\n");
    } while (strcmp(input, "0") != 0);

    printf("Program finished!\n\n");
    deallocate(&bstRoot);
    return 0;
}