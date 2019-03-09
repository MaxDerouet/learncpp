#include <iostream>
#include <string>



int main()
{
    std::cout << "Enter your full name: ";
    std::string name;
    std::getline(std::cin, name);
    std::cout << "Enter your age: ";
    int age;
    std::cin >> age;
    double average(static_cast<double>(name.length())/age);
    std::cout << "You've lived " << average << " years for each letter in your name.";
    return 0;
}
