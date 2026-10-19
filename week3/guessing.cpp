#include <iostream>
#include <string>

int main(){
    int min, max, guess;
    std::string userIn;

    std::cout << "Enter your inclusive bounds {min max}: " << std::endl;
    std::cin >> min >> max;

    while (1){

    guess = (min + max) / 2;
    std::cout << "Is your number " << guess << "? {yes, higher, lower}" << std::endl;
    std::cin >> userIn;

    if (userIn == "yes"){
        std::cout << "Ahh, I knew it all along." << std::endl;
        break;
    }
    else if (userIn == "higher"){
        min = guess;
    }
    else if (userIn == "lower"){
        max = guess;
    }
    else{
        std::cout << "Sorry, I didn't quite catch that." << std::endl;
    }
    }

}