#include <iostream>
#include "linked_queue_classes.hpp"

Node::Node(/* args */){
    data = 0;
    ID = 0;
    next = nullptr;
    previous = nullptr;
};

Node::~Node(){
    data = 0;
    ID = 0;
    next = nullptr;
    previous = nullptr;
};

Queue::Queue(){
    head = nullptr;
    tail = nullptr;
    length = 0;
};

int Queue::enqueue(Node* QueuedNode){
 
    QueuedNode->next = tail;
    tail = QueuedNode;
    length ++;
    if(tail->next == nullptr)
    {
        head = QueuedNode;
    };
};

int main() {

    

    return 0;
}
