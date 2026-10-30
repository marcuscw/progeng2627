#include <iostream>
#include <vector>

int min_vector_element(const std::vector<double>& vin){
    if (vin.size() == 0){
        return -1;
    }

    double min = vin[0];
    int minIndex = 0;

    for (int i = 1; i < vin.size(); i++){
        if (vin[i] < min){
            min = vin[i];
            minIndex = i;
        }
    }

    return minIndex;
}

int main(){
    std::vector<double> v = {};

    std::cout << min_vector_element(v) << std::endl;
}