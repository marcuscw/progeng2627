#include <iostream>

void intDiv(int a, int b, int &result, int &remainder){
    result = a/b;
    remainder = a%b;
}

int main(){
    int result, remainder;
    int a, b;
    std::cout << "Enter your division a/b as {a b}" << std::endl;
    std::cin >> a >> b;
    intDiv(a, b, result, remainder);
    std::cout << "Result: " << result << "  Remainder: " << remainder << std::endl;
}