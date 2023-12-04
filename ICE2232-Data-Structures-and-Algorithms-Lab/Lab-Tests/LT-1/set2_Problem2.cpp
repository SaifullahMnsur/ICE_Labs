// ICE2232 - Data Structures and Algorithms Lab
// Exam - 2022

// Set: 2
// Problem No: 2
// Solution by: Saifullah (ICE 21)

#include <iostream>
using namespace std;

struct Node // defining the required node structure
{
    char c;
    Node *next;  // next node's pointer
    Node(char ch) // when node structure is called along with 2 more integer value
    {
        c = ch;
        next = nullptr; // assuming next pointer is NULL
    }
};

class List
{
private:
    Node *head, *tail; // private head for the object

public:
    List() // constructor, called upon declaring the object
    {
        head = nullptr;
    }
    ~List() // destructor, called upon the end of program to free the memory
    {
        while (head != nullptr)
        {
            Node *temp = head->next;
            delete head;
            head = temp;
        }
    }
    void insert(char ch)
    {
        Node *newNode = new Node(ch);
        if( head == nullptr ) // if list is empty
        {
            head = newNode; // new node is head
            tail = newNode; // new node is the tail as well
        }
        else
        {
            tail->next = newNode; // new node is the next node of tail;
        }
        tail = newNode; // new node is the new tail
    }
    void list_it( char str[] )
    {
        for( int i = 0; str[i] != '\0'; i++ )
        {
            this->insert(str[i]); // insert ith charecter of str into the list
        }
    }
    void show()
    {
        Node *curr = head; // letting the head node is current node
        cout << "Current List: ";
        while (curr != nullptr) // untill current node reaches the end of the list
        {
             cout << curr->c; // printing values
            if (curr->next != nullptr) // if more nodes are ahead
                cout << " -> ";
            curr = curr->next; // setting current's next as current node
        }
        cout << "\n";
    }
};

int main()
{
    List ICE; // Declaring the ICE_St_List
    char str[1000]; // declaring an string
    cout << "Enter a line (max 1000): ";
    cin.getline(str, 1000); // taking input of a whole line
    ICE.list_it(str); // listing the string into the ICE list
    ICE.show(); // showing the list
    return 0;
}