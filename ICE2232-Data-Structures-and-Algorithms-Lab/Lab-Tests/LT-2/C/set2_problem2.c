// ICE2232 - Data Structures and Algorithms Lab
// Exam - 2022
// Lab Test: 2
// Set: 2
// Problem No: 2
// Solution by: Saifullah (ICE 21)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// node structe
struct Node
{
    char data;
    struct Node *next;
};

// queue structure
struct Queue
{
    struct Node *front;
    struct Node *rear;
};

// to intialise the queue
struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    if (queue == NULL)
    {
        perror("Memory allocation failed!\n");
        exit(1);
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// if the queue is empty!
bool empty(struct Queue *queue)
{
    return queue->front == NULL;
}

// enqueue data into the queue
void enqueue(struct Queue *queue, char val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // if memory allocated properly!
    if (newNode == NULL) // due to memory overflow or system error
    {
        perror("Memory Allocation failed / Overflow!\n");
        exit(1);
    }

    // set values
    newNode->data = val;
    newNode->next = NULL;

    // add new node at the end of the queue
    if (empty(queue) == true)
    {
        // if the queue is empty
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    return;
}

//dequeue data from the queue
char dequeue(struct Queue *queue)
{
    // if the queue is empty
    if (empty(queue) == true)
    {
        printf("Underflow!\n\n");
        return 0;
    }
    // store the data of front node
    char val = queue->front->data;

    struct Node *temp = queue->front;
    queue->front = queue->front->next;

    // free memory of front node
    free(temp);
    return val;
}

int main()
{
    // intialising queue
    struct Queue *queue = createQueue();

    // enqueue data
    enqueue(queue, 'a');
    enqueue(queue, 'b');
    enqueue(queue, 'c');
    enqueue(queue, 'd');

    // dqueue data
    while (empty(queue) == false)
    {
        printf("%c ", dequeue(queue));
    }
    return 0;
}