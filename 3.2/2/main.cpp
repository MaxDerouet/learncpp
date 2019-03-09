/*
Get a number from the user and decide if it is even or not
*/

#include <iostream>
#include "2.h"

int getNumber()
{
    std::cout << "Type in a number ";
    int number;
    std::cin >> number;
    return number;
}

bool isEven(int number)
{
    return ((number%2)==0);
}

int main()
{
    int number(getNumber());
    bool expr(isEven(number));
    if (expr)
        std::cout << "Number " << number << " is even \n";
    else
       std::cout << "Number " << number << " is not even \n";
    return 0;
}
