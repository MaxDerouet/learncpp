/*
This program converts an integer in the range 0-255 to its binary expression
*/

#include <iostream>
#include "6.h"
#include <cmath>

int getNumber()
{
    std::cout << "Type in an integer between 0 and 255 to convert it to an integer ";
    int number;
    std::cin >> number;
    return number;
}

//
int compareAndPrint(int number, int power)
{
    if (number >= std::pow(2,power))
    {
        std::cout << 1;
        return (number-pow(2,power));
    }
    std::cout << 0;
    return number;
}



int main()
{
    int number(getNumber());
    number=compareAndPrint(number,7); // 128
    number=compareAndPrint(number,6); // 64
    number=compareAndPrint(number,5); // 32
    number=compareAndPrint(number,4); // 16
    std::cout << " ";
    number=compareAndPrint(number,3); // 8
    number=compareAndPrint(number,2); // 4
    number=compareAndPrint(number,1); // 2
    number=compareAndPrint(number,0); // 1
    return 0;
}
