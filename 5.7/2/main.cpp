#include <iostream>

int sumTo(int number)
{
    int result(0);
    for (int count=1; count<=number; ++count)
        result+=count;
    return result;
}

int main()
{
    std::cout << "Type in an integer: ";
    int number;
    std::cin >> number;
    std::cout << "The sum up to this number is " << sumTo(number);
    return 0;
}
