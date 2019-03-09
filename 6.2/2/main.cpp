#include <iostream>

namespace Animals
{
    enum Animals
    {
        CHICKEN,
        DOG,
        CAT,
        ELEPHANT,
        DUCK,
        SNAKE,
        MAX_ANIMALS,
    };
}

int main()
{
    int noLegs[Animals::MAX_ANIMALS]={2,4,4,4,2,0};
    std::cout << "An elphant has " << noLegs[Animals::ELEPHANT] << " legs. \n";
    return 0;
}
