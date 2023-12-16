// ICE2232 - Data Structures and Algorithms Lab
// Exam - 2022
// Lab Test: 2
// Set: 1
// Problem No: 2
// Solution by: Saifullah (ICE 21)

// topics: structure, queue, dynamic memory

#include <iostream>

using namespace std;

struct Node
{
    char data;
    Node *next;

    Node(char &value) : data(value), next(nullptr) {}
};

class Queue
{
private:
    Node *frontPt, *rearPt;

public:
    Queue() : frontPt(nullptr), rearPt(nullptr){};
    ~Queue()
    {
        while (frontPt != nullptr)
        {
            Node *temp = frontPt->next;
            delete frontPt;
            frontPt = temp;
        }
    }

    char pop()
    {
        if (frontPt == nullptr)
        {
            cerr << "The queue is already empty!\n\n";
            exit(2);
        }

        char val;
        val = frontPt->data;

        if (frontPt == rearPt)
        {
            delete frontPt;
            frontPt = rearPt = nullptr;
            return val;
        }
        
        Node *temp = frontPt;
        frontPt = frontPt->next;
        delete temp;
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

        if (frontPt == nullptr)
            frontPt = newNode;
        if (rearPt != nullptr)
            rearPt->next = newNode;
        rearPt = newNode;
    }
    bool empty()
    {
        return frontPt == nullptr;
    }
};

int main()
{
    Queue que;
    que.push('a');
    que.push('b');
    que.push('c');
    que.push('d');
    while (que.empty() == false)
    {
        cout << que.pop() << " ";
    }
    return 0;
}