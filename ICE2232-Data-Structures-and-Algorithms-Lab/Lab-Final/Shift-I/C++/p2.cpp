#include <iostream>
#include <stack>
using namespace std;

stack<int> Stack[4];

void towerOfHanoi(int n, int from, int to, int aux)
{
    if (n == 0)
    {
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);

    cout << "Move disk " << n << " from rod " << from << " to rod " << to << endl;
    Stack[to].push(Stack[from].top());
    Stack[from].pop();

    towerOfHanoi(n - 1, aux, to, from);
}

void print(int n)
{
    cout << "Rod " << n << " :\n";
    if( Stack[n].empty() == true )
    {
        cout << "Empty!\n";
    }
    while( Stack[n].empty() == false )
    {
        cout << Stack[n].top() << "\n";
        Stack[n].pop();
    }
    cout << "\n";
}

int main()
{
    int n = 4;
    int from = 3;
    int to = 2;
    cout << "\n";
    for( int i = 1 ; i <= 4 ; i++ )
    {
        Stack[from].push(i);
    }
    towerOfHanoi(n, from, to, 1);

    cout << "\nAfter operations:\n";
    for( int i = 1 ; i<= 3 ; i++ )
    {
        print(i);
    }
    return 0;
}
