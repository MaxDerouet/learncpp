#include <iostream>

class Fraction
{
    int m_nominator=0;
    int m_denominator=1;
public:
    Fraction(int nominator=0, int denominator=1):m_nominator(nominator), m_denominator(denominator)
    {
    }
    friend Fraction operator*(const Fraction &firstFraction, const Fraction &secondFraction);
    friend Fraction operator*(int value, const Fraction &fraction);
    friend Fraction operator*(const Fraction &fraction, int value);
    void reduce();
    void print();
    static int gcd(int a, int b)
    {
        return (b == 0) ? (a > 0 ? a : -a) : gcd(b, a % b);
    }
};

Fraction operator*(const Fraction &firstFraction, const Fraction &secondFraction)
{
    Fraction fraction((firstFraction.m_nominator*secondFraction.m_nominator),(firstFraction.m_denominator*secondFraction.m_denominator));
    fraction.reduce();
    return fraction;
}

Fraction operator*(int value, const Fraction &fraction)
{
    Fraction temp((value*fraction.m_nominator),fraction.m_denominator);
    temp.reduce();
    return temp;
}

Fraction operator*(const Fraction &fraction, int value)
{
    Fraction temp(value*fraction);
    temp.reduce();
    return temp;
}

void Fraction::reduce()
{
    int greatestCommonDivisor(Fraction::gcd(m_nominator,m_denominator));
    m_nominator/=greatestCommonDivisor;
    m_denominator/=greatestCommonDivisor;
}

void Fraction::print()
{
    std::cout << m_nominator << "/" << m_denominator << "\n";
}

int main()
{
    Fraction f1(2, 5);
    f1.print();

    Fraction f2(3, 8);
    f2.print();

    Fraction f3 = f1 * f2;
    f3.print();

    Fraction f4 = f1 * 2;
    f4.print();

    Fraction f5 = 2 * f2;
    f5.print();

    Fraction f6 = Fraction(1, 2) * Fraction(2, 3) * Fraction(3, 4);
    f6.print();
}
