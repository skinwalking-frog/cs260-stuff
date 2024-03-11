#include <iostream>
#include "hashmap.hpp"

using namespace std;



int main(){
    hashmap* table = new hashmap;
    string bob = "bob";
    string joe = "joe";
    string phill = "phill";
    string nick = "nick";
    string james = "james";

    table->insert(bob, 1);
    table->insert(joe, 2);
    table->insert(phill, 3);
    table->insert(nick, 4);
    table->insert(james, 5);

    cout << table->get("bob") << " is the value of bob\n";

    table->debug_array();
    return 0;
}
