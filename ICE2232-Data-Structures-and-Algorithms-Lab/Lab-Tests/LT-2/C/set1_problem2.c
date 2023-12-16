// ICE2232 - Data Structures and Algorithms Lab
// Exam - 2022
// Lab Test: 2
// Set: 1
// Problem No: 2
// Solution by: Saifullah (ICE 21)

// topics: structure, stack, dynamic memory

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// node structure
struct Node
{
    char data;
    struct Node *next;
};

// stack structure
struct Stack
{
    struct Node *top;
};

// to initialise the stack
struct Stack* createStack()
{
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
    if( stack == NULL )
    {
        perror("Memory allocation failed!\n");
        exit(1);
    }
    stack->top = NULL;
    return stack;
}

// if the stack is empty
bool empty(struct Stack *stack)
{
    return stack->top == NULL;
}

// to push data into stack
void push(struct Stack *stack, char val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if ( newNode == NULL) // due to memory overflow or system error
    {
        perror("Memory Allocation failed!\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = stack->top;

    stack->top = newNode;
    return;
}

// to pop data from stack
char pop( struct Stack *stack )
{
    if( stack->top == NULL )
    {
        printf("The stack is empty!\n\n");
        return 0;
    }
    char val = stack->top->data;
    struct Node *temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return val;
}

int main()
{
    struct Stack *stack = createStack();
    push(stack,'a');
    push(stack,'b');
    push(stack,'c');
    push(stack,'d');
    while( empty(stack) == false )
    {
        printf("%c ", pop(stack));
    }
    return 0;
}