#include <iostream>

int main(){
    int n, max, min;

    std::cin >> n;

    min = n;
    max = n;

    std::cout << "The current max is: " << max << ", and the current min is: " << min << std::endl;

    while (n){
        std::cin >> n;
        
        if (n > max){
            max = n;
        }
        else if (n < min){
            min = n;
        }

        std::cout << "The current max is: " << max << ", and the current min is: " << min << std::endl;
    }
}