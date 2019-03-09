#include <iostream>

struct Fraction
{
    int nominator;
    int denominator;
};

double multiply(Fraction first, Fraction second)
{
    return ((static_cast<double>(first.nominator)*second.nominator)/(first.denominator*second.denominator));
}

int main()
{
    int firstNominator;
    std::cout << "Type in the nominator for the first fraction: ";
    std::cin >> firstNominator;
    int firstDenominator;
    std::cout << "Type in the denominator for the first fraction: ";
    std::cin >> firstDenominator;
    Fraction first{firstNominator,firstDenominator};
    int secondNominator;
    std::cout << "Type in the nominator for the second fraction: ";
    std::cin >> secondNominator;
    int secondDenominator;
    std::cout << "Type in the denominator for the second fraction: ";
    std::cin >> secondDenominator;
    Fraction second{secondNominator,secondDenominator};
    std::cout << "Mulitplying your two fraction yields " << multiply(first, second) << "\n";
    return 0;
}
