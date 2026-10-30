#include <iostream>

bool leap_year(int year){
    bool ly;

    if (year % 4 != 0){
        ly = 0;
    }
    else if (year % 100 == 0){
        if (year % 400 == 0){
            ly = 1;
        }
        else{
            ly = 0;
        }
    }
    else{
        ly = 1;
    }

    return ly;
}

void next_date(int d1, int m1, int y1, int& d2, int& m2, int& y2){
    
    int numDaysInMonth;

    if (m1 == 2){
        numDaysInMonth = 28 + leap_year(y1);
    }
    else if (m1 == 4 || m1 == 6 || m1 == 9 || m1 == 11)
    {
        numDaysInMonth = 30;
    }
    else{
        numDaysInMonth = 31;
    }
    
    d2 = ((d1) % (numDaysInMonth)) + 1;
    if ((d1+1) > numDaysInMonth){
        m2 = (m1+1) % 12;
    } else {m2 = m1;}
    if (m1 == 12 && d2 == 1){
        y2 = y1+1;
    } else{y2 = y1;}
}

int main(){
    // TODO: write a main to test the function
    int d, m, y, d0, m0, y0;
    std::cin >> d0 >> m0 >> y0;
    next_date(d0, m0, y0, d, m, y);
    std::cout << d << " " << m << " " << y << std::endl;
}