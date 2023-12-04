// ICE2232 - Data Structures and Algorithms Lab
// Exam - 2022

// Set: 1
// Problem No: 1
// Solution by: Saifullah (ICE 21)

#include <iostream>
using namespace std;

int main()
{
    // take input of FIRST sorted array
    int n;
    printf("Enter the number elements in First array: ");
    scanf("%d", &n);
    int a[n];
    printf("Insert the elements of First array in sorted order: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // take input of SECOND sorted array
    int m;
    printf("Enter the number elements in Second array: ");
    scanf("%d", &m);
    int b[m];
    printf("Insert the elements of Second array in sorted order: ");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }

    // Begin the operations to perform merged sort in O(n) time complexity

    int tot = m + n; // the size of the merged sorted array is the sum of number of elements of two sorted array
    int c[tot];      // declare a array to store the merged sorted array

    int i = 0, j = 0, k = 0; // i, j, k is to controll the index of array A, B and C respectively

    while (i < n and j < m) // till you complete any of the two array
    {
        if (a[i] < b[j]) // if ith element of A is smaller than jth element of B
        {
            // insert a[i] into array C's k position
            c[k] = a[i];
            // move i and k to there next position since operation for current index is completed
            k++; i++;
        }
        else // for the other case
        {
            // insert b[j] into array C's k position
            c[k] = b[j];
            // move j and k to there next position since operation for current index is completed
            k++; j++;
        }
    }

    while (i < n) // if some elements of A is left to insert in the merged sorted array
    {
        // insert all the elements of A into C with their current order because they are in sorted order
        c[k] = a[i];
        // move i and k to there next position
        k++; i++;
    }

    while (j < m) // if some elements of A is left to insert in the merged sorted array
    {
        // insert all the elements of B into C with their current order because they are in sorted order
        c[k] = b[j];
        // move j and k to there next position
        k++; j++;
    }

    // Print the merged sorted array
    printf("\nThe size of merged sorted array: %d", tot);
    printf("The merged sorted array: ");
    for( int i = 0 ; i < tot ; i++ )
    {
        printf("%d ", c[i]);
    }
    printf("\n");
    
    return 0;
}