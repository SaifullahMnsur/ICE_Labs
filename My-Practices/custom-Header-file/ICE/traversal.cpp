#include "traversal"
#include "BST"

#include <iostream>

template <typename T>
void traversal<T>::preorder(treeNode<T> *root)
{
    if (root == nullptr)
        return;
    std::cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
    return;
}

template <typename T>
void traversal<T>::inorder(treeNode<T> *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
    return;
}

template <typename T>
void traversal<T>::postorder(treeNode<T> *root)
{
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    std::cout << root->data << " ";
    return;
}

