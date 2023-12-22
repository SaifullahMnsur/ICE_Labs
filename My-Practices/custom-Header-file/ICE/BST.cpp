#include "BST"
#include "traversal"

template <typename T>
BST<T>::BST() : root(nullptr) {}

template <typename T>
void BST<T>::insert(T value)
{
    insert(root, value);
    return;
}

template <typename T>
bool BST<T>::find(T value)
{
    return address(root, value) != nullptr;
}

template <typename T>
treeNode<T>* BST<T>::address(T value)
{
    return address(root, value);
}

template <typename T>
long long BST<T>::depth(T value)
{
    return depth(root, value, 0);
}

template <typename T>
long long BST<T>::height(T value)
{
    treeNode<T> *value_address = address(root, value);
    if( value_address == nullptr )
        return -1;
    return height(value_address, value);
}

template <typename T>
long long BST<T>::path_length()
{
    return path_length(root, 0);
}

template <typename T>
void BST<T>::preorder()
{
    traverser.preorder(root);
}

template <typename T>
void BST<T>::inorder()
{
    traverser.inorder(root);
}

template <typename T>
void BST<T>::postorder()
{
    traverser.postorder(root);
}

template <typename T>
void BST<T>::insert(treeNode<T> *&root, T value)
{
    if (root == nullptr)
    {
        root = new treeNode<T>(value);
        if (root == nullptr)
        {
            std::cerr << "Error creating new node!\n";
            exit(1);
        }
        return;
    }
    if (value < root->data)
        insert(root->left, value);
    else
        insert(root->right, value);
    return;
}

template <typename T>
long long BST<T>::depth(treeNode<T> *root, T value, long long curr_depth)
{
    if( root == nullptr )
        return -1;
    if( root->data == value )
        return curr_depth;
    if( value < root->data)
        return depth(root->left, value, curr_depth+1);
    else
        return depth(root->right, value, curr_depth+1);
}

template <typename T>
long long BST<T>::height(treeNode<T> *root, T value)
{
    if( root == nullptr )
        return -1;
    return 1 + std::max(height(root->left, value), height(root->right, value));
}

template <typename T>
treeNode<T>* BST<T>::address(treeNode<T> *root, T value)
{
    if (root == nullptr || value == root->data)
        return root;
    if (value < root->data)
    {
        return address(root->left, value);
    }
    else
    {
        return address(root->right, value);
    }
}

template <typename T>
long long BST<T>::path_length(treeNode<T> *root, long long curr_depth)
{
    if( root == nullptr )
        return 0;
    return curr_depth + path_length(root->left, curr_depth+1) + path_length(root->right, curr_depth+1);
}