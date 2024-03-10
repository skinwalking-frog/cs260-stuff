#include <iostream>

using namespace std;
class hashmap{
private:
    static const int map_size = 100;
    int array[map_size];

public:
    hashmap(){
        for (int i = 0; i < map_size; i++){
            array[i] = 0;
        }
    }



    size_t hash_func(string key){
        hash<string> hasher;
        size_t index = hasher(key);
        return index; 
    }

};
