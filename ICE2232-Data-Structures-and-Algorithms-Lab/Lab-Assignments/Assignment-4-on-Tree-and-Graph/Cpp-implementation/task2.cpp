// ICE2232 - Data Structures and Algorithms Lab
// Exam - 2022
// November 23, 2023

// Assignment: 4

// Task: 2
// Solution by: Saifullah (ICE 21)

#include <iostream>
#include <string>

using namespace std;

class Graph
{
private:
    int numVertices;
    int **adjMat, **pathMat; // pointer to a pointer for adjacency matrix and path matrix to allocate memory according to the input size

public:
    // constructor
    Graph(int num)
    {
        numVertices = num;
        // allocate pointer array to point different rows of a matrix via heap allocation
        adjMat = new int *[numVertices];
        pathMat = new int *[numVertices];
        for (int i = 0; i < numVertices; i++)
        {
            // allocate an array for each row via heap allocation
            adjMat[i] = new int[numVertices];
            pathMat[i] = new int[numVertices];
            // set preliminary values
            for (int j = 0; j < numVertices; j++)
            {
                adjMat[i][j] = 0;
                pathMat[i][j] = 0;
            }
        }
    }
    // destructor
    ~Graph()
    {
        // free memory
        for (int i = 0; i < numVertices; i++)
        {
            // free allocated array as row
            delete[] adjMat[i];
            delete[] pathMat[i];
        }
        // free allocated pointer array to point rows
        delete[] adjMat;
        delete[] pathMat;
    }
    void warshall()
    {
        // Initialize the path matrix with the adjacency matrix
        // increase the inderemediate node gradually
        for (int k = 0; k < numVertices; k++)
        {
            // find the inderemediate node for different pair of nodes in path matrix
            for (int i = 0; i < numVertices; i++)
            {
                for (int j = 0; j < numVertices; j++)
                {
                    // Update the path matrix
                    pathMat[i][j] = pathMat[i][j] || (pathMat[i][k] && pathMat[k][j]);
                }
            }
        }
        return;
    }
    void input()
    {
        int x;
        for (int i = 0; i < numVertices; i++)
        {
            for (int j = 0; j < numVertices; j++)
            {
                cin >> x;
                adjMat[i][j] = x;
                pathMat[i][j] = x;
            }
        }
        return;
    }
    void printPathMat()
    {
        cout << "\nPath matrix:\n\n";
        for (int i = 0; i < numVertices; i++)
        {
            for (int j = 0; j < numVertices; j++)
            {
                cout << pathMat[i][j] << " ";
            }
            cout << "\n";
        }
        return;
    }
};

int main()
{
    Graph graph(4);
    graph.input();
    graph.warshall();
    graph.printPathMat();
    return 0;
}