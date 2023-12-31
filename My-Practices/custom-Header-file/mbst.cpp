#include <iostream>
// #include <ICE/BST>
#include "ICE/ASSIGNMENTS"

int main()
{
    BST<int> bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(1);
    bst.insert(4);
    bst.insert(6);
    bst.insert(10);
    bst.preorder();
    std::cout << "\n";
    bst.inorder();
    std::cout << "\n";
    bst.postorder();
    std::cout << "\n";
    std::cout << bst.find(5) << "\n";
    std::cout << bst.address(5) << "\n";
    std::cout << bst.depth(5) << " " << bst.depth(10) << "\n";
    std::cout << bst.height(5) << " " << bst.height(10) << "\n";
    std::cout << bst.height(7) << " " << bst.depth(7) << "\n";
    std::cout << bst.path_length() << "\n";
    return 0;
}
