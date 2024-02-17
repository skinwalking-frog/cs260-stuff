#include "helper.hpp"
#include <iostream>

using std::cout;

//most of these are not completely thorough tests because I'm not sure how I'm supposed 
//to test a destructor method.

//figured it would be easier to report if something failed than if everything passed.
int TestNode(){
    int result = 0;
    Node* node_A = new Node(5);
    if(node_A->data != 5 || node_A->index != -1 || node_A->next != nullptr || node_A->last != nullptr){
        result = 1;
    };
    return result;
};

bool TestListAdd(int test_list_len, int test_in_data, int test_in_pos) {
    List* test_list = new List;

    test_list->AddAtPos(test_in_pos, test_in_data);
    
}
