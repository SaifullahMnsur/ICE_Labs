// ICE2232 - Data Structures and Algorithms Lab
// Exam - 2022
// Assignment: 4

// Task: 1
// Solution by: Saifullah (ICE 21)

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *right, *left;
    Node(int val) : data(val), left(nullptr), right(nullptr){};
};

class BST
{
private:
    Node *bstRoot;

    Node *deallocate(Node *&root)
    {
        if (root == nullptr)
            return root;
        
        deallocate(root->left);
        deallocate(root->right);
        delete root;
        root = nullptr;
        return root;
    }

    void insert_private( int &val, Node *&root)
    {
        if (root == nullptr)
        {
            root = new Node(val);
            if( root == nullptr )
            {
                cerr << "Memory allocation failed!\n";
                exit(1);
            }
            return;
        }

        if (val < root->data)
            insert_private(val, root->left);
        else
            insert_private(val, root->right);
        return;
    }

    void preOrder_private(Node *&root)
    {
        if (root == nullptr)
            return;

        cout << root->data << " ";

        preOrder_private(root->left);
        preOrder_private(root->right);
    }

    void inOrder_private(Node *&root)
    {
        if (root == nullptr)
            return;

        inOrder_private(root->left);

        cout << root->data << " ";

        inOrder_private(root->right);
    }

    void postOrder_private(Node *&root)
    {
        if (root == nullptr)
            return;

        postOrder_private(root->left);
        postOrder_private(root->right);

        cout << root->data << " ";
    }
    void printGreater_private(Node *&root, int val)
    {
        if (root == nullptr)
            return;

        printGreater_private(root->left, val);
        if( root->data >= val )
            cout << root->data << " ";

        printGreater_private(root->right, val);
    }

public:
    BST() : bstRoot(nullptr){};
    ~BST()
    {
        deallocate(bstRoot);
    }
    void insert(int &val)
    {
        insert_private(val, bstRoot);
    }
    void preOrder()
    {
        cout << "Pre-Order traversal: ";
        preOrder_private(bstRoot);
        cout << "\n";
    }
    void inOrder()
    {
        cout << "In-Order traversal: ";
        inOrder_private(bstRoot);
        cout << "\n";
    }
    void postOrder()
    {
        cout << "Post-Order traversal: ";
        postOrder_private(bstRoot);
        cout << "\n";
    }
    void printGreater( int val )
    {
        cout << "Values greater than or eqauls to " << val << " are: ";
        printGreater_private(bstRoot, val);
        cout << "\n";
    }
};

int main()
{
    BST bst;
    cout << "Instructions:\n";
    cout << "1 : insert into the BST\n";
    cout << "2 : Pre-Order traversal\n";
    cout << "3 : In-Order traversal\n";
    cout << "4 : Post-Order traversal\n";
    cout << "4 : Print all value greater than or equal given value\n";
    cout << "0 : exit\n\n";
    int choice;
    int val;
    do
    {
        cin >> choice;
        if (choice == 1)
        {
            cin >> val;
            bst.insert(val);
        }
        else if (choice == 2)
            bst.preOrder();
        else if (choice == 3)
            bst.inOrder();
        else if (choice == 4)
            bst.postOrder();
        else if( choice == 5 )
        {
            cin >> val;
            bst.printGreater(val);
        }
        else if (choice != 0)
            cout << "Wrong choice! try again!\n";
        cout << "\n";
    } while (choice != 0);

    cout << "Program finished!\n\n";

    return 0;
}