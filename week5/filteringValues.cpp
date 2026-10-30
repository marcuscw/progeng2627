#include <iostream>
#include <vector>

int main(){
    std::vector<int> v; 
    int n, t, tmp;

    std::cout << "Enter the number of elements in your vector: ";
    std::cin >> n;

    for (int i = 0; i < n; i++){
        std::cout << "Enter element " << i <<": ";
        std::cin >> tmp;
        v.push_back(tmp);
    }

    std::cout << "Enter the upper bound of the values you want from your vector: ";
    std::cin >> t;

    for (int i = 0; i < n; i++){
        if (v[i] < t){
        std::cout << v[i] << ", which is v[" << i << "]" << std::endl;
        }
    }

}