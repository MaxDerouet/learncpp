#include <iostream>

void printBinary(unsigned int posNumber)
{
    if (posNumber==0)
    {
        return;
    }
    else
    {
        printBinary(posNumber/2);
        std::cout << (posNumber%2);
    }
}

int main()
{
    printBinary(-15);
    return 0;
}
