#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of elements in first sorted array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter first sorted array: ");
    for( int i = 0 ; i < n ; i++ )
        scanf("%d", &a[i]);

    int m;
    printf("Enter number of elements in second sorted array: ");
    scanf("%d", &m);
    int b[m];
    printf("Enter second sorted array: ");
    for( int i = 0 ; i < m ; i++ )
        scanf("%d", &b[i]);

    int c[n+m];
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (a[i] < a[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    while (i < n)
        c[k++] = a[i++];
    while (j < m)
        c[k++] = b[j++];

    printf("Merged sorted array: ");
    for( int i = 0 ; i < n+m ; i++ )
        printf("%d ", c[i]);
    return 0;
}