#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
// header fstream needed for working with text files

int main(){
    std::ifstream infile; 

    infile.open("input.txt");

    if (!infile.is_open()){
        std::cout << "File could not be opened" << std::endl;
        return EXIT_FAILURE;
    }

    int tmp;
    int sum = 0;

    while(infile >> tmp){
        std::cout << tmp << std::endl;
        sum = sum + tmp;
    }
    std::cout << sum;

}