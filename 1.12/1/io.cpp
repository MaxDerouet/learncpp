#include <iostream>

int readNumber()
{
    std::cout << "Type in a number" << std::endl;
    int number;
    std::cin >> number;
    return number;
}

void writeAnswer(int answer)
{
    std::cout << "The result of adding the two numbers is " << std::endl;
    std::cout << answer << std::endl;
}
