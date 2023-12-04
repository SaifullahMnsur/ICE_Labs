// ICE2232 - Data Structures and Algorithms Lab
// Exam - 2022

// Set: 1
// Problem No: 2
// Solution by: Saifullah (ICE 21)

#include <iostream>
using namespace std;

struct Node // defining the required node structure
{
    int ID;              // integer type 2digit id
    int year;            // integer type 1digit year
    Node *next;          // next node's pointer
    Node(int id, int yr) // when node structure is called along with 2 more integer value
    {
        ID = id % 100;  // assuming first integer is id, to ensure it is 2 digit modding it with 100
        year = yr % 10; // assuming second integer is year, to ensure it is 1 digit modding it with 10
        next = nullptr; // assuming next pointer is NULL
    }
};

class List
{
private:
    Node *head; // private head for the object

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

    void insert(int id, int yr)
    {
        Node *newNode = new Node(id, yr); // creating new node and setting up it's values
        if (head != nullptr)              // if head is present then new node's head should be head
            newNode->next = head;
        head = newNode; // new node is the new head
        this->show();   // showing the list
    }

    void show()
    {
        Node *curr = head; // letting the head node is current node
        cout << "Current List: ";
        while (curr != nullptr) // untill current node reaches the end of the list
        {
            cout << curr->ID << " " << curr->year; // printing values
            if (curr->next != nullptr)             // if more nodes are ahead
                cout << " -> ";
            curr = curr->next; // setting current's next as current node
        }
        cout << "\n";
    }
};

int main()
{
    List ICE_St_List;                                                                                 // Declaring the ICE_St_List
    int id, yr;                                                                                       // Variable to be used to take input
    cout << "Keep entering 2 digit id and 1 digit year to insert into the list or Enter 0 to end:\n"; // Giving input instructions
    while (true)
    {
        cin >> id;   // first take id
        if (id == 0) // if id is 0 that means the user ended inputting
            break;
        cin >> yr;                  // take year
        ICE_St_List.insert(id, yr); // insert into the list
    }
    return 0;
}