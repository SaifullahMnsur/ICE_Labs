#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
struct node
{
    T data;
    node *next;

    node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class stack
{
private:
    node<T> *tail;

public:
    stack() : tail(nullptr) {};
    void pop()
    {
        if (tail != nullptr)
        {
            node<T> *temp = tail->next;
            delete tail;
            tail = temp;
        }
        else
        {
            cout << "The stack is already empty!\n\n";
        }
        return;
    }
    void push( const T &val)
    {
        node<T> *newNode = new node(val);
        if( tail != nullptr )
            newNode->next = tail;
        tail = newNode;
    }
    T top()
    {
        return tail->data;
    }
    bool empty()
    {
        return tail == nullptr;
    }
};

stack<int> tower[3];
string names[] = {"A", "B", "C"};
int A = 0, B = 1, C = 2;

void towerOfHanoi(int n, int from, int to, int aux)
{
    if( n == 0 )
        return;
    towerOfHanoi(n-1, from, aux, to);
    cout << "Move " << n << " from " << names[from] << " to " << names[to] << "\n";
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
    cout << setw(10) << "A" << setw(10) << "B" << setw(10) << "C" << "\n";
    while( !tower[C].empty() )
    {
        if( tower[A].empty() )
            cout << setw(10) << "Empty!";
        if( tower[B].empty() )
            cout << setw(10) << "Empty!";
        cout << setw(10) << tower[C].top() << "\n";
        tower[C].pop();
    }
}