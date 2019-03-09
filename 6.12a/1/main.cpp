#include <iostream>
#include <string.h>

int main()
{
    std::string names[]={"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};
    std::cout << "Type in a name: ";
    std::string name;
    std::cin >> name;
    bool nameFound(false);
    for (const auto &currentName : names)
    {
        if (currentName == name)
            nameFound=true;
    }
    if (nameFound)
        std::cout << name << " was found.\n";
    else
        std::cout << name << " was not found.\n";
    return 0;
}
