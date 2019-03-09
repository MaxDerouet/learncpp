#include <iostream>
#include <array>

int getInteger();
char getOperator();
int add(int fristNumber, int secondNumber);
int subtract(int fristNumber, int secondNumber);
int multiply(int fristNumber, int secondNumber);
int divide(int fristNumber, int secondNumber);
typedef int (*arithmeticFcn)(int,int);
//using arithmeticFcn=int(*)(int,int);
arithmeticFcn getArithmeticFunction(char op, int quiz=1);
struct arithmeticStruct;


int getInteger()
{
    while (true)
    {
        std::cout << "Type in an integer ";
        int number;
        std::cin >> number;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(333,'\n');
        }
        else
        {
            std::cin.ignore(333,'\n');
            return number;
        }
    }
}

char getOperator()
{
    while (true)
    {
        std::cout << "Which operation should be performed (+,-,*,/) ";
        char op;
        std::cin >> op;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(333,'\n');
        }
        else
        {
            std::cin.ignore(333,'\n');
            if (op=='+' || op=='-' || op=='*'|| op=='/')
                return op;
        }
    }
}

int add(int firstNumber, int secondNumber)
{
    return (firstNumber+secondNumber);
}

int subtract(int firstNumber, int secondNumber)
{
    return (firstNumber-secondNumber);
}

int multiply(int firstNumber, int secondNumber)
{
    return (firstNumber*secondNumber);
}

int divide(int firstNumber, int secondNumber)
{
    if (secondNumber!=0)
        return (firstNumber/secondNumber);
    else
    {
        std::cout << "You can't divide by zero \n";
        return 0;
    }
}



struct arithmeticStruct
{
    char op;
    arithmeticFcn fcnPtr;
};

static const std::array<arithmeticStruct,4> arithmeticArray{{{'+',add},{'-',subtract},{'*',multiply},{'/',divide}}};

arithmeticFcn getArithmeticFunction(char op, int quiz)
{
    switch (quiz)
    {
        default:
        case 1:
        switch(op)
        {
            case('+'): return add;
            case('-'): return subtract;
            case('*'): return multiply;
            case('/'): return divide;
            default:
            {
                std::cout << "A valid operator was not provided \n";
                return add;
            }
        }
        case 2:
        {
            for (const auto &element : arithmeticArray)
            {
                if (element.op==op)
                {
                    return element.fcnPtr;
                }
            }
            return add;
        }
    }
}

int main()
{
    std::cout << "Which quiz do you want to test? ";
    int quiz;
    std::cin >> quiz;
    int firstNumber(getInteger());
    char op(getOperator());
    int secondNumber(getInteger());
    arithmeticFcn fcnPtr;
    switch (quiz)
    {
        default:
        case 1:
        fcnPtr=getArithmeticFunction(op);
        break;
        case 2:
        fcnPtr=getArithmeticFunction(op,2);
        break;
    }
    std::cout << "The result is of your calculation in quiz " << quiz << " is " << fcnPtr(firstNumber, secondNumber);
    return 0;
}
