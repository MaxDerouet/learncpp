#include <iostream>

void printBinary(int number)
{
    if (number==0)
    {
        return;
    }
    else
    {
        printBinary(number/2);
        std::cout << (number%2);
    }
}

int main()
{
    printBinary(13);
    return 0;
}
