#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

void printVector(const std::vector<double>& vin){
    for (int i = 0; i < vin.size(); i++){
        std::cout << vin[i] << "\t" << std::endl;
    }
}

std::string matToString(const std::vector<std::vector<double>>& m){
    std::stringstream out;
    for (int i = 0; i < m.size(); i++){
        for (int j = 0; j < m[i].size(); j++){
            out << m[i][j] << "\t";
        }
        out << "\n";
    }

    return out.str();
}

std::vector<double> lineToVector(std::string s){
    std::stringstream ss;
    ss << s;
    std::string tmp;
    std::vector<double> out;

    while(ss >> tmp){
        out.push_back(std::stod(tmp));
    }

    return out;
}

std::vector<std::vector<double>> readMatFromFile(std::string inputFile){
    std::ifstream infile;
    infile.open(inputFile);

    if (!infile.is_open()){
        std::cout << "Could not open file " << inputFile << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::string line;
    std::vector<std::vector<double>> out;

    while(std::getline(infile, line)){
        out.push_back(lineToVector(line));
    }

    return out;

}

std::vector<std::vector<double>> matTranspose(const std::vector<std::vector<double>>& m){
    std::vector<std::vector<double>> out;

    for (int j = 0; j < m[0].size(); j++){
        std::stringstream tmp;
        for (int i = 0; i < m.size(); i++){
            tmp << m[i][j] << "\t";
        }

        out.push_back(lineToVector(tmp.str()));
    }

    return out;

}

std::vector<std::vector<double>> matMult(const std::vector<std::vector<double>>& m1, const std::vector<std::vector<double>>& m3){
    std::vector<std::vector<double>> m2 = matTranspose(m3);
    std::vector<std::vector<double>> out;
    for (int i = 0; i < m1.size(); i++){    // iterate through each row of the first matrix
        std::stringstream line;
        for (int j = 0; j < m2.size(); j++){    // iterate through each row of the second matrix
            double sum = 0;
            for (int k = 0; k < m1[i].size(); k++){     // iterate on each element of each row
                sum = sum + (m1[i][k] * m2[j][k]);
            }
            line << sum << "\t";
        }
        out.push_back(lineToVector(line.str()));
    }

    return out;
}

int main(){
    std::cout << matToString(matMult(readMatFromFile("mat1.txt"), readMatFromFile("mat2.txt")));

}