#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &a, int start, int mid, int end)
{
    // cout << "Merge\n";
    int n = mid - start + 1;
    int m = end - mid;
    int x[n], y[m];
    for (int i = 0; i < n; i++)
    {
        x[i] = a[start + i];
    }
    for (int i = 0; i < m; i++)
    {
        y[i] = a[mid + 1 + i];
    }
    int i = 0, j = 0, k = start;
    while (i < n and j < m)
    {
        if (x[i] < y[j] )
            a[k++] = x[i++];
        else
            a[k++] = y[j++];
    }
    while( i < n )
        a[k++] = x[i++];
    while( j < m )
        a[k++] = y[j++];
    return;
}

void mergeSort(vector<int> &a, int start, int end)
{
    // cout << "Sort\n";
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(a, start, mid);
        mergeSort(a, mid + 1, end);
        merge(a, start, mid, end);
    }
}

void printer(vector<int> &a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int n = 100000;
    //cin >> n;
    vector<int> a(n);
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
    }
    printer(a, n);
    mergeSort(a, 0, n - 1);
    printf("Sorted array: ");
    printer(a, n);
}