#include <iostream>
#include <time.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
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
    while (i < n and j < m)
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

int partition(int a[], int start, int end)
{
    int pivot = a[end];
    int i = start - 1;
    for (int j = start; j < end; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[end]);
    return i + 1;
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
    cout << "Task 5\n";
    int cn, rn1;
    cout << "Enter number of rows: ";
    cin >> rn1;
    cout << "Enter number of columns: ";
    cin >> cn;
    int arr[rn1][cn];
    cout << "Entering the array!\n";
    for (int i = 0; i < rn1; i++)
    {
        for (int j = 0; j < cn; j++)
        {
            arr[i][j] = rand() % 1000 + 1;
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    int again = 1;
    do
    {
        int target;
        cout << "\nEnter yout target: ";
        cin >> target;
        bool found = false;
        for (int i = 0; i < rn1; i++)
        {
            for (int j = 0; j < cn; j++)
            {
                if (arr[i][j] == target)
                {
                    cout << "Target found at row: " << i + 1 << ", column: " << j + 1 << "\n";
                    found = true;
                }
            }
        }
        if (found == false)
            cout << "target not found in the array\n";
        cout << "\nEnter 0 to end Task 5 or else to continue\n";
        cin >> again;
    } while (again != 0);
    
    //Task 6
    cout << "\nTask 6\n";
    do
    {
        int column;
        cout << "\nEnter 1base column you want to sort: ";
        cin >> column;
        column--;
        int a[rn1];
        for (int i = 0; i < rn1; i++)
            a[i] = arr[i][column];
        int choice;
        cout << "Enter a number to choos sorting algorithm:\n";
        cout << "Odd number: Quicksort\n";
        cout << "Even number: Mergesort\n";
        cin >> choice;
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
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\nEnter 0 to end Task 6 or else to continue\n";
        cin >> again;
    } while (again != 0);

    // Task 7
    cout << "\nTask 7\n";
    int rn2;
    cout << "To merge two 2d array column wise please enter the number of row for new array!: ";
    cin >> rn2;
    int brr[rn2][cn];
    
    cout << "Enter another " << rn2 << "x" << cn << "2d array:\n";
    for( int i = 0 ; i < rn2 ; i++ )
    {
        for(int j = 0 ; j < cn ; j++ )
        {
            brr[i][j] = rand() % 1000 + 1;
            cout << brr[i][j] <<" ";
        }
        cout << "\n";
    }

    // this part is to confirm both array are sorted comlumn wise
    cout << "Sorting this array!\n";
    for( int i = 0 ; i < cn ; i++ )
    {
        int a[rn1];
        for (int j = 0; j < rn1; j++)
            a[j] = arr[j][i];
        mergeSort(a, 0, rn1-1);
        for (int j = 0; j < rn1; j++)
            arr[j][i] = a[j];
        
        int b[rn2];
        for (int j = 0; j < rn2; j++)
            b[j] = brr[j][i];
        mergeSort(b, 0, rn2-1);
        for (int j = 0; j < rn2; j++)
            brr[j][i] = b[j];
    }
    //both array sorted column wise

    cout << "*Merging this two 2d array!*\n";
    int rn = rn1+rn2;
    int mrr[rn][cn];
    for( int i = 0 ; i < cn ; i++ )
    {
        int k = 0;
        int ai = 0, bi = 0;
        while( ai < rn1 && bi < rn2 )
        {
            if(arr[ai][i] < brr[bi][i])
                mrr[k++][i] = arr[ai++][i];
            else
                mrr[k++][i] = brr[bi++][i];
        }
        while( ai < rn1 )
            mrr[k++][i] = arr[ai++][i];
        while( bi < rn2 )
            mrr[k++][i] = brr[bi++][i];
    }
    cout << "\n*Merged 2d array*\n";
    for( int i = 0 ; i < rn ; i++ )
    {
        for( int j = 0 ; j < cn ; j++ )
        {
            cout << mrr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "All task finished\n";
    return 0;
}