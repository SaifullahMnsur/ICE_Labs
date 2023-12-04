// ICE2232 - Data Structures and Algorithms Lab
// Exam - 2022
// Assignment: 4

// Task: 3
// Solution by: Saifullah (ICE 21)

#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Graph
{
private:
    int numVertices;
    int **wMat;         // pointer to a pointer for weight matrix to allocate memory according the input size
    int *dist, *parent; // pointer for distance and parent array to allocate memory according to the input size
    bool *explored;     // pointer for explored array to allocate memory according to the input size
    int INF;            // to store value of infinity
public:
    // constructor
    Graph(int num)
    {
        numVertices = num;
        // allocate pointer array to point different rows of a matrix via heap allocation
        wMat = new int *[numVertices];
        for (int i = 0; i < numVertices; i++)
        {
            // allocate an array for each row via heap allocation
            wMat[i] = new int[numVertices];
            // set premilimanary values
            for (int j = 0; j < numVertices; j++)
            {
                wMat[i][j] = 0;
            }
        }
        // allocate distance, parent and explored array via heap allocation
        dist = new int[numVertices];
        parent = new int[numVertices];
        explored = new bool[numVertices];
        // set value of infinity
        INF = numeric_limits<int>::max();
    }
    // destructor
    ~Graph()
    {
        for (int i = 0; i < numVertices; i++)
            delete[] wMat[i]; // free allocated array as row
        // free allocated pointer array to point rows
        delete[] wMat;
        // free distance, parent and explored array
        delete[] dist;
        delete[] parent;
        delete[] explored;
    }

    void printPath(int j)
    {
        // if their is no parent then return
        if (parent[j] == -1)
            return;

        // keep going to parent
        printPath(parent[j]);

        // print the indermediate nodes
        cout << " -> " << j;
    }

    void printSolution(int root, int destination)
    {
        if (root == destination)
        {
            cout << "Shortest distance from "<< root << " to " << destination << " is : 0\n";
            return;
        }
        if (parent[destination] == -1)
        {
            cout << "No path available!\n";
            return;
        }
        cout << "Shortest path from " << root << " to " << destination << " is: " << root;

        // print shortest poth from root to destination
        printPath(destination);
        cout << "\n";
    }

    int minDistInd(int dist[], bool explored[])
    {
        int minn = INF;                  // set INF as the minimum distance
        int min_index = numVertices - 1; // set last node as the minimum distance's node's index

        // linear search to find the node with minimum distance
        for (int i = 0; i < numVertices; i++)
        {
            // if the distance is current minimum and the node is yet unexplored
            if (dist[i] <= minn and explored[i] == false)
            {
                // update minimum distance node
                minn = dist[i];
                min_index = i;
            }
        }

        return min_index;
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
                if (explored[j] == false and wMat[minInd][j] > 0 and dist[minInd] != INF and dist[minInd] + wMat[minInd][j] < dist[j])
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
                cin >> wMat[i][j];
            }
        }
    }

    void printwMat()
    {
        // print the weight matrix
        cout << "Weight matrix:\n";
        for (int i = 0; i < numVertices; i++)
        {
            for (int j = 0; j < numVertices; j++)
            {
                cout << wMat[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main()
{
    int num;
    cout << "Enter number of vertices: ";
    cin >> num;
    Graph graph(num);
    graph.input();
    cout << "\n";
    int root, destination;
    while (true)
    {
        cout << "-1 to exit or any valid root and destination: ";
        cin >> root;
        if (root == -1)
            break;
        // graph.printwMat();
        cin >> destination;
        graph.dijkstra(root, destination);
        cout << "\n";
        graph.printSolution(root, destination);
        cout << "\n";
    }
}