// ICE1292 - Programming with C Lab
// Exam - 2021

// Problem No: 2
// Solution by: Saifullah (ICE 21)

// Problem Topics: array, 2d array, math

#include <stdio.h>

int main()
{
    int n;
    printf("Input the size of the square matrix : ");
    scanf("%d", &n);
    int mat[n][n]; // declaring a 2d array of n*n size to represent the square matrix
    printf("Input elements in the first matrixL : \n");
    for( int i = 0 ; i < n ; i++ )
    {
        for( int j = 0 ; j < n ; j++ )
        {
            printf("element - [%d],[%d] : ", i, j);
            scanf("%d", &mat[i][j]); // taking input of current position
        }
    }

    // showing the matrix
    printf("The First matrix is:\n");
    printf("The matrix is:\n");
    for( int i = 0 ; i < n ; i++ )
    {
        for( int j = 0 ; j < n ; j++ )
        {
            printf("%d ", mat[i][j]); // printing value of current position
        }
        printf("\n");
    }

    // proceeding to calculate desired values

    int row[n]; // array to store the sum of rows
    for( int i = 0 ; i < n ; i++ )
        row[i] = 0; // setting the initial value of all element as 0
    
    for( int i = 0 ; i < n ; i++ )
    {
        for( int j = 0 ; j < n ; j++ )
        {
            row[i] += mat[i][j]; // adding current position's value to it's corresponding row sum
        }
    }

    int col[n]; // array to store the sum of columns
    for( int j = 0 ; j < n ; j++ )
        col[j] = 0; // setting the initial value of all element as 0
    
    for( int i = 0 ; i < n ; i++ )
    {
        for( int j = 0 ; j < n ; j++ )
        {
            col[j] += mat[i][j]; // adding current positions value to it's corresponding column sum
        }
    }

    printf("The sum of rows and columns of the matrix is:\n");
    for( int i = 0 ; i < n ; i++ )
    {
        for( int j = 0 ; j < n ; j++ )
        {
            printf("%d ", mat[i][j]);
        }
        printf("%d\n", row[i]); // printing the sum of the currnt row
    }
    // printing the sum of columns
    for( int j = 0 ; j < n ; j++ )
    {
        printf("%d ", col[j]);
    }
    
    return 0;
}
