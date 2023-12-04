#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

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

int main()
{
    srand(time(0));
    int r1, c1;
    printf("Enter the number of rows and columns of first array: ");
    scanf("%d%d", &r1, &c1);
    int arr1[r1][c1];
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            // scanf("%d", &arr1[i][j]);
            arr1[i][j] = rand() % 1000;
            printf("%d ", arr1[i][j]);
        }
        printf("\n");
    }
    int r2, c2;
    printf("Enter the number of rows and columns of second array: ");
    scanf("%d%d", &r2, &c2);
    int arr2[r2][c2];
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            // scanf("%d", &arr1[i][j]);
            arr2[i][j] = rand() % 1000;
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }
    // this part is to confirm both array are sorted comlumn wise
    for (int i = 0; i < c1; i++)
    {
        int a[r1];
        for (int j = 0; j < r1; j++)
            a[j] = arr1[j][i];
        mergeSort(a, 0, r1 - 1);
        for (int j = 0; j < r1; j++)
            arr1[j][i] = a[j];
    }
    for (int i = 0; i < c2; i++)
    {
        int b[r2];
        for (int j = 0; j < r2; j++)
            b[j] = arr2[j][i];
        mergeSort(b, 0, r2 - 1);
        for (int j = 0; j < r2; j++)
            arr2[j][i] = b[j];
    }
    // both array sorted column wise

    printf("Enter odd or even to choose option:\n");
    printf("Odd. Column wise merge (number of rows must be equal)\n");
    printf("Even. Row wise merge (number of columns must be equal\n)");
    int choice;
    scanf("%d", &choice);
    int rows, columns;
    int mrr[r1 + r2][c1 + c2];
    bool mergable = true;
    if (choice % 2 == 0)
    {
        if (r1 == r2)
        {
            rows = r1;
            columns = c1 + c2;
            for (int i = 0; i < c1; i++)
            {
                int k = 0;
                int ai = 0, bi = 0;
                while (ai < r1 && bi < r2)
                {
                    if (arr1[ai][i] < arr2[bi][i])
                        mrr[k++][i] = arr1[ai++][i];
                    else
                        mrr[k++][i] = arr2[bi++][i];
                }
                while (ai < r1)
                    mrr[k++][i] = arr1[ai++][i];
                while (bi < r2)
                    mrr[k++][i] = arr2[bi++][i];
            }
        }
        else
        {
            mergable = false;
        }
    }
    else
    {
        if (c1 == c2)
        {
            columns = c1;
            rows = r1+r1;
            for (int i = 0; i < r1; i++)
            {
                int k = 0;
                int ai = 0, bi = 0;
                while (ai < c1 && bi < c2)
                {
                    if (arr1[ai][i] < arr2[bi][i])
                        mrr[k++][i] = arr1[ai++][i];
                    else
                        mrr[k++][i] = arr2[bi++][i];
                }
                while (ai < r1)
                    mrr[k++][i] = arr1[ai++][i];
                while (bi < r2)
                    mrr[k++][i] = arr2[bi++][i];
            }
        }
        else
        {
            mergable = false;
        }
    }
    if( mergable == false )
    {
        printf("Not mergable\n");
    }
    else
    {
        for( int i = 0 ; i < rows ; i++ )
        {
            for( int j = 0 ; j < columns ; j++ )
            {
                printf("%d ", mrr[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}