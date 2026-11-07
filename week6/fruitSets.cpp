#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

int search_vector(std::string s, const std::vector<std::string>& vin){
    for (int i = 0; i < vin.size(); i++){
        if (vin[i] == s){
            return i;
        }
    }
    return -1;
}

void union_vector(const std::vector<std::string>& vin1, const std::vector<std::string>& vin2, std::vector<std::string>& vout){
    vout = vin1;
    for (int i = 0; i < vin2.size(); i++){
        if (search_vector(vin2[i], vout) == -1){
            vout.push_back(vin2[i]);
        }
    }
}

void intersection_vector(const std::vector<std::string>& vin1, const std::vector<std::string>& vin2, std::vector<std::string>& vout){
    if (vin1.size() > vin2.size()){
        for (int i = 0; i < vin1.size(); i++){
            int index = search_vector(vin1[i], vin2);
            if (index == -1){
                continue;
            }
            vout.push_back(vin1[i]);
        }
    }
    else {
        for (int i = 0; i < vin2.size(); i++){
            int index = search_vector(vin2[i], vin1);
            if (index == -1){
                continue;
            }
            vout.push_back(vin2[i]);
        }
    }
}


int main(){
    std::ifstream fileW1, fileW2;
    std::ofstream fileIntersect, fileUnion;

    fileW1.open("warehouse1.txt");
    fileW2.open("warehouse2.txt");
    fileIntersect.open("intersection.txt");
    fileUnion.open("union.txt");

    if (!fileW1.is_open()){
        std::cout << "Could not open file warehouse1";
        return EXIT_FAILURE;
    }
    else if (!fileW2.is_open()){
        std::cout << "Could not open file warehouse2";
        return EXIT_FAILURE;
    }
    else if (!fileIntersect.is_open()){
        std::cout << "Could not open file intersection";
        return EXIT_FAILURE;
    }
    else if (!fileUnion.is_open()){
        std::cout << "Could not open file union";
        return EXIT_FAILURE;
    }

    std::string tmp;
    std::vector<std::string> v_w1, v_w2, v_intersect, v_union;

    while(fileW1 >> tmp){
        v_w1.push_back(tmp);
    }
    while(fileW2 >> tmp){
        v_w2.push_back(tmp);
    }

    union_vector(v_w1, v_w2, v_union);
    intersection_vector(v_w1, v_w2, v_intersect);

    for (int i = 0; i < v_union.size(); i++){
        std::cout << i << " ";
        fileUnion << v_union[i] << std::endl;
    }
    for (int i = 0; i < v_intersect.size(); i++){
        std::cout << i << " ";
        fileIntersect << v_intersect[i] << std::endl;
    }
}