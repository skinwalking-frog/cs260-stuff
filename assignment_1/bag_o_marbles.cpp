#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;

#define bagsize 10

int rand_num(int, int);

int main() {
    srand(time(0));

    int running = 1;
    int bag[bagsize] = {0};

    while(running == 1){
        cout << "menu: \n"
                "1: add marble to top of bag\n"
                "2: remove marble from top of bag\n"
                "3: check status of bag\n"
                "any unlisted key: exit\n";

        std::string input;
        cin >> input;

        if(input == "1"){
            for(int i = 0; i < bagsize; i++){
                if(bag[i] == 0){
                    cout << "space found, inserting marble\n";
                    bag[i] = rand_num(1,9);
                    break;
                }
                if(i == 9){
                    cout << "bag already full\n";
                }
            }
        }else if(input == "2"){
            for(int i = bagsize - 1; i > -1; i--){
                if(bag[i] != 0){
                    bag[i] = 0;
                    cout << "removing marble\n";
                    break;
                }
                if(i == 0){
                    cout << "bag already empty";
                }
            }
        }else if(input == "3"){
            cout << "bag contents\n";

            for(int i = 0; i < bagsize; i++){
                cout << i << ": " << bag[i] << '\n';
            }
        }else{
            cout << "exiting";
            running = 0;
        }
    }
    return 0;
}

int rand_num(int min, int max){
    return rand() % (max - min + 1) + min;
}