#include <iostream>
#include "hashmap.hpp"

using namespace std;

size_t hashmap::hash_func(string key){
    hash<string> hasher;
    size_t index = hasher(key) % map_size;
    return index; 
}

hashmap::hashmap(){
    for (int i = 0; i < map_size; i++){
        array[i] = 0;
    }
}

void hashmap::insert(string key, int value){
    array[hash_func(key)] = value;
}

int hashmap::get(string key){
    return array[hash_func(key)];
}

void hashmap::debug_array(){
    for (int i = 0; i < map_size; i++){
    cout << array[i] << endl;
    }
}