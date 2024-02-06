#include <iostream>
#include "linked_queue_classes.hpp"

using std::cout;

//!!!may need to omit lines before this for multi-file compilation!!!

//still not sure on how the compiler links these files 

//not a great testing file because it doesnt tell u what exactly went wrong, but does tell u it went wrong.

Node node_A = Node(0);
if(node_A.data == 0 && node_A.next == nullptr && node_A.previous == nullptr){
    cout << "node_A created successfully";
}else{
    cout << "node_A failed to create successfully";
    return 1;
};
Node node_B = Node(1);
if(node_B.data == 1 && node_B.next == nullptr && node_B.previous == nullptr){
    cout << "node_B created successfully";
}else{
    cout << "node_B failed to create successfully";
    return 2;
};

Queue Q;
if(Q.head == nullptr && Q.tail == nullptr && Q.length == 0){
    cout << "Queue created successfully";
}else{
    cout << "Queue failed to create successfully";
    return 3;
};

int ret1 = Q.enqueue(&node_A);
if(Q.length == 1 && Q.head == &node_A && Q.tail == &node_A){
    cout << "enqueued node_A succesfully, data of node_A = " << ret1;
}else{
    cout << "failed to enqueue node_A";
    return 4;
};

int ret2 = Q.enqueue(&node_B);
if(Q.length == 2 && Q.head == &node_A && Q.tail == &node_B){
    cout << "enqueued node_B succesfully, data of node_B = " << ret2;
}else{
    cout << "failed to enqueue node_B";
    return 5;
};

Q.dequeue();
if(Q.length == 1 && Q.head == &node_B && Q.tail == &node_B)
{
    cout << "dequeued head node successfully";
}else{
    cout << "failed to dequeue head node";
    return 6;
};

