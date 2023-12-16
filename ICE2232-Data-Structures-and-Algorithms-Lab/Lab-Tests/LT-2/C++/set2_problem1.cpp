// ICE2232 - Data Structures and Algorithms Lab
// Exam - 2022
// Lab Test: 2
// Set: 2
// Problem No: 1
// Solution by: Saifullah (ICE 21)

// topics: directed graph, unweighted graph, matrix, path, cycles

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
        for( int i = 0 ; i < numVertices ; i++ )
        {
            for( int j = 0 ; j < numVertices ; j++ )
            {
                pathMat[i][j] = adjMat[i][j];
            }
        }
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
    bool cycle()
    {
        for( int i = 0 ; i < numVertices ; i++ )
        {
            for( int j = 0 ; j < numVertices ; j++ )
            {
                // if there is a path from i to j and j to i as well then there is a cycle
                if( pathMat[i][j] == 1 and pathMat[j][i] == 1 )
                    return true;
            }
        }
        return false;
    }
    void input()
    {
        cout << "Enter the adjecancy matrix:\n";
        for (int i = 0; i < numVertices; i++)
        {
            for (int j = 0; j < numVertices; j++)
            {
                cin >> adjMat[i][j];
                pathMat[i][j] = adjMat[i][j];
            }
        }
        return;
    }
    void printPathMat()
    {
        cout << "\nPath matrix:\n";
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
    int num;
    cout << "Enter number of vertices: ";
    cin >> num;
    Graph graph(num);
    graph.input();
    graph.warshall();
    graph.printPathMat();
    if( graph.cycle() == true )
        cout << "\nThe graph have cycles\n\n";
    else
        cout << "\nThe graph don't have any cycle\n\n";
    return 0;
}
