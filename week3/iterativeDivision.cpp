#include <iostream>
#include <string>

int main(){
    int num, denom, counter;
    counter = 0;
    std::string foo;
    std::cin >> num >> foo >> denom;
    
    while (num >= denom){
        counter = counter + 1;
        num = num - denom;

    }

    std::cout << counter << " remainder " << num << std::endl;
}