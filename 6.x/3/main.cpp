#include <iostream>

void mySwap(int &firstValue, int &secondValue)
{
    int temp(firstValue);
    firstValue=secondValue;
    secondValue=temp;
}

int main()
{
    int firstValue(5);
    int secondValue(6);
    mySwap(firstValue, secondValue);
    std::cout << firstValue << "\n";
    std::cout << secondValue << "\n";
    return 0;
}
