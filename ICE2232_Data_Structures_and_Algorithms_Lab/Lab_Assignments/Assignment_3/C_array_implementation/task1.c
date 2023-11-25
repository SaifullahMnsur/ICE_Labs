#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 1000 // maximum size of the stack queue array
int sqArray[MAX]; // stack queue array
bool qstate = true; // by default it is queue mode
int top = -1; // top of the stack
int front = -1; // front of the queue

bool empty()
{
    return front > top;
}

// pop element from the stack/queue
void pop()
{
    // if the array is empty 
    if ( empty() ) 
    {
        if (qstate == true)
            printf("The queue is empty!\n");
        else
            printf("The stack is empty!\n");
        return;
    }

    // if queue mode was enabled
    if (qstate == true) 
    {
        front++;
    }
    // if stack mode was enabled
    else 
    {
        top--;
    }
    return;
}

// push value into the stack/queue
void push(int val)
{
    top++;
    if (top == MAX) // if we reached the maximum elements limit
    {
        // if it is queue state
        if (qstate == true)
            printf("The queue is full!\n");
        // if it is stack state
        else
            printf("The stack is full!\n");

        top--;
        return;
    }

    // for first input
    if (front == -1)
        front++;

    // add the value
    sqArray[top] = val;
    return;
}

// print the stack/queue
void print()
{
    // if queue mode was enabled
    if (qstate == true) 
    {
        // if there is no elements
        if( empty() ) 
        {
            printf("Your queue is empty!\n\n");
            return;
        }

        printf("Your queue is: ");
        for (int i = front; i <= top; i++)
        {
            printf("%d ", sqArray[i]);
        }
        printf("\n\n");
    }
    // if stack mode was enabled
    else 
    {
        // if there is no elements
        if( empty() ) 
        {
            printf("Your stack is empty!\n\n");
            return;
        }

        printf("Your stack is:\n");
        for (int i = top; i >= front; i--)
        {
            printf("%d\n", sqArray[i]);
        }
        printf("\n");
    }
    return;
}

int main()
{
    while (true)
    {
        char input[50];
        // take an input
        scanf("%s", input);

        // if input is Q
        if (strcmp(input, "Q") == 0) 
        {
            printf("Program ended here\n");
            return 0;
        }

        // if input is q
        else if (strcmp(input, "q") == 0) 
        {
            printf("QUEUE MODE enabled\n");
            qstate = true; // queue mode
        }

        // if input is s
        else if (strcmp(input, "s") == 0) 
        {
            printf("STACK MODE enabled\n");
            qstate = false; // stack mode
        }

        // if input is p
        else if (strcmp(input, "p") == 0) 
        {
            pop(); // deleting element from stack/queue
        }

        // if input is anything else
        else 
        {
            int num = 0;
            for (int i = 0; input[i] != '\0'; i++)
            {
                // if input is a valid integer
                if (input[i] < '0' || input[i] >= '9' || i > 9) 
                {
                    printf("Invalid input\nEnter a valid input!\n");
                    continue;
                }

                // add to the number
                num = num * 10 + input[i] - '0';
            }

            // push input integer into stack/queue
            push(num); 
        }

        // print stack/queue
        print();
    }
    return 0;
}