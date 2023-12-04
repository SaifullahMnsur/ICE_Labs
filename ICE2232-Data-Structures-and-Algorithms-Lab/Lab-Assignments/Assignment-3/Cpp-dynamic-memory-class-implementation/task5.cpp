// ICE2232 - Data Structures and Algorithms Lab
// Exam - 2022
// Assignment: 3

// Task: 5
// Solution by: Saifullah (ICE 21)

#include <iostream>
#include <stack>

using namespace std;

stack<int> tower[3];
string names[] = {"A", "B", "C"};
int A = 0, B = 1, C = 2;

void towerOfHanoi(int n, int from, int to, int aux)
{
    if( n == 0 )
        return;

    towerOfHanoi(n-1, from, aux, to);
    cout << "Move " << n << " from " << names[from] << " to " << names[to] << "\n";

    // moving n
    tower[to].push(tower[from].top());
    tower[from].pop();

    towerOfHanoi(n-1, aux, to, from);
    return;
}

int main()
{
    int n;
    cin >> n;
    for( int i = 0 ; i < n ; i++ )
    {
        tower[A].push(i+1);
    }
    towerOfHanoi(n, A, B, C);
    cout << "Tower C:\n";
    while( !tower[C].empty() )
    {
        cout << tower[C].top() << "\n";
        tower[C].pop();
    }
}