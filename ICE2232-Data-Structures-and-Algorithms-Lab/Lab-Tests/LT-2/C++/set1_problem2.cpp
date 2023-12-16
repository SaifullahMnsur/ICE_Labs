// ICE2232 - Data Structures and Algorithms Lab
// Exam - 2022
// Lab Test: 2
// Set: 1
// Problem No: 2
// Solution by: Saifullah (ICE 21)

// topics: structure, stack, dynamic memory

#include <iostream>

using namespace std;

struct Node
{
    char data;
    Node *next;

    Node(char &value) : data(value), next(nullptr) {}
};

class Stack
{
private:
    Node *tail;

public:
    Stack() : tail(nullptr){};
    ~Stack()
    {
        while (tail != nullptr)
        {
            Node *temp = tail->next;
            delete tail;
            tail = temp;
        }
    }

    char pop()
    {
        char val;
        if (tail != nullptr)
        {
            Node *temp = tail->next;
            val = tail->data;
            delete tail;
            tail = temp;
        }
        else
        {
            cerr << "The stack is already empty!\n\n";
            exit(2);
        }
        return val;
    }
    void push(char val)
    {
        Node *newNode = new Node(val);
        if (newNode == NULL) // due to memory overflow or system error
        {
            cerr << "Memory Allocation failed!\n";
            exit(1);
        }
        if (tail != nullptr)
            newNode->next = tail;
        tail = newNode;
    }
    bool empty()
    {
        return tail == nullptr;
    }
};

int main()
{
    Stack stc;
    stc.push('a');
    stc.push('b');
    stc.push('c');
    stc.push('d');
    while (stc.empty() == false)
    {
        cout << stc.pop() << " ";
    }
    return 0;
}