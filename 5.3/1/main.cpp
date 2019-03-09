#include <iostream>

int getInt()
{
    std::cout << "Type in an integer: ";
    int integer;
    std::cin >> integer;
    return integer;
}

char getOperator()
{
    std::cout << "Type in an operator (+,-,*,/,%): ";
    char op;
    std::cin >> op;
    return op;
}

int calculate(int firstInt,int secondInt,char op)
{
    switch(op)
    {
        case '+':
            return firstInt+secondInt;
        case '-':
            return firstInt-secondInt;
        case '*':
            return firstInt*secondInt;
        case '/':
            return firstInt/secondInt;
        case '%':
            return firstInt%secondInt;

        default:
           std::cout << "You did not enter a valid operator. \n";
           return 0;
    }
}

int main()
{
    int firstInt(getInt());
    char op(getOperator());
    int secondInt(getInt());
    std::cout << "The result is " << calculate(firstInt,secondInt,op) << ". \n";
    return 0;
}
