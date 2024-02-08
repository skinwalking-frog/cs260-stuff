#include <iostream>
#include "helper.hpp"

using std::cout;
using std::endl;


//method definitions
Node::Node(int D = 0){
    data = D;
    next = nullptr;
    last = nullptr;
    index = -1;
};

Node::~Node(){
    data = 0;
    next = nullptr;
    last = nullptr;
    index = -1;
};

List::List(){
    start = nullptr;
    end = nullptr;
    length = 0;
};

//adds node to list at index "pos" with node contents "data".
void List::AddAtPos(int pos, int data){
    //if defined index is negative, use 0.
    if(pos < 0){
        pos = 0;
    //if defined index is out of range of list length, append to end of list.
    }else if(length < pos){
        //length is absolute, pos is zero-indexed. if length == pos there is no problem.
        pos = length;
    };

    Node* newnode = new Node(data);
    
    //if list is empty, overide user defined index to 0.
    if(start == nullptr){
        newnode->index = 0;
        start = newnode;
        end = newnode;
        length ++;
    //else if desired pos == length of list, we are only appending to end of List.
    }else if(pos == length){
            newnode->index = pos;
            end->next = newnode;
            newnode->last = end;
            end = newnode;
            length++;
    //else if we are just adding to the front
    }else if(pos == 0){
        
    }else{
        Node* current = end;
        bool reached = false;
        while(reached == false){
            if(current->index == pos){
                reached = true;
                current->index++;
            }else{  
                current->index++;
                current = current->last;
            };
        };
        newnode->index = pos;
        newnode->next = current;
        newnode->last = current->last;
        current->last->next = newnode;
        current->last = newnode;
        length++;
    };
};