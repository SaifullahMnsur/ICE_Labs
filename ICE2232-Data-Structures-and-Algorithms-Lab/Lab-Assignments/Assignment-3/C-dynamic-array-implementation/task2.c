// ICE2232 - Data Structures and Algorithms Lab
// Exam - 2022
// Assignment - 3

// Task No: 2
// Solution by: Saifullah (ICE 21)

// Purpose of this dynamic array implementation is to change the capacity along with the need during runtime

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *stack = NULL; // int pointer for stack to allocate dynamic memory during runtime
int capacity = 1;  // capacity of the stack/queue array
int top = -1;      // top of the stack

// setup the stack
void setupStack()
{
    stack = (int *)malloc(sizeof(int) * capacity); // allocating memory for MAX number of integer size
    if (stack == NULL)                             // if memory allocationg is faild
    {
        perror("Memory allocation faild!\n\n"); // error message
        exit(1);                                // exiting the program with an error message
    }
    top = -1;
    return;
}
// increase stack capacity
void increaseStack()
{
    capacity = capacity * 2;                               // doubling the capacity
    stack = (int *)realloc(stack, sizeof(int) * capacity); // reallocating with a new capacity of stack
    if (stack == NULL)                                     // if memory allocationg is faild
    {
        perror("Memory allocation faild!\n\n"); // error message
        exit(1);                                // exiting the program with an error message
    }
    return;
}

// check if stack is empty
bool empty()
{
    return top < 0;
}
// check if stack is full
bool full()
{
    return top == capacity - 1;
}
// push an element onto the stack
void push(int value)
{
    if (full() == true)
    {
        increaseStack();
    }
    stack[++top] = value;
    return;
}
// pop an element from the stack
int pop()
{
    if (empty() == true)
    {
        printf("Stack is already empty!\n");
        return -1; // You may choose a different value to indicate an error
    }
    else
    {
        return stack[top--];
    }
}

// quicksort operations are here

// swap two elements in the array
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// partition the array and returning the index of the pivot element
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1; // tracks the indices which are smaller than pivot

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }

    // swap pivot point and next index of i
    swap(arr, i + 1, high);
    return i + 1;
}

// Quicksort using the global stack
void quicksort(int arr[], int low, int high)
{
    // set up a dynamic memory for stack, allocated memory can be treated as an array
    setupStack();
    // push initial values of low and high to the stack
    push(low);
    push(high);

    // continue popping from the stack until it is empty
    while (empty() == false)
    {
        // pop high and low
        high = pop();
        low = pop();

        // partition the array
        int pivotIndex = partition(arr, low, high);

        // if there are elements on the left side of the pivot, push them to the stack
        if (pivotIndex - 1 > low)
        {
            push(low);
            push(pivotIndex - 1);
        }

        // if there are elements on the right side of the pivot, push them to the stack
        if (pivotIndex + 1 < high)
        {
            push(pivotIndex + 1);
            push(high);
        }
    }

    // free stack memory
    free(stack);
}

// function to print an array
void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

int main()
{
    int size;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
    int arr[size];

    printf("Enter the array: ");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    printf("\nInput array: ");
    printArr(arr, size);

    quicksort(arr, 0, size - 1);

    printf("Sorted array: ");
    printArr(arr, size);
    return 0;
}
