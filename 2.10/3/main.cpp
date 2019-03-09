#include <iostream>
# include "3.h"

/*
This progrqam takes two floating point numbers and an operator (+,-,*,/) as a input and calculates the result
*/

int getCalcOperator()
{
    std::cout << "Type in a number to choose an operator (1=+,2=-,3=*,4=/) \n";
    int calcOperator;
    std::cin >> calcOperator;
    return calcOperator;
}

double getOperand()
{
    std::cout << "Type in an operand \n";
    double operand;
    std::cin >> operand;
    return operand;
}

double calculate(const double firstOperand, const int calcOperator, const double secondOperand)
{
    if (calcOperator==1)
    {
        return firstOperand + secondOperand;
    }
    else if (calcOperator==2)
    {
        return firstOperand - secondOperand;
    }
    else if (calcOperator==3)
    {
        return firstOperand * secondOperand;
    }
    else if (calcOperator==4)
    {
        return firstOperand / secondOperand;
    }
}

bool validateOperator(int calcOperator) //figures outif user input was vali
{
    if (calcOperator==1)
        return true;
    else if (calcOperator==2)
        return true;
    else if (calcOperator==3)
        return true;
    else if (calcOperator==4)
        return true;
    return false;
}

int main()
{
    double firstOperand(getOperand());
    int calcOperator(getCalcOperator());
    if (validateOperator(calcOperator))
    {
        double secondOperand(getOperand());
        double calculationResult(calculate(firstOperand,calcOperator,secondOperand));
        std::cout << "The result of the calculation is " << calculationResult;
    }

    return 0;
}
