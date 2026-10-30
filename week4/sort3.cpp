#include <iostream>


void sort_two_numbers(double& s1, double& s2){
    double temp;
    if (s2 < s1){
        temp = s2;
    }
    else{
        return;
    }
    s2 = s1;
    s1 = temp;
}


void sort_three_numbers(double& s1, double& s2, double& s3){
    sort_two_numbers(s1, s2);
    sort_two_numbers(s2, s3);
}

int main(){
    double n1, n2, n3;
    std::cout << "please enter three numbers:" << std::endl;
    std::cin >> n1 >> n2 >> n3;
    sort_three_numbers(n1, n2, n3);
    std::cout << n1 << " " << n2 << " " << n3 << std::endl;
}
