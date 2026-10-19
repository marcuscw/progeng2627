#include <iostream>

int main(){
    unsigned int n, steps, max;
    steps = 0;
    std::cin >> n;
    max = n;

    do{
        std::cout << n << "  ";
        if (n%2 == 0){
            n = n/2;
        }
        else{
            n = 3*n + 1;
        }

        if (n > max){
            max = n;
        }

        steps++;
    }
    while (n != 1);

    std::cout << n << "  steps: " << steps << "  max:  " << max << std::endl;
}