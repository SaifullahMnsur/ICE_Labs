// ICE2232 - Data Structures and Algorithms Lab
// Exam - 2022
// Lab Test: 2
// Set: 2
// Problem No: 1
// Solution by: Saifullah (ICE 21)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// to determine path matrix
void warshall(int num, bool adj[num][num], bool path[num][num])
{
    // copy adjecancy matrix to path matrix
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            path[i][j] = adj[i][j];
        }
    }
    // find paths
    for (int k = 0; k < num; k++)
    {
        for (int i = 0; i < num; i++)
        {
            for (int j = 0; j < num; j++)
            {
                // if path i->j is available or path i->j and j-> is availabe
                path[i][j] = path[i][j] | (path[i][k] & path[k][j]);
            }
        }
    }
    return;
}

// to detect cycel
bool cycle(int num, bool path[num][num])
{
    // check if there is any cycle between every pair of nodes
    for( int i = 0 ; i < num ; i++ )
    {
        for( int j = 0 ; j < num ; j++ )
        {
            // if there is path from i->j and j-> that means there is a cycle
            if( path[i][j] == true && path[j][i] == true )
                return true;
        }
    }
    return false;
}

// to print desired matrix
void printMat(int num, bool mat[num][num])
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return;
}

// to take matrix input
void matInput(int num, bool mat[num][num])
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    return;
}

int main()
{
    printf("Enter the number of vertices: ");
    int num;
    scanf("%d", &num);
    bool adj[num][num];

    printf("Enter the adjecency matrix:\n");
    matInput(num, adj);

    bool path[num][num];
    warshall(num, adj, path);

    printf("\nPath Matrix:\n");
    printMat(num, path);

    if( cycle(num, path) == true )
    {
        printf("The graph has cycle!\n\n");
    }
    else
    {
        printf("The graph has no cycle!\n\n");
    }
    return 0;
}