// ICE2232 - Data Structures and Algorithms Lab
// Exam - 2022
// Lab Final Exam
// Problem: 3
// Solution by: Saifullah (ICE 21)

#include <iostream>
using namespace std;

string node = "XYZWABCDEFGHIJKLMNOPQRST"; // names of different nodes

class Graph
{
private:
    int numVertices;
    int **adjMat;
    int **pathMat;

public:
    Graph(int num)
    {
        numVertices = num;
        adjMat = new int *[numVertices];
        pathMat = new int *[numVertices];
        for (int i = 0; i < numVertices; i++)
        {
            adjMat[i] = new int[numVertices];
            pathMat[i] = new int[numVertices];
        }
    }
    ~Graph()
    {
        for (int i = 0; i < numVertices; i++)
        {
            delete[] adjMat[i];
            delete[] pathMat[i];
        }
        delete[] adjMat;
        delete[] pathMat;
    }
    void printPathMat()
    {
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
    void warshall()
    {
        for (int i = 0; i < numVertices; i++)
        {
            for (int j = 0; j < numVertices; j++)
            {
                pathMat[i][j] = adjMat[i][j];
            }
        }
        for (int k = 0; k < numVertices; k++)
        {
            for (int i = 0; i < numVertices; i++)
            {
                for (int j = 0; j < numVertices; j++)
                {
                    if (pathMat[i][k] && pathMat[k][j])
                        pathMat[i][j] = 1;
                }
            }
        }
        return;
    }
    void input()
    {
        for (int i = 0; i < numVertices; i++)
        {
            for (int j = 0; j < numVertices; j++)
            {
                cin >> adjMat[i][j];
            }
        }
        return;
    }

    void DFS(int curr, int end, bool visited[], int path[], int &pathIndex)
    {
        visited[curr] = true;
        path[pathIndex++] = curr;

        if (curr == end)
        {
            for (int i = 0; i < pathIndex; i++)
            {
                if (i > 0)
                    cout << " -> ";
                cout << node[path[i]];
            }
            cout << "\n";
        }
        else
        {
            for (int neighbor = 0; neighbor < numVertices; neighbor++)
            {
                if (adjMat[curr][neighbor] == 1 && visited[neighbor] == false)
                {
                    DFS(neighbor, end, visited, path, pathIndex);
                }
            }
        }
        visited[curr] = false;
        pathIndex--;
        return;
    }

    void findAllPaths(int start, int end)
    {
        bool visited[numVertices] = {false};
        int path[numVertices];
        int pathIndex = 0;
        DFS(start, end, visited, path, pathIndex);
        return;
    }
};

int main()
{
    int num;
    cout << "\nEnter number of vertices: ";
    cin >> num;

    Graph graph(num);
    cout << "Assumed Name of the nodes: ";
    for (int i = 0; i < num; i++)
        cout << node[i] << " ";
    cout << "\n\n";

    cout << "Enter the adjacency matrix:\n";
    graph.input();
    graph.warshall();

    cout << "\nThe path matrix:\n";
    graph.printPathMat();

    cout << "\nEnter the nodes pair for paths: ";
    char startName, endName;
    cin >> startName >> endName;
    cout << "\nAll the paths from " << startName << " to " << endName << ":\n";
    int start, end;
    for (int i = 0; node[i] != '\0'; i++)
    {
        if (startName == node[i])
        {
            start = i;
            break;
        }
    }
    for (int i = 0; node[i] != '\0'; i++)
    {
        if (endName == node[i])
        {
            end = i;
            break;
        }
    }
    graph.findAllPaths(start, end);
    cout << "\n\n";

    return 0;
}