#include <iostream>
#include <fstream>
#include <vector>

// argc is the number of command line arguments
// argv is an array of C-style strings
// we'll see what this means more in detail later on

int main(int argc, char* argv[]){


    std::fstream textIn;
    textIn.open(argv[1]);

    if (!textIn.is_open()){
        std::cout << "Could not open text file: ";
        std::cout << argv[1];
        return 1;
    }

    std::string tmp;
    std::vector<std::string> content;

    while (textIn >> tmp){
        content.push_back(tmp);
    }

    for (int i = 0; i < content.size(); i++){
        std::cout << content[i] << std::endl;
    }

}