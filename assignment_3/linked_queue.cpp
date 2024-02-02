#include <iostream>
#include "linked_queue_classes.hpp"

using std::cout;
using std::endl;

Node::Node(int D = 0){
    data = D;
    next = nullptr;
    previous = nullptr;
};

Node::~Node(){
    data = 0;
    next = nullptr;
    previous = nullptr;
};

Queue::Queue(){
    head = nullptr;
    tail = nullptr;
    length = 0;
};

int Queue::enqueue(Node* QueuedNode)
{ 
    if(tail == nullptr){
        tail = QueuedNode;
        head = QueuedNode;
        length++;
    } else {
        QueuedNode->next = tail;
        tail->previous = QueuedNode;
        tail = QueuedNode;
        length++;
    }
    return QueuedNode->data;
};

int Queue::dequeue()
{   
    int retval;
    if(head == nullptr){
        cout << "queue is empty!\n";
        retval = 0;
    }else if(head->previous == nullptr){
        retval = head->data;
        Node *todestroy = head;
        head = nullptr;
        delete todestroy;
    }else{
        retval = head->data;
        Node *todestroy = head;
        head = head->previous;
        head->next = nullptr;
        delete todestroy;
    }
    return retval;
}

int main() {
    Queue Q;
    Node * n1 = new Node(4);
    Node * n2 = new Node(5);
    Node * n3 = new Node(6);
    cout << "nodes created with values 4, 5, and 6.\n";
    cout << "queued node with value:" << Q.enqueue(n1) << endl;
    cout << "queued node with value:" << Q.enqueue(n2) << endl;
    cout << "queued node with value:" << Q.enqueue(n3) << endl;
    cout << "dequeued node with value:" << Q.dequeue() << endl;
    cout << "dequeued node with value:" << Q.dequeue() << endl;
    cout << "dequeued node with value:" << Q.dequeue() << endl;

    return 0;
}