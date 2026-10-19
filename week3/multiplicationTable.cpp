#include <iostream>

int main(){
    int size;
    std::cin >> size;

    for (int i = 1; i <= size; i++){
        for (int j = i; j <= i*size; j = j + i){
            std::cout << j << "\t";
        }
        std::cout << std::endl;
    }
}