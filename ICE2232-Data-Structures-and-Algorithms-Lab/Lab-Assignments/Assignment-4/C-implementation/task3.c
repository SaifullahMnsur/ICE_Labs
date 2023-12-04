// ICE2232 - Data Structures and Algorithms Lab
// Exam - 2022
// Assignment: 4

// Task: 3
// Solution by: Saifullah (ICE 21)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define INF INT_MAX // defining maximum value of integer as infinity

// global variables to access from every function
int numVertices;
int **wMat;         // pointer to a pointer for weight matrix to allocate memory according the input size
int *dist, *parent; // pointer for distance and parent array to allocate memory according to the input size
bool *explored;     // pointer for explored array to allocate memory according to the input size

void setupGraph(int num)
{
    numVertices = num;
    // allocate pointer array to point different rows of a matrix via heap allocation
    wMat = (int **)malloc(sizeof(int *) * numVertices);
    for (int i = 0; i < numVertices; i++)
    {
        // allocate an array for each row via heap allocation
        wMat[i] = (int *)malloc(sizeof(int) * numVertices);
        // set premilimanary values
        for (int j = 0; j < numVertices; j++)
        {
            wMat[i][j] = 0;
        }
    }
    // allocate distance, parent and explored array via heap allocation
    dist = (int *)malloc(sizeof(int) * numVertices);
    parent = (int *)malloc(sizeof(int) * numVertices);
    explored = (bool *)malloc(sizeof(int) * numVertices);
}
void freeMemory()
{
    for (int i = 0; i < numVertices; i++)
        free(wMat[i]); // free allocated array as row
    // free allocated pointer array to point rows
    free(wMat);
    // free distance, parent and explored array
    free(dist);
    free(parent);
    free(explored);
}

void printPath(int j)
{
    // if their is no parent then return
    if (parent[j] == -1)
        return;

    // keep going to parent
    printPath(parent[j]);

    // print the indermediate nodes
    printf(" -> %d", j);
}

void printSolution(int root, int destination)
{
    // if root and destination is same
    if (root == destination)
    {
        printf("Shortest distance from %d to %d is : 0\n", root, destination);
        return;
    }

    // if there is no path between root and destination
    if (parent[destination] == -1)
    {
        printf("No path available!\n");
        return;
    }
    printf("Shortest distance from %d to %d is : %d\n", root, destination, dist[destination]);
    printf("Shortest path from %d to %d is: %d", root, destination, root);

    // print shortest poth from root to destination
    printPath(destination);
    printf("\n");
}

int minDistInd(int dist[], bool explored[])
{
    int minn = INF;               // set INF as the minimum distance
    int minInd = numVertices - 1; // set last node as the minimum distance's node's index

    // linear search to find the node with minimum distance
    for (int i = 0; i < numVertices; i++)
    {
        // if the distance is current minimum and the node is yet unexplored
        if (dist[i] <= minn && explored[i] == false)
        {
            // update minimum distance node
            minn = dist[i];
            minInd = i;
        }
    }

    return minInd;
}

void dijkstra(int root, int destination)
{
    // set preliminary values to perform dijkstra
    for (int i = 0; i < numVertices; i++)
    {
        dist[i] = INF;
        explored[i] = false;
        parent[i] = -1;
    }

    dist[root] = 0; // distance of root to root is 0

    // go through all nodes except last one
    for (int i = 0; i < numVertices - 1; i++)
    {
        // find the node with minimum distance from root
        int minInd = minDistInd(dist, explored);

        explored[minInd] = true; // make that node explored
        // go through all nodes
        for (int j = 0; j < numVertices; j++)
        {
            // if jth node is not yet explored
            // and if the weight is greater than 0 at dijkstra is not applicable for negative weight
            // and if ditance is not infinity
            // and if current nodes distance is greater than (minimum distance index's distance + minimum distance index to current node distance)
            // then update distance and parent
            if (explored[j] == false && wMat[minInd][j] > 0 && dist[minInd] != INF && dist[minInd] + wMat[minInd][j] < dist[j])
            {
                dist[j] = dist[minInd] + wMat[minInd][j];
                parent[j] = minInd;
            }
        }
    }
}

void input()
{
    // take input
    int x;
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            scanf("%d", &wMat[i][j]);
        }
    }
}

void printwMat()
{
    // print the weight matrix
    printf("Weight matrix:\n");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            printf("%d ", wMat[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int num;
    printf("Enter number of vertices: ");
    scanf("%d", &num);
    setupGraph(num);
    input();
    printf("\n");
    int root, destination;
    while (true)
    {
        printf("-1 to exit or any valid root and destination: ");
        scanf("%d", &root);
        if (root == -1)
        {
            printf("Programm finished!");
            break;
        }
        scanf("%d", &destination);
        dijkstra(root, destination);
        printf("\n");
        printwMat();
        printSolution(root, destination);
        printf("\n");
    }
}