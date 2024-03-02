#include "tree_classes.hpp"

//Node constructor
Node::Node(int value = 0){
    data = value;
    left = nullptr;
    right = nullptr;
}
//BinaryTree constructor
BinaryTree::BinaryTree(){
    root = nullptr;
};

//recursive method to find the parent node of where we want to add a node.
Node* BinaryTree::rec_parent_search(int search_value, Node* search_node){
    Node* return_val;
    if (search_node == nullptr){
        return_val = nullptr;
    }else{
        if(search_value < search_node->data){
            return_val = rec_parent_search(search_value, search_node->left);
        }else{
            return_val = rec_parent_search(search_value, search_node->right);
        };
        if(return_val == nullptr){
            return_val = search_node;
        };
    };
    return return_val;
};

//method to add a Node to the tree, uses the recursive_parent_search method.
void BinaryTree::Add(int new_value){
    Node* destination_parent = rec_parent_search(new_value, root);
    Node* new_node = new Node(new_value);
    if (new_value < destination_parent->data) {
        destination_parent->left = new_node;
    }else {
        destination_parent->right = new_node;
    };  
};

void BinaryTree::Remove(int ){
    
}

bool BinaryTree::Search(int search_value, Node* search_node){

    bool return_val;
    if (search_node == nullptr){
        return_val = false;
    }else{
        if(search_value < search_node->data){
            return_val = rec_parent_search(search_value, search_node->left);
        }else if(search_value > search_node->data){
            return_val = rec_parent_search(search_value, search_node->right);
        }else{
            return_val = true;
        };
    };
    return return_val;
}

void BinaryTree::Display(){

}