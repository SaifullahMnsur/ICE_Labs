#include <iostream>
#include <vector>

using namespace std;

void DFS(int curr, vector<vector<int>> &graph, vector<bool> &visited, vector<vector<int>> &paths)
{
    //cout << curr << ' ';
    visited[curr] = true;
    if( !paths.empty())
        paths.back().push_back(curr);
    else
        paths.push_back({curr});
    for (int i = 0; i < 4; i++)
    {
        if (graph[curr][i] == 1 && visited[i] == false)
        {
            DFS(i, graph, visited, paths);
        }
    }
    paths.push_back(paths.back());
    paths.back().pop_back();
    visited[curr] = false;
}

int main()
{
    vector<vector<int>> graph = {{0, 0, 0, 1},
                                 {1, 0, 1, 1},
                                 {1, 0, 0, 1},
                                 {0, 0, 1, 0}};
    vector<bool> vis(4, false);
    vector<vector<int>> paths;
    for( int i = 0 ; i < 4 ; i++ )
    {
        DFS(i, graph, vis, paths);
        cout << "\n";
    }
    string name = "XYZW";
    int prev = -1;
    for (auto i : paths)
    {
        if( prev != i.front() )
            cout << "\nfrom " << name[i.front()] << ":\n";
        for (auto j : i)
        {
            cout << name[j] << " ";
        }
        prev = i.front();
        cout << "\n";
    }
}