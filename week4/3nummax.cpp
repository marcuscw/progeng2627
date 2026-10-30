#include <iostream>

double numnax(double A, double B, double C){
    double big = B;

    if (A > B){
        big = A;
    }
    if (C > big){
        big = C;
    }

    return big;
}

int main(){
    std::cout << numnax(5, 99, -2) << std::endl;
}