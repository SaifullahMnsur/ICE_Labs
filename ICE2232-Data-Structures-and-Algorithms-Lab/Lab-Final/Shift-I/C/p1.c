#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));

    int n, m;
    printf("Enter row and column number: ");
    scanf("%d%d", &n, &m);

    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = rand() % 100;
        }
    }

    printf("The array:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    int choice = -1;
    while (choice != 0)
    {
        printf("1. Search a value\n");
        printf("0. End program!\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int val;
            scanf("%d", &val);

            printf("Indices: ");
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if( arr[i][j] == val )
                    {
                        printf("%d%d ", i, j);
                    }
                }
            }
            printf("\n\n");
        }
        else if( choice != 0 )
        {
            printf("Wrong input!\n\n");
        }
    }
    return 0;
}