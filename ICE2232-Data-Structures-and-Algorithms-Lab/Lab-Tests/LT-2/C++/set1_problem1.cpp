// ICE2232 - Data Structures and Algorithms Lab
// Exam - 2022
// Lab Test: 2
// Set: 1
// Problem No: 1
// Solution by: Saifullah (ICE 21)

// topics: tree, binary tree, binary search tree, recursion, dynamic memory, struture, tree traversal, math

#include <iostream>
using namespace std;

class BST
{
private:
    struct Node
    {
        int data;
        Node *right, *left; // left and right node's pointer
        Node(const int &val) : data(val), left(nullptr), right(nullptr){};
    };

    Node *bstRoot;

    Node *deallocate(Node *&root)
    {
        if (root == nullptr)
            return root;
        // going deeper into the BST
        deallocate(root->left);  // deallocating left subtree
        deallocate(root->right); // deallocating right subtree
        // at the deepest point delete the node
        delete root;
        // set the pointer null
        root = nullptr;
        return root;
    }

    void insert_private(const int &val, Node *&root)
    {
        if (root == nullptr)
        {
            root = new Node(val); // when no node is present in the BST, set new value's node as root
            if (root == NULL)     // due to memory overflow or system error
            {
                cerr << "Memory Allocation failed!\n";
                exit(1);
            }
            return;
        }

        if (val < root->data)                 // if val is less than current root's value
            insert_private(val, root->left);  // the val must be at the left subtree
        else                                  // if val is not less than current root's value
            insert_private(val, root->right); // tha val must be at the right subtree
        return;
    }

    void inOrder_private(Node *&root)
    {
        if (root == nullptr) // if no node is available
            return;

        inOrder_private(root->left); // going into left subtree

        cout << root->data << " "; // processesing between going deeper left and right, it is called in order

        inOrder_private(root->right); // going into right subtree
    }

    Node *find(Node *root, const int &val)
    {
        if (root == nullptr) // if no node is available
            return nullptr;
        if (root->data == val) // if current root's value is equal to val
            return root;

        if (val < root->data)              // if val is less than current root's value
            return find(root->left, val);  // the val must be at the left subtree
        else                               // if val is not less than current root's value
            return find(root->right, val); // tha val must be at the right subtree
    }
    // calculate height of the node of the given value
    int calHeight(Node *root, int ht)
    {
        if (root == NULL)
            return ht - 1;
        return max(calHeight(root->left, ht + 1), calHeight(root->right, ht + 1));
    }

public:
    BST() : bstRoot(nullptr){};
    ~BST()
    {
        // a post order operation to free memory
        deallocate(bstRoot);
    }
    void insert(const int &val)
    {
        // inserting the value in the appropriate plase in the BST
        insert_private(val, bstRoot);
    }
    void inOrder()
    {
        // in order traversal and print the values
        cout << "In-Order traversal: ";
        inOrder_private(bstRoot);
        cout << "\n";
    }
    int height(int &val)
    {
        // find the node of given value
        struct Node *valNode = find(bstRoot, val);
        // if the value is not found
        if (valNode == NULL)
        {
            cout << "%d is not found in the BST\n\n";
            return 0;
        }
        // return the height
        return calHeight(valNode, 0);
    }
};

main()
{
    BST bst;
    int choose, val, height;
    do
    {
        cout << "\n1: insert\n";
        cout << "2: In-order Traverse\n";
        cout << "3: Height of a node\n";
        cout << "-1: Exit\n\n";
        cin >> choose;
        switch (choose)
        {
        case 1:
            // insert a value into the BST at it's correct position
            cout << "Enter value to insert: ";
            cin >> val;
            bst.insert(val);
            break;
        case 2:
            // traverse the BST in-order
            cout << "In-order traversal is: ";
            bst.inOrder();
            cout << "\n\n";
            break;
        case 3:
            // find the height of the node of a given value
            // height is the maximum distance from a given node to any leaf node
            cout << "Enter a value of node: ";
            cin >> val;
            cout << "Height of " << val << " is : " << bst.height(val) << "\n\n";
            break;
        case -1:
            cout << "\nEnding program!\n\n";
        default:
            break;
        }
    } while (choose != -1);
    return 0;
}