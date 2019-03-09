#include <iostream>

namespace ItemTypes{
    enum ItemTypes
    {
        HEALTH_PORTION,
        TORCH,
        ARROW,
        MAX_ITEMS
    };
}

int countTotalItems(int *itemsArray)
{
    int sumItems(0);
    for (int index=0; index < ItemTypes::MAX_ITEMS; ++index)
        sumItems+=itemsArray[index];
    return sumItems;
}

int main()
{
    int itemsArray[ItemTypes::MAX_ITEMS]{2,5,10};
    std::cout << "You carry " << countTotalItems(itemsArray) << " items.\n";
    return 0;
}
