#include <iostream>

bool isPrime(int n){
    if (n == 1){
        return 0;
    }
    if (n==2){
        return 1;
    }
    for (int i = 2; i < n; i++){
        if (n%i == 0){
            return 0;
        }
    }

    return 1;
}

int smallestFactor (int n){
        for(int cf = 2; cf < n-1; cf++){

        if( (n % cf) == 0){ // n can be divided by cf...
            if (isPrime(cf)){
                return cf;
            }
        }
    }
    return 0;
}

void primesInRange(int a, int b){   // b > a
    for (int i = a+1; i < b; i++){
        if (isPrime(i)){
            std::cout << i << std::endl;
        }
    }
}


int main(){
    int a, b;
    std::cin >> a >> b;
    primesInRange(a, b);
}