#include <iostream>
#include <string>

enum class Animal
{
    PIG,
    CHICKEN,
    GOAT,
    CAT,
    DOG,
    OSTRICH,
};

std::string getAnimalName(Animal animal)
{
    switch (animal)
    {
        case Animal::PIG:
            return "Pig";
        case Animal::CHICKEN:
            return "Chicken";
        case Animal::GOAT:
            return "Goat";
        case Animal::CAT:
            return "Cat";
        case Animal::DOG:
            return "Dog";
        case Animal::OSTRICH:
            return "Ostrich";
        default:
            std::cout << "???";
            return "Unknown";
    }
}

void printNumberOfLegs(Animal animal)
{
    std::cout << "A " << getAnimalName(animal) << " has ";
    switch (animal)
    {
        case Animal::PIG:
        case Animal::GOAT:
        case Animal::CAT:
        case Animal::DOG:
            std::cout << "4";
            break;
        case Animal::CHICKEN:
        case Animal::OSTRICH:
            std::cout << "2";
            break;
        default:
            std::cout << "???";
            break;
    }
    std::cout << " legs. \n";
}

int main()
{
    Animal cat(Animal::CAT);
    printNumberOfLegs(cat);;
    Animal chicken(Animal::CHICKEN);;
    printNumberOfLegs(chicken);

    return 0;
}
