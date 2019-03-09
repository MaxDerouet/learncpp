#include <iostream>

bool isPrime(int x);

bool isPrime(int x)
{
    if (x==2)
    {
        return true;
    }
    if (x==3)
    {
        return true;
    }
    if (x==5)
    {
        return true;
    }
    if (x==7)
    {
        return true;
    }
    return false;
}


int main()
{
    std::cout << "Enter a single digit integer" << std::endl;
    int x;
    std::cin >> x;
    if (isPrime(x))
    {
        std::cout << "Digit " << x << " is prime" << std::endl;
    }
    else
    {
        std::cout << "Digit " << x << " is not prime" << std::endl;
    }

}
