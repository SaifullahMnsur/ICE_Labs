#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
        int target;
        printf("\nEnter yout target: ");
        scanf("%d", target);
        bool found = false;
        for (int i = 0; i < rn1; i++)
        {
            for (int j = 0; j < cn; j++)
            {
                if (arr[i][j] == target)
                {
                    printf("Target found at row: %d, column: %d\n", i + 1, j + 1);
                    found = true;
                }
            }
        }
        if (found == false)
            printf("target not found in the array\n");
        printf("\nEnter 0 to end Task 5 or else to continue\n");
        scanf("%d", again);
    } while (again != 0);
    printf("Thank you!\n");
    return 0;
}