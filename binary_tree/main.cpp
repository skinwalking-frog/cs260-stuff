#include "tree_classes.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main(){
    BinaryTree tree = BinaryTree();
    
    tree.Add(5);
    tree.Add(3);
    tree.Add(2);
    tree.Add(4);
    tree.Add(7);
    tree.Add(6);
    tree.Add(8);

    cout << "in order\n";
    tree.Display_in_order(tree.root);
    cout << "top-bottom\n";
    tree.Display_Tree(tree.root);

    return 0;
}