#include "tree_classes.hpp"
#include <iostream>
#include <queue>

using std::cout;
using std::endl;
using std::queue;

//Node constructor
Node::Node(int value = 0){
    data = value;
    left = nullptr;
    right = nullptr;
}

//Node destructor
Node::~Node(){
    data = 0;
}

//BinaryTree constructor
BinaryTree::BinaryTree(){
    root = nullptr;
}

BinaryTree::~BinaryTree(){
    Delete_tree(root);
}

void BinaryTree::Delete_tree(Node* node){
    if(node != nullptr){
        Node* left = node->left;
        Node* right = node->right;
        delete node;
        Delete_tree(left);
        Delete_tree(right);
    }
}

//searches everything from input node down, start at root node to search whole tree
bool BinaryTree::Search(int search_value, Node* search_node){
    //return true if value is in tree, else false
    bool return_val;
    if (search_node == nullptr){
        return_val = false;
    }else{
        if(search_value < search_node->data){
            return_val = Search(search_value, search_node->left);
        }else if(search_value > search_node->data){
            return_val = Search(search_value, search_node->right);
        }else{
            return_val = true;
        };
    };
    return return_val;
}

//recursive method to find the parent node of where we want to add a node
Node* BinaryTree::Add_parent_search(int search_value, Node* start){
    //return the pointer to the parent of node
    Node* return_val;
    if (start == nullptr){
        return_val = nullptr;
    }else{
        if(search_value < start->data){
            return_val = Add_parent_search(search_value, start->left);
        }else{
            return_val = Add_parent_search(search_value, start->right);
        };

        if(return_val == nullptr){
            return_val = start;
        };
    };
    return return_val; 
}

//private method to get the parent node of the first node with matching value below start node
Node* BinaryTree::Get_parent(int value, Node* start){
    Node* return_val = nullptr;
    if(start->left->data == value || start->right->data == value){
        return_val = start;
    }else if(value < start->data){
        return_val = Get_parent(value, start->left);
    }else{
        return_val = Get_parent(value, start->right);
    }
    return return_val;
}

//method to find replacement node for a deleted node recursively, 
//use the node directly left or right of the node we are finding a replacement for as the start 
//value should be the data of the node we are finding a replacement for
Node* BinaryTree::Find_replacement(int value, Node* start){
    Node* return_val = nullptr;
    // cout << "start " << start << endl;
    // if(start != nullptr){
    //     cout << "start->data " << start->data << endl;
    // }
    if(start == nullptr){
        return_val = nullptr;
    }else{
        if(start->data > value){
            return_val = Find_replacement(value, start->left);
            if(return_val == nullptr){
                return_val = start;
            }
        }else if(start->data < value){
            return_val = Find_replacement(value, start->right);
            if(return_val == nullptr){
                return_val = start;
            }
        }else{
            return_val = start;
        }
    }
    // cout << "return_val " << return_val << endl;
    // if(return_val != nullptr){
    //     cout << "return_val->data " << return_val->data << endl;
    // }

    return return_val;
}

//method to add a Node to the tree, uses the Add_parent_search method
void BinaryTree::Add(int new_value){
    Node* destination_parent = Add_parent_search(new_value, root);
    Node* new_node = new Node(new_value);
    //parent == nullptr when tree is empty
    if(destination_parent == nullptr){
        root = new_node;
    }else if (new_value < destination_parent->data) {
        destination_parent->left = new_node;
    }else {
        destination_parent->right = new_node;
    };  
}

void BinaryTree::Remove(int value){    
    Node* node_to_del = nullptr;
    Node* parent = root;
    Node* current = root;

    bool found = false;

    //find the matching node to delete and its parent
    while(found == false){
        if(current->data == value){
            node_to_del = current;
            found = true;
        }else if(current->data < value && current->right != nullptr){
            parent = current;
            current = current->right;
        }else if(current->data > value && current->left != nullptr){
            parent = current;
            current = current->left;
        }else{
            cout << "value does not exist in tree!";
            break;
        }
    }

    if(found == true){
        // cout << node_to_del->data << endl;
        // cout << parent->data << endl;
        //set variables for node directly left and right of node we want to delete
        Node* first_left = node_to_del->left;
        Node* first_right = node_to_del->right;
        Node* option_A = nullptr;
        Node* option_B = nullptr;

        // cout << "found data: " << node_to_del->data << endl;
        
        // if(first_left != nullptr){  
        //     cout << "first L data: " << first_left->data << endl;
        //     cout << "first L: " << first_left << endl;
        //     // cout << "first L R: " << first_left->right << endl;
        // }
        // if(first_right != nullptr){
        //     cout << "first R data: " << first_right->data << endl; 
        //     cout << "first R: " << first_right << endl;      
        //     // cout << "First R L: " << first_right->left << endl;
        // }

        //find replacement options from right and left if they exist
        if(first_left != nullptr){
            option_A = Find_replacement(value, first_left);
            // cout << "option A found\n";
        }
        if(first_right != nullptr){
            option_B = Find_replacement(value, first_right);
            // cout << "option B found\n";
        }

        // if(option_A != nullptr){
        // cout << "option A" << option_A->data << endl;
        // }else{
        //     cout << "option A is null" << endl;
        // }
        // if(option_B != nullptr){
        // cout << "option B" << option_B->data << endl;
        // }else{ 
        //     cout <<"option B is null" << endl;
        // }

        //if option_A is closer to the original value than option_B, or if of equal distance
        if(option_A != nullptr && (option_B != nullptr && ((value - option_A->data) < (option_B->data - value)) || option_B == nullptr)){
            // cout << "option A taken\n";
            
            //get the parent of the option we pick starting at the node to delete
            Node* option_parent = Get_parent(option_A->data, node_to_del);
            
            // cout << "option parent " << option_parent->data << endl;
            //set replacement option's parent's child to nullptr
            if(option_parent->left == option_A){
                option_parent->left = nullptr;
            }else if(option_parent->right == option_A){
                option_parent->right = nullptr;
            }
            
            //set replacement options children to node to delete's children (if option is immediate child of node to delete, )
            option_A->left = node_to_del->left;
            option_A->right = node_to_del->right;

            //replace the node we want to delete with the replacement option
            if(parent->left == node_to_del){
                parent->left = option_A;
            }else if(parent->right == node_to_del){
                parent->right = option_A;
            }
        
            delete node_to_del;
        

        //else option_B is closer to the original value   
        }else if(option_B != nullptr && (option_A != nullptr && ((value - option_A->data) >= (option_B->data - value)) || option_A == nullptr)){
            // cout << "option B taken\n";
           
            //get the parent of the option we pick starting at the node to delete
            Node* option_parent = Get_parent(option_B->data, node_to_del);

            //set replacement option's parent's child to nullptr
            if(option_parent->left == option_B){
                option_parent->left = nullptr;
            }else if(option_parent->right == option_B){
                option_parent->right = nullptr;
            }
            
            //set replacement options children to node to delete's children (if option is immediate child of node to delete, )
            option_B->left = node_to_del->left;
            option_B->right = node_to_del->right;

            //replace the node we want to delete with the replacement option
            if(parent->left == node_to_del){
                parent->left = option_B;
            }else if(parent->right == node_to_del){
                parent->right = option_B;
            }

            delete node_to_del;
        }else{
            if(parent->left == node_to_del){
                parent->left = nullptr;
            }else if(parent->right == node_to_del){
                parent->right = nullptr;
            }
            delete node_to_del;
        }
    }
}

//print values of tree in order of smallest to largest from starting node chosen
void BinaryTree::Display_in_order(Node* start){
    if(start != nullptr){
        if(start->left != nullptr){
            Display_in_order(start->left);
        }
        cout << start->data << endl;
        if(start->right != nullptr){
            Display_in_order(start->right);
        }
    }
    
}

//print values of tree from top to bottom from starting node;
//chatGPT helped teach me the concept of how to use a queue to print row by row.
void BinaryTree::Display_Tree(Node* start){
    if(start != nullptr){
        queue<Node*> Q;
        Q.push(start);

        while (!Q.empty()){   
            int rowitems = Q.size();
            while (rowitems > 0){
                cout << Q.front()->data << " ";
                if(Q.front()->left != nullptr){
                    Q.push(Q.front()->left);
                }
                if(Q.front()->right != nullptr){
                    Q.push(Q.front()->right);
                }
                Q.pop();
                rowitems--;
            }
            cout << endl;
        }
    }