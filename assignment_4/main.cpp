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
    }else if(pos > length){
        //length is absolute, pos is zero-indexed. if length == pos there is no problem.
        pos = length;
    };

    Node* newnode = new Node(data);
    
    //if list is empty, overide user defined index to 0.
    if(start == nullptr){
        newnode->index = 0;
        start = newnode;
        end = newnode;
        length++;
    //else if desired pos == length of list, we are only appending to end of List.
    }else if(pos == length){
            newnode->index = pos;
            end->next = newnode;
            newnode->last = end;
            end = newnode;
            length++;
    //else if we are just adding to the front
    }else if(pos == 0){
        //adjust all indices by +1
        Node* current = start;
        bool reached = false;
        while(reached == false){
            if(current == end){
                reached = true;
                current->index++;
            }else{  
                current->index++;
                current = current->next;
            };
        };
        newnode->index = pos;
        newnode->next = start;
        start->last = newnode;
        start = newnode;
        length++;
    //otherwise proceed with general solution    
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

//removes node at index and deletes it
int List::RemoveAtPos(int pos){
    int Data = 0;
    //if index is not valid, output message 
    if(pos < 0 || pos >= length){
        cout << "not a valid index ";
    //else if there is only one item left in list/start and end are the same
    }else if(length == 1){
        Data = start->data;
        Node* ToDel = start;
        start = nullptr;
        end = nullptr;
        delete ToDel;
        length--;
    //else if we only want to remove node from end of list
    }else if(pos == length - 1){
        Data = end->data;
        Node* ToDel = end;
        end = end->last;
        end->next = nullptr;
        ToDel->last = nullptr;
        delete ToDel;
        length--;
    //otherwise general solution will work
    }else{
        Node* current = start;
        bool finished = false;
        while(finished == false){
            if(current->index == pos){
                Data = current->data;
                //if we are trying to remove start/first element
                if(current->last == nullptr){
                    current->next->last = nullptr;
                    start = current->next;
                }else{
                    current->last->next = current->next;
                    current->next->last = current->last;
                }
                length--;
                Node* ToDel = current;
                current = current->next;
                delete ToDel;
            }else if(current == end){
                current->index--;
                finished = true;
            }else if(current->index > pos){
                current->index--;
                current = current->next;
            }else{
                current = current->next;
            };
        };
    };
    return Data;
};

//return value of data property from node at index without deleting node
int List::LookAtPos(int pos){
    int value;
    if(pos < 0 || pos >= length){
    cout << "not a valid index ";
    value = 0;
    //if index in second half, search backwards from end
    }else if(pos - 1 < length/2){
        Node* current = end;
        bool found = false;
        while(found == false){
            if(current->index == pos){
                value = current->data;
                found = true;
            }else{
                current = current->last;
            };
        };
    //otherwise if index is in first half, search from start
    }else{
        Node* current = start;
        bool found = false;
        while(found == false){
            if(current->index == pos){
                value = current->data;
                found = true;
            }else{
                current = current->next;    
            };
        };
    };
    return value;
};

void List::printlist(){
    if(length > 0){
        Node* current = start;
        bool done = false;
        cout << "List length: " << length << endl << "---------------" << endl;
        while(done == false){
            cout << "node index: " << current->index << endl << "node data: " 
            << current->data << endl << "---------------" << endl;            
            if(current == end){
                done = true;
            }else{
                current = current->next;
            };
            
        };
    }else{
        cout << "list is empty\n";
    };
};

List::~List(){
    for(int i = length; i > 0; i--){
        RemoveAtPos(i - 1);
    }
};

int main(){
    List* list_A = new List;

    //not really a test, more of a pseudo test to demonstrate that main can execute without error
    cout << "attempting to add node at index 0 with data 2\n";
    list_A->AddAtPos(0, 2);
    cout << "attempting to add node at index -1 with data 1\n"; //should add it infront of previous node, at corrected index 0
    list_A->AddAtPos(-1, 1);
    cout << "attempting to add node at index 5 with data 3\n";//shoukd add node to end of list with corrected index of 2.
    list_A->AddAtPos(5, 3);

    cout << "current list status:\n";
    list_A->printlist();

    cout << "data at index 0: " << list_A->LookAtPos(0) << endl;
    cout << "data at index 1: " << list_A->LookAtPos(1) << endl;
    cout << "data at index 2: " << list_A->LookAtPos(2) << endl;
    cout << "data at index 3: " << list_A->LookAtPos(3) << endl; //should return invalid index
    cout << "data from attempted node removal at index 3: " << list_A->RemoveAtPos(3) << endl; //should return invalid index
    cout << "data from attempted node removal at index 2: " <<list_A->RemoveAtPos(2) << endl; 
    cout << "data from attempted node removal at index 0: " <<list_A->RemoveAtPos(0) << endl;
    cout << "data from attempted node removal at index 0: " <<list_A->RemoveAtPos(0) << endl;

    cout << "current list status:\n";
    list_A->printlist();
    
    delete list_A;

    return 0;
};
