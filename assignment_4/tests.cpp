#include "helper.hpp"
#include <iostream>

using std::cout;

//most of these are not completely thorough tests because I'm not sure how I'm supposed 
//to test a destructor method.

//figured it would be easier to report if something failed than if everything passed.
int testnode(){
    int result = 0;
    Node* node_A = new Node(5);
    if(node_A->data != 5 || node_A->index != -1 || node_A->next != nullptr || node_A->last != nullptr){
        result = 1;
    };
    return result;
};

int testlist(){
    int result = 0;

    List* list = new List;

    if(list->length != 0 || list->start != nullptr || list->end != nullptr){
        result = 1;
    };
    list->AddAtPos(0, 1);
    if(list->length != 1 || list->start != nullptr || list->end != nullptr){
        result = 2;
    };
    

    return result;
}
