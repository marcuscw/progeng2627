#include <iostream>

int main(){
    int num, n;
    std::cout << "Factorial Calculator. Enter your number" << std::endl;
    std::cin >> num;

    n = num;

    for (int i = 1; i < num; i++){
        n = n*i;
    }
    std::cout << num << "! = " << n;
}