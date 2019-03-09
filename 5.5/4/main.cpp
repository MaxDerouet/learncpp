#include <iostream>

void printNumbers()
{
    int outer(1);
    while (outer<=5)
    {
        int inner(5);
        while (inner>=1)
        {
            if (inner<=outer)
                std::cout << inner << " ";
            else
                std::cout << "  ";
            --inner;
        }
        std::cout << "\n";
        ++outer;
    }
}

int main()
{
    printNumbers();
    return 0;
}
