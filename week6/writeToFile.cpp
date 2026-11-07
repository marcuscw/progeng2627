#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

int main(){

    std::ofstream outfile;
    std::ifstream infile;
    
    std::string infileName;
    std::string outfileName;

    std::cout << "Please enter the name of your input file: ";
    std::cin >> infileName;
    std::cout << "Now enter the name of your output file: ";
    std::cin >> outfileName;

    infile.open(infileName);
    outfile.open(outfileName);

    if (!outfile.is_open()){
        std::cout << "Output File could not be opened";
        return EXIT_FAILURE;
    }
    else if (!infile.is_open()){
        std::cout << "Input File could not be opened";
        return EXIT_FAILURE;
    }



    std::string tmp;
    std::vector<std::string> v;

    while (infile >> tmp){
        v.push_back(tmp);
    }

    for (int i = 0; i < v.size(); i++){
        outfile << v[v.size() - i - 1] << std::endl;
    }
}