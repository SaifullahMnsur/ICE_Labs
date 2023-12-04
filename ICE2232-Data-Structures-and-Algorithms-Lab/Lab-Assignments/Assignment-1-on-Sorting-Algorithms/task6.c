#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *a, int *b)
{
    int *temp = a;
    a = b;
    b = temp;
}

void merge(int a[], int start, int mid, int end)
{
    int n = mid - start + 1;
    int m = end - mid;
    int x[n], y[m];
    for (int i = 0; i < n; i++)
        x[i] = a[start + i];
    for (int i = 0; i < m; i++)
        y[i] = a[mid + 1 + i];
    int i = 0, j = 0, k = start;
    while (i < n && j < m)
    {
        if (x[i] < y[j])
            a[k++] = x[i++];
        else
            a[k++] = y[j++];
    }
    while (i < n)
        a[k++] = x[i++];
    while (j < m)
        a[k++] = y[j++];
    return;
}

int medianOfThree(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;

    if (arr[low] > arr[mid])
        swap(&arr[low], &arr[mid]);
    if (arr[low] > arr[high])
        swap(&arr[low], &arr[high]);
    if (arr[mid] > arr[high])
        swap(&arr[mid], &arr[high]);

    return mid;
}

int partition(int arr[], int low, int high) {
    int pi = medianOfThree(arr, low, high);
    int pivot = arr[pi];
    swap(&arr[pi], &arr[high]);
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void mergeSort(int a[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(a, start, mid);
        mergeSort(a, mid + 1, end);
        merge(a, start, mid, end);
    }
}

void quickSort(int a[], int start, int end)
{
    if (start < end)
    {
        int pi = partition(a, start, end);
        quickSort(a, start, pi - 1);
        quickSort(a, pi + 1, end);
    }
}

int main()
{
    srand(time(0));
    printf("Task 5\n");
    int cn, rn1;
    printf("Enter number of rows: ");
    scanf("%d", rn1);
    printf("Enter number of columns: ");
    scanf("%d", cn);
    int arr[rn1][cn];
    printf("Entering the array!\n");
    for (int i = 0; i < rn1; i++)
    {
        for (int j = 0; j < cn; j++)
        {
            arr[i][j] = rand() % 1000 + 1;
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    int again = 1;
    do
    {
        int column;
        printf("\nEnter 1base column you want to sort: ");
        scanf("%d", &column);
        column--;
        int a[rn1];
        for (int i = 0; i < rn1; i++)
            a[i] = arr[i][column];
        int choice;
        printf("Enter a number to choose sorting algorithm:\n");
        printf("Odd number: Quicksort\n");
        printf("Even number: Mergesort\n");
        scanf("%d", &choice);
        if (choice % 2 == 0)
            mergeSort(a, 0, rn1 - 1);
        else
            quickSort(a, 0, rn1 - 1);
        for (int i = 0; i < rn1; i++)
            arr[i][column] = a[i];
        for (int i = 0; i < rn1; i++)
        {
            for (int j = 0; j < cn; j++)
            {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
        printf("\nEnter 0 to end Task 6 or else to continue\n");
        scanf("%d", &again);
    } while (again != 0);
    printf("Thank you!\n");
    return 0;
}