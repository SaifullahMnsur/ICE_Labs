#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// declaring all the user defined functions that are being used in this code
void swap(int *a, int *b);
void recover_unsorted_array(int a[], int b[], int n);
void printer(int a[], int n);
void selection_sort(int a[], int n);
void bubble_sort(int a[], int n);
void insertion_sort(int a[], int n);
void input_array(int a[], int b[], int n);
void task_function();

int main()
{
    srand(time(0)); // connceting random number genarator with current time so that we get different numbers each time
    int test_again = 1;
    do
    {
        task_function(); // task function the main function to do all the task of getting, sorting and showing the array
        printf("Enter 0 to exit or anything else to Enter a new array!\n");
        scanf("%d", &test_again);
    } while (test_again != 0);
    printf("THANK YOU!");
    return 0;
}

void task_function()
{
    int n;
    printf("Enter the number elements in the array: ");
    scanf("%d", &n);
    int a[n], b[n];
    input_array(a, b, n); // b is backup array
    int again = 1; // assuming you will sort again with the same array!
    do
    {
        int algo;
        printf("\nChoose a sorting algorithm:\n");
        printf("1. Selection sort\n");
        printf("2. Bubble sort\n");
        printf("3. Insertion sort\n");
        scanf("%d", &algo);
        bool error = false;
        switch (algo)
        {
        case 1:
            selection_sort(a, n);
            break;
        case 2:
            bubble_sort(a, n);
            break;
        case 3:
            insertion_sort(a, n);
            break;
        default:
            printf("Entered wrong input!");
            error = true;
            break;
        }
        printf("\nSorted array: ");
        printer(a, n);
        if (error == false)
        {
            printf("Enter 0 to end operations with this array or anything else to sort again!\n");
            scanf("%d", &again);
            if (again != 0)
            {
                // if you want to apply any other sorting algorithm again then retrive the original array
                recover_unsorted_array(a, b, n);
            }
        }
    } while (again != 0);
    printf("*Execution ends with the current array!*\n");
    return;
}

void input_array(int a[], int b[], int n)
{
    printf("Enter the array: ");
    for (int i = 0; i < n; i++)
    {
        //scanf("%d", &a[i]);
        a[i] = rand()%100; // genarating random numbers and limitng it under 100
        b[i] = a[i]; // having a backup of the input array to retrive it
    }
    return;
}

void swap(int *a, int *b)
{
    // swap the value between addresses
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void selection_sort(int a[], int n)
{
    printf("*Applying SELECTION SORT algorithm*\n");
    // Basic: bring the minimum element to front
    for (int i = 0; i < n; i++)
    {
        // outer loop is for indices
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            // inner loop is for detecting minimum element's index
            if (a[min] > a[j])
                min = j;
        }
        // now swap i and min index
        swap(&a[i], &a[min]);
    }
    printf("*Selection sort applied*\n");
    return;
}

void bubble_sort(int a[], int n)
{
    printf("*Applying BUBBLE SORT algorithm*\n");
    // Basic: bring the largest element to the back by comparing adjecent
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                // jth element is larger than it's next element
                swap(&a[j], &a[j + 1]);
            }
        }
    }
    printf("*Bubble sort applied*\n");
    return;
}

void insertion_sort(int a[], int n)
{
    printf("*Applying INSERTION SORT algorithm*\n");
    // Basic: from 2nd to nth element, choose every element and drag it toward the left of the array unless you no longer get any larger element
    for (int i = 1; i < n; i++)
    {
        int key = a[i]; // choose the element and name it key
        int j = i - 1;  // to compare elements before key
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j]; // moving jth element to it's next index
            j--;             // going to the left
        }
        a[j + 1] = key; // since j+1 is copied to it's right index, set j+1th index as key
    }
    printf("*Insertion sort applied*\n");
    return;
}

void printer(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n\n");
    return;
}

void recover_unsorted_array(int a[], int b[], int n)
{
    printf("*Recovering unsorted array*\n");
    // recover the unsorted array a from array b
    for (int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
    printf("*Unsorted array recovered*\n");
    return;
}