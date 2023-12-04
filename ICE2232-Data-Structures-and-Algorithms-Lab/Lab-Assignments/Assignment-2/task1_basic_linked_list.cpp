#include <iostream>
using namespace std;

/**/

template <typename T>
class List
{
private:
    template <typename B>
    struct Node
    {
        B info;
        Node *next;
        Node(const B &val) : info(val), next(nullptr) {}
    };
    Node<T> *head, *rehead;
    size_t size;

public:
    // Constructor to assign initial values of the linkedlist
    List() : head(nullptr), size(0) {}
    // Destructor to release memory
    ~List()
    {
        while (head != nullptr)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }
    // to return the number of nodes in the linked list
    size_t length()
    {
        return size;
    }
    // to delete last node
    void pop_back()
    {
        if (head == nullptr)
        {
            cerr << "The list is already empty\n";
        }
        size--;
        if (head->next == nullptr) // if head is the only node
        {
            delete head;
            head = nullptr;
            return;
        }
        Node<T> *current = head;
        while (current->next->next != nullptr) // traversing till the 2nd last node of the list
        {
            current = current->next;
        }
        delete current->next;    // deleting the next node of 2nd last node, which is the last node
        current->next = nullptr; // 2nd last node's next node is now NULL
    }
    // to delete first node
    void pop_front()
    {
        if (head == nullptr)
        {
            cerr << "The list is already empty\n";
            return;
        }
        size--;
        Node<T> *temp = head->next; // 2nd element is temp
        delete head;                // deleting head
        head = temp;                // temp is the new head
    }
    // to insert a node at the end
    void push_back(const T &val)
    {
        size++;
        Node<T> *newNode = new Node<T>(val);
        if (head == nullptr)
            head = newNode;
        else
        {
            Node<T> *current = head;
            while (current->next != nullptr) // traversing till the last node
            {
                current = current->next;
            }
            current->next = newNode; // next node of last node is the new node
        }
    }
    // to insert a node at the beginning
    void push_front(const T &val)
    {
        size++;
        Node<T> *newNode = new Node<T>(val);
        newNode->next = head;
        head = newNode;
    }
    // to insert a node at the given position
    void insert(const T &val, const size_t &position)
    {
        if (position < 1 or position > size + 1)
        {
            cerr << "Error position\n"; // error message
        }
        if (position == size + 1) // if insert at first position which is push front
        {
            this->push_back(val);
        }
        else if (position == 1) // if insert at last position which is push back
        {
            this->push_front(val);
        }
        else
        {
            size++;
            Node<T> *newNode = new Node<T>(val);
            Node<T> *current = head;
            size_t currentPosition = 2;
            while (currentPosition < position) // traversing till the position before given position
            {
                current = current->next;
                currentPosition++;
            }
            newNode->next = current->next; // current's next is the next of new node
            current->next = newNode;       // new node is the next of current node
        }
    }
    // to remove all node that contains the given value
    void remove(const T val)
    {
        Node<T> *current = head, *temp = nullptr;
        while (current != nullptr && current->info == val) // if some of the first consecutive node's info is equal to the given value
        {
            size--;
            head = current->next; // next of current is head
            delete current;       // deleting current
            current = head;       // head is current
        }
        if (current == nullptr)
        {
            return;
        }
        while (current->next != nullptr) // if any other node's info is equal to given value
        {
            if (current->next->info == val) // if the next value of current value contains given value
            {
                size--;
                temp = current->next;       // next of current is temp
                current->next = temp->next; // skipping temp
                delete temp;                // deleting temp
            }
            else
            {
                current = current->next; // current's next is new current
            }
        }
    }
    // to print the full linked list
    void show()
    {
        Node<T> *current = head;
        while (current != nullptr) // traversing untill it reaches nullptr
        {
            cout << current->info << " -> ";
            current = current->next;
        }
        cout << "nullptr\n";
    }

    // to remove all the duplicates
    void remove_duplicates()
    {
        if (head == nullptr)
        {
            throw std::runtime_error("Queue is empty");
        }
        Node<T> *current = head;
        while (current != nullptr)
        {
            Node<T> *temp = current->next, *prev = current; // current is the previous node and temp is the the next node of current node
            while (temp != nullptr)
            {
                if (temp->info == current->info) // if current's info is equal to temp's info
                {
                    size--;
                    prev->next = temp->next; // skipping temp node and previous node pointing to the next node of temp node
                    delete temp;
                    temp = prev->next; // next element of previous is new temp node
                }
                else
                {
                    prev = temp;       // temp is the previous node
                    temp = temp->next; // next node of temp is the new temp node
                }
            }
            current = current->next;
        }
    }

    // to swap between every first and second node
    void swap_adjacency()
    {
        if (head == nullptr or head->next == nullptr)
            return;
        Node<T> *current = head, *after = head->next, *prev = nullptr;
        head = after; // 2nd element will be the new head, so doing it earlier
        while (current != nullptr and after != nullptr)
        {
            current->next = after->next; // current's next is the next node of the after node, skipping after
            after->next = current;       // after node should point the current node to swap position and go before current node
            if (prev != nullptr)
            {
                prev->next = after; // setting after node as the next no of previous node, so previous node will be linked to after node
            }
            prev = current;          // now current node will be counted as previous node
            current = current->next; // next node of current is new current node
            if (current != nullptr)
            {
                after = current->next; // after node is the next node of current
            }
        }
    }
    // to traverse through the list used to reorder
    void traverse(Node<T> *current, int n)
    {
        if (current == nullptr)
            return;
        traverse(current->next, n + 1); // traversing to the next node
        if (n == size / 2 + 1)
            current->next = nullptr; // setting the size/2+1 th node as the last node and the next node after it is nullptr
        else if (n > size / 2)       // inserting nth node in between of rehead and the next element of rehead
        {
            Node<T> *temp = rehead->next; // storing the next node address after rehead
            current->next = rehead->next; // setting rehead's next as the nth node's next node
            rehead->next = current;       // rehead's next is nth node
            rehead = temp;                // setting stored note address as the new head, new node must be linked after this
        }
        return;
    }
    // to call for reordering the list
    void reorder()
    {
        if (head == nullptr or head->next == nullptr)
            return;
        rehead = head;                     // setting the head as the rehead
        int n = 1;                         // position of element
        this->traverse(head->next, n + 1); // beginning the traversal
    }
};

int main()
{
    List<int> intList; // intList object

    // TASK 1.2
    intList.push_front(2); // list: 2 -> nullptr
    intList.push_front(1); // list: 1 -> 2 -> nullptr
    intList.push_back(5);  // list: 1 -> 2 -> 5 -> nullptr
    intList.push_back(6);  // list: 1 -> 2 -> 5 -> 6 -> nullptr
    intList.insert(4, 3);  // list: 1 -> 2 -> 4 -> 5 -> 6 -> nullptr
    intList.insert(3, 3);  // list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> nullptr
    intList.push_back(7);  // list: 1 -> 2 -> 5 -> 6 -> -> 7 -> nullptr
    intList.show();
    /*
    // TASK 1.4
    cout << "Initially:\n";
    cout << "Length of the list: " << intList.length() << endl;
    intList.show();

    // Task 1.2: insert 6 at 7 position
    intList.insert(6, 3);
    cout << "\nAfter inserting an elements: 6 at 3\n";
    cout << "Length of the list: " << intList.length() << endl; // TASK 1.5
    intList.show();

    // TASK 1.3: lets remove all the 6 from the list
    intList.remove(5);
    cout << "\nAfter removing an elements: 5\n";
    cout << "Length of the list: " << intList.length() << endl; // TASK 1.5
    intList.show();

    // TASK 2.1: lets remove all the duplicates
    intList.remove_duplicates();
    cout << "\nAfter deleting duplicates:\n";
    cout << "Length of the list: " << intList.length() << endl; // TASK 1.5
    intList.show();

    // TASK 2.2: lets swap adjecency node
    intList.swap_adjacency();
    cout << "\nAfter swapping adjacency nodes:\n";
    cout << "Length of the list: " << intList.length() << endl; // TASK 1.5
    intList.show();
*/
    // TASK 2.3: lets reorder the list
    intList.reorder();
    cout << "\nAfter reordering the list:\n";
    cout << "Length of the list: " << intList.length() << endl; // TASK 1.5
    intList.show();

    return 0;
}