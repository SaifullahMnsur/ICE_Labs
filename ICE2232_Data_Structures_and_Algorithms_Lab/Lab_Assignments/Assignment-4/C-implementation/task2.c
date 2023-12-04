// ICE2232 - Data Structures and Algorithms Lab
// Exam - 2022
// Assignment: 4

// Task: 2
// Solution by: Saifullah (ICE 21)

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numVertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    int adjMat[numVertices][numVertices];
    int pathMat[numVertices][numVertices];

    printf("Enter the adjecencty matric:\n");
    int x;
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            scanf("%d", &x);
            adjMat[i][j] = x;
            pathMat[i][j] = x; // adjecancy matrices' value is the inital value of path matrix
        }
    }
    
    // floyd-warshell algorithm starts here

    // increase the interemediate node gradually
    for (int k = 0; k < numVertices; k++)
    {
        // find the interemediate node for different pair of nodes in path matrix
        for (int i = 0; i < numVertices; i++)
        {
            for (int j = 0; j < numVertices; j++)
            {
                // Update the path matrix
                pathMat[i][j] = pathMat[i][j] || (pathMat[i][k] && pathMat[k][j]);
            }
        }
    }

    printf("\nPath matrix:\n\n");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            printf("%d ", pathMat[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}