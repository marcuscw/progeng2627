#include <iostream>
#include <vector>

void append_vectors(const std::vector<int>& vin1, const std::vector<int>& vin2, std::vector<int>& vout){
    for (int i = 0; i < vin1.size(); i++){
        vout.push_back(vin1[i]);
    }
    for (int i = 0; i < vin2.size(); i++){
        vout.push_back(vin2[i]);
    }
}

int main(){
    std::vector<int> vin1 = {4, 6, 1, -1};
    std::vector<int> vin2 = {-1, 5, -4, 6, 7};
    std::vector<int> vout;

    append_vectors(vin1, vin2, vout);
    for (int i = 0; i < vout.size(); i++){
        std::cout << vout[i] << " ";
    }
}