#include <iostream>

int digitSum(int number)
{
    int lastDigit=number%10;
    if (lastDigit==number)
        return number;
    else
        return (lastDigit+digitSum((number-lastDigit)/10));
}

int main()
{
    std::cout << digitSum(93427);
    return 0;
}
