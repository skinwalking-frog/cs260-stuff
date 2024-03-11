#include <iostream>

using namespace std;

class hashmap{
private:
    static const int map_size = 30;
    int array[map_size];

    size_t hash_func(string key);

public:
    hashmap();

    void insert(string key, int value);

    int get(string key);

    void debug_array();
};
