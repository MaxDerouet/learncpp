#include <iostream>

// thís program doubles a user input
int doubleNumber(int x)
{
    return 2*x;
}
int main()
{
    std::cout << "Type in a number,so we can double it" << std::endl;
    int x;
    std::cin >> x;
    std::cout << "The doubled number is:" << std::endl;
    std::cout << doubleNumber(x) << std::endl;
    return 0;
}
