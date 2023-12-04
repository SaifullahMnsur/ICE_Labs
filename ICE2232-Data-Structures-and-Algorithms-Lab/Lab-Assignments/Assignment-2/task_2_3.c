#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *rehead = NULL;
int size = 0;
// declaring functions which are written after main function
void push_front(int val);
void show();
void free_memory();

////*****main part starts here****///

// traversing through the list
void traverse(struct node *current, int n)
{
    if (current == NULL)
        return;
    traverse(current->next, n + 1); // traversing to the next node
    if (n == size / 2 + 1)
        current->next = NULL; // setting the size/2+1 th node as the last node and the next node after it is nullptr
    else if (n > size / 2)    // inserting nth node in between of rehead and the next element of rehead
    {
        struct node *temp = rehead->next; // storing the next node address after rehead
        current->next = rehead->next;     // setting rehead's next as the nth node's next node
        rehead->next = current;           // rehead's next is nth node
        rehead = temp;                    // setting stored note address as the new head, new node must be linked after this
    }
    return;
}
// to call for reordering the list
void reorder()
{
    if (head == NULL || head->next == NULL)
        return;
    rehead = head;               // setting the head as the rehead, rehead used to reorder
    int n = 1;                   // position of element
    traverse(head->next, n + 1); // beginning the traversal
}

int main()
{
    for (int i = 11; i >= 1; i--)
        push_front(i);
    show();
    reorder();
    show();
    free_memory();
}

// necessarry things
void free_memory()
{
    struct node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
void show()
{
    struct node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("nullptr\n\n");
}
void push_front(int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
    size++;
}