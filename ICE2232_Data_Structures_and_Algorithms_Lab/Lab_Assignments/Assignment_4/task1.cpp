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

    Node<T> *root;

    Node<T> *deallocate(Node<T> *&tmpRoot)
    {
        if (tmpRoot == nullptr)
            return tmpRoot;
        // going deeper into the BST
        deallocate(tmpRoot->left);
        deallocate(tmpRoot->right);
        // at the deepest point delete the node
        delete tmpRoot;
        // set the pointer null
        tmpRoot = nullptr;
        return tmpRoot;
    }

    void insert_private(const T &val, Node<T> *&tmpRoot)
    {
        if (tmpRoot == nullptr)
        {
            tmpRoot = new Node<T>(val); // when no node is present in the BST, set new value's node as root
            return;
        }

        if (val < tmpRoot->data) // if val is less than current root's value
            insert_private(val, tmpRoot->left); // the val must be at the left subtree
        else // if val is not less than current root's value
            insert_private(val, tmpRoot->right); // tha val must be at the right subtree
        return;
    }

    void preOrder_private(Node<T> *&tmpRoot)
    {
        if (tmpRoot == nullptr) // if no node is available
            return;

        cout << tmpRoot->data << " "; // processesing before going deeper, it is called pre order

        preOrder_private(tmpRoot->left); // going into left subtree
        preOrder_private(tmpRoot->right); // going into right subtree
    }

    void inOrder_private(Node<T> *&tmpRoot)
    {
        if (tmpRoot == nullptr) // if no node is available
            return;

        inOrder_private(tmpRoot->left); // going into left subtree

        cout << tmpRoot->data << " "; // processesing between going deeper left and right, it is called in order

        inOrder_private(tmpRoot->right); // going into right subtree
    }

    void postOrder_private(Node<T> *&tmpRoot)
    {
        if (tmpRoot == nullptr) // if no node is available
            return;

        postOrder_private(tmpRoot->left); // going into left subtree
        postOrder_private(tmpRoot->right); // going into right subtree

        cout << tmpRoot->data << " "; // processesing after going deeper, it is called post order
    }

    bool find_private(const T &val, Node<T> *tmpRoot)
    {
        if (tmpRoot == nullptr) // if no node is available
            return false;
        if (tmpRoot->data == val) // if current root's value is equal to val
            return true;

        if (val < tmpRoot->data) // if val is less than current root's value
            return find_private(val, tmpRoot->left); // the val must be at the left subtree
        else // if val is not less than current root's value
            return find_private(val, tmpRoot->right); // tha val must be at the right subtree
    }

    int pathLength_private(Node<T> *tmpRoot, int depth)
    {
        if (tmpRoot == nullptr)
            return 0;

        int leftDepth = pathLength_private(tmpRoot->left, depth + 1); // calculating path length of left subtree
        int rightDepth = pathLength_private(tmpRoot->right, depth + 1); // calculating path length of right subtree

        return depth + leftDepth + rightDepth;
    }

public:
    // constructor
    BST() : root(nullptr){};
    // destructor
    ~BST()
    {
        // a post order operation to free memory
        deallocate(root);
    }
    void insert(const T &val)
    {
        // inserting the value in the appropriate plase in the BST
        insert_private(val, root);
    }
    void preOrder()
    {
        // pre order traversal and print the values
        cout << "Pre-Order traversal: ";
        preOrder_private(root);
        cout << "\n";
    }
    void inOrder()
    {
        // in order traversal and print the values
        cout << "In-Order traversal: ";
        inOrder_private(root);
        cout << "\n";
    }
    void postOrder()
    {
        // post order traversal and print the values
        cout << "Post-Order traversal: ";
        postOrder_private(root);
        cout << "\n";
    }
    bool find(const T &val)
    {
        // find the value in the BST
        return find_private(val, root);
    }
    int pathLength()
    {
        // calculate the sum of distance of all nodes from the root node of the BST
        return pathLength_private(root, 0);
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
