#include <iostream>

void printNumbers()
{
    int outer(5);
    while (outer>=1)
    {
        int inner(outer);
        while (inner>=1)
        {
            std::cout << inner-- << " ";
        }
        std::cout << "\n";
        --outer;
    }
}

int main()
{
    printNumbers();
    return 0;
}
