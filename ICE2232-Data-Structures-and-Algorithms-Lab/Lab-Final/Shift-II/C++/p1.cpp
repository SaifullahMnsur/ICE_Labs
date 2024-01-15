// ICE2232 - Data Structures and Algorithms Lab
// Exam - 2022
// Lab Final Exam
// Problem: 1
// Solution by: Saifullah (ICE 21)

#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements of first array: ";
    cin >> n;
    int a[n];
    for( int i = 0 ; i < n ; i++ )
        cin >> a[i];

    int m;
    cout << "Enter the number of elements of first array: ";
    cin >> m;
    int b[m];
    for( int i = 0 ; i < m ; i++ )
        cin >> b[i];
    
    int c[n+m];
    int i = 0, j = 0, k = 0;

    while( i < n && j < m )
    {
        if( a[i] < b[j] )
        {
            c[k++] = a[i++];
        }
        else
        {
            c[k++] = b[j++];
        }
    }
    while( i < n )
    {
        c[k++] = a[i++];
    }
    while( j < m )
    {
        c[k++] = b[j++];
    }

    cout << "Merged Sorted array: ";
    for( int i = 0 ; i < n+m ; i++ )
    {
        cout << c[i] << " ";
    }
    return 0;
}