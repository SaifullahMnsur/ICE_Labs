// ICE2232 - Data Structures and Algorithms Lab
// Exam - 2022
// Lab Final Exam
// Problem: 2
// Solution by: Saifullah (ICE 21)

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

class SLL
{
private:
    Node *head;

public:
    SLL() : head(nullptr) {}
    ~SLL()
    {
        while (head != nullptr)
        {
            Node *temp = head->next;
            delete head;
            head = temp;
        }
    }
    void print()
    {
        cout << "Current List: ";
        Node *temp = head;
        while( temp != nullptr )
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n\n";
    }
    void insertBegin(int val)
    {
        Node *newNode = new Node(val);
        if (newNode == nullptr)
        {
            cerr << "Memory allocation failed!\n";
            exit(1);
        }
        newNode->next = head;
        head = newNode;
        return;
    }
    void deleteOne(int val)
    {
        if (head == nullptr)
        {
            cout << "Not found! Deletation Unseccessful\n";
            return;
        }
        Node *temp = head;
        if (temp->data == val)
        {
            head = head->next;
            delete temp;
            cout << "Found! The element is deleted...!!\n";
            return;
        }
        while (temp->next != nullptr && temp->next->data != val)
        {
            temp = temp->next;
        }
        if (temp->next == nullptr)
        {
            cout << "Not found! Deletation Unseccessful\n";
            return;
        }
        Node *temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
        cout << "Found! The element is deleted...!!\n";
        return;
    }
    void deleteAll(int val)
    {
        if (head == nullptr)
        {
            cout << "Not found! Deletation Unseccessful\n";
            return;
        }
        Node *temp = head;
        bool deleted = false;
        while ( temp != nullptr && temp->data == val)
        {
            head = head->next;
            delete temp;
            temp = head;
            deleted = true;
        }
        while ( temp != nullptr && temp->next != nullptr)
        {
            if (temp->next->data == val)
            {
                Node *temp2 = temp->next;
                temp->next = temp2->next;
                delete temp2;
                deleted = true;
            }
            temp = temp->next;
        }
        if (deleted == true)
            cout << "Found! The element is deleted...!!\n";
        else
            cout << "Not found! Deletation Unseccessful\n";
        return;
    }
};

int main()
{
    SLL myList;
    int choice = -1;
    while (choice != 0)
    {
        cout << "1: Insert the given element at the beginning!\n";
        cout << "2. Delete the first node of given data\n";
        cout << "3. Delete all the node of given data\n";
        cin >> choice;
        if (choice >= 1 and choice <= 3)
        {
            int val;
            cout << "Enter value: ";
            cin >> val;
            if( choice == 1)
                myList.insertBegin(val);
            else if( choice == 2 )
                myList.deleteOne(val);
            else if( choice == 3 )
                myList.deleteAll(val);
            myList.print();
        }
        else if (choice != 0)
        {
            cout << "Wrong input!\n";
        }
    }
    cout << "Program end!\n";
    return 0;
}