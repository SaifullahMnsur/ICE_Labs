// ICE2232 - Data Structures and Algorithms Lab
// Exam - 2022
// Assignment - 3

// Task No: 1
// Solution by: Saifullah (ICE 21)

// Purpose of this dynamic array implementation is to change the capacity along with the need during runtime

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int *sqArr = NULL;  // int pointer for stack to allocate dynamic memory during runtime
int capacity = 10;   // capacity of the stack/queue array
bool qstate = true; // by default it is queue mode
int top = -1;       // top of the stack
int front = -1;     // front of the queue

void setup_sqArr()
{
    sqArr = (int *)malloc(sizeof(int) * capacity); // allocating memory for MAX number of integer size
    if (sqArr == NULL)                             // if memory allocationg is faild
    {
        perror("Memory allocation faild!\n\n"); // error message
        exit(1);                                // exiting the program with an error message
    }
    capacity = 10;
    top = -1;
    front = -1;
    return;
}
void increase_sqArr()
{
    capacity = capacity * 2;                               // doubling the capacity
    sqArr = (int *)realloc(sqArr, sizeof(int) * capacity); // reallocating with a new capacity of sqArr
    if (sqArr == NULL)                                     // if memory allocationg is faild
    {
        perror("Memory allocation faild!\n\n"); // error message
        exit(1);                                // exiting the program with an error message
    }
    printf("Stack/Queue capacity increased\n");
    return;
}
// if sqArr is empty
bool empty()
{
    return front > top || top == -1;
}
// if sqArr is full 
bool full()
{
    return top == capacity-1;
}
// pop element from the stack/queue
void pop()
{
    // if the array is empty
    if (empty() == true)
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
        printf("Popped %d\n\n", sqArr[top]);
        front++;
    }
    // if stack mode was enabled
    else
    {
        printf("Popped %d\n\n", sqArr[top]);
        top--;
    }
    return;
}

// push value into the stack/queue
void push(int val)
{
    if ( full() == true ) // if we exceed the current capacity
    {
        increase_sqArr();
    }

    top++;
    // for first input
    if (front == -1)
        front++;

    // add the value
    sqArr[top] = val;
    return;
}

// print the stack/queue
void print()
{
    // if queue mode was enabled
    if (qstate == true)
    {
        // if there is no elements
        if (empty() == true)
        {
            printf("Your queue is empty!\n\n");
            return;
        }

        printf("Your queue is: ");
        for (int i = front; i <= top; i++)
        {
            printf("%d ", sqArr[i]);
        }
        printf("\n\n");
    }
    // if stack mode was enabled
    else
    {
        // if there is no elements
        if (empty() == true)
        {
            printf("Your stack is empty!\n\n");
            return;
        }

        printf("Your stack is:\n");
        for (int i = top; i >= front; i--)
        {
            printf("%d\n", sqArr[i]);
        }
        printf("\n");
    }
    return;
}

int main()
{
    setup_sqArr(); // setup stack
    while (true)
    {
        char input[50];
        // take an input
        scanf("%s", input);

        // strcmp() function compares two string if there are any difference or not
        // if there are no difference it return 0 else 1

        // if input is Q
        if (strcmp(input, "Q") == 0)
        {
            print();
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
            // converting the string input to a number
            int num = 0;
            bool valid = true;
            for (int i = 0; input[i] != '\0'; i++)
            {
                // if input is a valid integer
                if (input[i] < '0' || input[i] >= '9' || i > 9)
                {
                    printf("Invalid input\nEnter a valid input!\n");
                    valid = false; // make validity false
                    break; // exit the loop
                }

                // add to the number
                num = num * 10 + input[i] - '0';
            }
            // for invalid it will go to next iteration
            if (valid == false)
                continue;

            // push input integer into stack/queue
            push(num);
        }

        // print stack/queue
        print();
    }
    return 0;
}