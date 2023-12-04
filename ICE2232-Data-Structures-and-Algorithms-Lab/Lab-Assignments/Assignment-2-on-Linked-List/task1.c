#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;// declaring the head globally

void insertAtEnd( int val )
{
    struct node *newNode;// pointer to store the memory location that has been allocated
    newNode = (struct node*)malloc(sizeof(struct node));// allocating memory
    newNode->data = val;// setting value to the new allocated node
    newNode->next = NULL;// setting the next node as NULL
    if( head == NULL )// if the head is empty then the new node should be the head and no other operation is needed
    {
        head = newNode;// setting new node as the head
        return;
    }
    struct node *curr = head;// pointer to iterate through the linked list and reach the ending
    while( curr->next != NULL )// untill the next node is null my current node is not the last node
    {
        curr = curr->next;// going to the next node
    }
    curr->next = newNode;// linking the new node after the current last node of the list
}

void insertAtBegin( int val )
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    if( head == NULL )
    {
        head = newNode;
        return;
    }
    newNode->next = head;// new node must point current head as it's next node
    head = newNode;// and new node should be the new head
}
void free_memory()
{
    while( head != NULL )// untill the head is not null which means it is a node and memory has been allocated for it
    {
        struct node *temp = head->next;// temporary node pointer to store the next node of the head
        free(head);// deallocating head
        head = temp;// setting temp as the new head because now it is the first node of the list
    }
}

void print()
{
    struct node* curr = head;// setting head to iterate through the list
    while( curr != NULL )
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

int main()
{
    insertAtEnd(123);// inserting 123 at the end
    insertAtEnd(321);// inserting 321 at the end
    insertAtBegin(987);// inserting 987 at the beginning
    print();// to print the whole linked list
    free_memory();// to deallocte the memory
}