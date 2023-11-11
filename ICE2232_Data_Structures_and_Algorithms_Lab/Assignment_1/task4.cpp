#include<iostream>
#include <algorithm>
#include <time.h>

using namespace std;

void merge( int a[], int b[], int n, int m, int c[])
{
    int ai = 0, bi = 0;
    int ci = 0;
    while( ai < n && bi < m )
    {
        if( a[ai] < b[bi] )
        {
            c[ci] = a[ai];
            ai++;
        }
        else
        {
            c[ci] = b[bi];
            bi++;
        }
        ci++;
    }
    while( ai < n )
    {
        c[ci] = a[ai];
        ci++;
        ai++;
    }
    while( bi < m )
    {
        c[ci] = b[bi];
        ci++;
        bi++;
    }
    return;
}

int main()
{
    srand(time(0));
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for( int i = 0 ; i < n ; i++ )
        a[i] = rand()%100+1;
    for( int i = 0 ; i < m ; i++ )
        b[i] = rand()%100+1;
    sort(a, a+n);
    for( int i = 0 ; i < n ; i++ )
        cout << a[i] << " ";
    cout << endl;
    sort(b, b+m);
    for( int i = 0 ; i< m ; i++ )
        cout << b[i] << " ";
    cout << endl;
    int c[n+m];
    merge(a, b, n, m, c);
    for( int i = 0 ; i < n +m; i++ )
        cout << c[i] << " ";
}