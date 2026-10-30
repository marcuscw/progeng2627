#include <iostream>

double mypow(double base, int exp){
    double result = base;

    if (exp < 0){
        for (int i = 1; i < -exp; i++ ){
        result = result * base;
        }
    return 1/result;
    }
    else{
        for (int i = 1; i < exp; i++ ){     
        result = result * base;
        }
    return result;
    }

    // at the end we return the value we computed
    // we *do not print* anything in the function
}

int main(){
    // we test examples with integer (and non-negative) exponent

    std::cout << mypow(2, -3) << std::endl;

    // std::cout << "2^-3: " << mypow(2, -3) << std::endl;
    // std::cout << "0.5^2: " << mypow(0.5, 2) << std::endl;
    // std::cout << "1^0: " << mypow(1, 0) << std::endl;
}
