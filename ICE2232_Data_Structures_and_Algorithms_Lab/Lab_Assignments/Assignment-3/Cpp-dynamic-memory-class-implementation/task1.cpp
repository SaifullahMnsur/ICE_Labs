// ICE2232 - Data Structures and Algorithms Lab
// Exam - 2022
// Assignment: 3

// Task: 1
// Solution by: Saifullah (ICE 21)

#include <iostream>
#include <string.h>
using namespace std;

template <typename T>
struct node
{
    T data;
    node *next;

    node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class stack_queue
{
private:
    node<T> *front, *top;
    bool qstate;

    void q_print(node<T> *curr)
    {
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << "\n\n";
        return;
    }
    void s_print(node<T> *curr)
    {
        if (curr == nullptr)
            return;

        s_print(curr->next);

        cout << curr->data << "\n";
        return;
    }
    void common_pop()
    {
        delete front;
        front = nullptr;
        top = nullptr;
        return;
    }
    void LIFO_pop()
    {
        if (front == top)
            common_pop();
        else if( front != nullptr )
        {
            node<T> *temp = front;

            while (temp->next->next != nullptr)
                temp = temp->next;

            delete top;
            top = temp;
            top->next = nullptr;
        }
        return;
    }
    void FIFO_pop()
    {
        if (front == top)
            common_pop();
        else if( front != nullptr )
        {
            node<T> *temp = front->next;
            delete front;
            front = temp;
        }
        return;
    }

public:
    // constructor
    stack_queue() : front(nullptr), top(nullptr), qstate(true){};
    // destructor
    ~stack_queue()
    {
        while (front != nullptr)
        {
            node<T> *temp = front;
            front = front->next;
            delete temp;
        }
    }

    // print stack/queue
    void print()
    {
        cout << "Your " << (qstate ? "QUEUE " : "STACK ") << "is: ";
        if (front == nullptr)
        {
            cout << "Empty!\n\n";
            return;
        }
        if (qstate == true)
        {
            q_print(front);
            return;
        }
        else
        {
            cout << "\n";
            s_print(front);
            cout << "\n";
        }
        return;
    }

    // pop element
    void pop()
    {
        qstate ? FIFO_pop() : LIFO_pop(); // if it is queue state then follow FIFO, or else LIFO
    }

    // push element
    void push(const T &val) // pushing new value
    {
        node<T> *newNode = new node(val);
        if (top == nullptr)
            front = newNode;
        else
            top->next = newNode;
        top = newNode;
    }

    // update stack/queue mode
    void mode(const bool stt)
    {
        qstate = stt;
    }
};

int main()
{
    stack_queue<int> sq;
    while (true)
    {
        char input[50];
        cin >> input;                // taking an input
        if (strcmp(input, "Q") == 0) // if input is Q
        {
            printf("Program ended here\n");
            return 0;
        }
        else if (strcmp(input, "q") == 0) // if input is q
        {
            printf("QUEUE MODE enabled\n");
            sq.mode(true); // queue mode
        }
        else if (strcmp(input, "s") == 0) // if input is s
        {
            printf("STACK MODE enabeld\n");
            sq.mode(false); // stack mode
        }
        else if (strcmp(input, "p") == 0) // if input is p
        {
            sq.pop(); // deleting element from stack/queue
        }
        else // if input is anything else
        {
            int num = 0;
            for (int i = 0; input[i] != '\0'; i++)
            {
                if (input[i] < '0' || input[i] >= '9' || i > 9) // checking if input is a valid integer
                {
                    printf("Invalid input\nEnter a valid input!\n");
                    continue;
                }
                num = num * 10 + input[i] - '0';
            }
            sq.push(num); // pushing input integer into stack/queue
        }
        sq.print(); // printing stack/queue
    }
    return 0;
}