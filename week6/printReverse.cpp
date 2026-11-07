#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include<string>

int main(){
    std::ifstream intext;
    intext.open("input.txt");

    if (!intext.is_open()){
        std::cout << "Could not open file" << std::endl;
        return EXIT_FAILURE;
    }

    std::string tmp;
    std::vector<std::string> content;

    while (intext >> tmp){
        content.push_back(tmp);
    }

    intext.close();

    for (int i = content.size() - 1; i >= 0; i--){
        std::cout << content[i] << std::endl;
    }
}