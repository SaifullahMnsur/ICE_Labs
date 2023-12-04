// ICE2232 - Data Structures and Algorithms Lab
// Exam - 2022
// Assignment: 4

// Task: 1
// Solution by: Saifullah (ICE 21)

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class BST
{
private:
    template <typename B>
    struct Node
    {
        B data;
        Node<B> *right, *left; // left and right node's pointer
        Node(const B &val) : data(val), left(nullptr), right(nullptr){};
    };

    Node<T> *bstRoot;

    Node<T> *deallocate(Node<T> *&root)
    {
        if (root == nullptr)
            return root;
        // going deeper into the BST
        deallocate(root->left); // deallocating left subtree
        deallocate(root->right); // deallocating right subtree
        // at the deepest point delete the node
        delete root;
        // set the pointer null
        root = nullptr;
        return root;
    }

    void insert_private(const T &val, Node<T> *&root)
    {
        if (root == nullptr)
        {
            root = new Node<T>(val); // when no node is present in the BST, set new value's node as root
            return;
        }

        if (val < root->data) // if val is less than current root's value
            insert_private(val, root->left); // the val must be at the left subtree
        else // if val is not less than current root's value
            insert_private(val, root->right); // tha val must be at the right subtree
        return;
    }

    void preOrder_private(Node<T> *&root)
    {
        if (root == nullptr) // if no node is available
            return;

        cout << root->data << " "; // processesing before going deeper, it is called pre order

        preOrder_private(root->left); // going into left subtree
        preOrder_private(root->right); // going into right subtree
    }

    void inOrder_private(Node<T> *&root)
    {
        if (root == nullptr) // if no node is available
            return;

        inOrder_private(root->left); // going into left subtree

        cout << root->data << " "; // processesing between going deeper left and right, it is called in order

        inOrder_private(root->right); // going into right subtree
    }

    void postOrder_private(Node<T> *&root)
    {
        if (root == nullptr) // if no node is available
            return;

        postOrder_private(root->left); // going into left subtree
        postOrder_private(root->right); // going into right subtree

        cout << root->data << " "; // processesing after going deeper, it is called post order
    }

    bool find_private(const T &val, Node<T> *root)
    {
        if (root == nullptr) // if no node is available
            return false;
        if (root->data == val) // if current root's value is equal to val
            return true;

        if (val < root->data) // if val is less than current root's value
            return find_private(val, root->left); // the val must be at the left subtree
        else // if val is not less than current root's value
            return find_private(val, root->right); // tha val must be at the right subtree
    }

    int pathLength_private(Node<T> *root, int depth)
    {
        if (root == nullptr)
            return 0;

        int leftDepth = pathLength_private(root->left, depth + 1); // calculating path length of left subtree
        int rightDepth = pathLength_private(root->right, depth + 1); // calculating path length of right subtree

        return depth + leftDepth + rightDepth;
    }

public:
    BST() : bstRoot(nullptr){};
    ~BST()
    {
        // a post order operation to free memory
        deallocate(bstRoot);
    }
    void insert(const T &val)
    {
        // inserting the value in the appropriate plase in the BST
        insert_private(val, bstRoot);
    }
    void preOrder()
    {
        // pre order traversal and print the values
        cout << "Pre-Order traversal: ";
        preOrder_private(bstRoot);
        cout << "\n";
    }
    void inOrder()
    {
        // in order traversal and print the values
        cout << "In-Order traversal: ";
        inOrder_private(bstRoot);
        cout << "\n";
    }
    void postOrder()
    {
        // post order traversal and print the values
        cout << "Post-Order traversal: ";
        postOrder_private(bstRoot);
        cout << "\n";
    }
    bool find(const T &val)
    {
        // find the value in the BST
        return find_private(val, bstRoot);
    }
    int pathLength()
    {
        // calculate the sum of distance of all nodes from the root node of the BST
        return pathLength_private(bstRoot, 0);
    }
};

int main()
{
    BST<int> bst;
    cout << "Instructions:\n";
    cout << "ins + integer : insert into the BST\n";
    cout << "f + integer : find the integer into the BST\n";
    cout << "p : path length of the BST\n";
    cout << "pre : Pre-Order traversal\n";
    cout << "in : In-Order traversal\n";
    cout << "post : Post-Order traversal\n";
    cout << "0 : exit\n\n";

    string input;
    int val;
    do
    {
        cin >> input;
        if (input == "ins")
        {
            cin >> val;
            bst.insert(val);
        }
        else if (input == "f")
        {
            cin >> val;
            if (bst.find(val) == true)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        else if (input == "p")
            cout << "Path length of the given BST: " << bst.pathLength() << "\n";
        else if (input == "pre")
            bst.preOrder();
        else if (input == "in")
            bst.inOrder();
        else if (input == "post")
            bst.postOrder();
        else if (input != "0")
            cout << "Wrong input! try again!\n";
        cout << "\n";
    } while (input != "0");

    cout << "Program finished!\n\n";

    return 0;
}