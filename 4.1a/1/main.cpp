#include <iostream>


int main()
{
    std::cout << "Enter an integer: ";
    int numberUser;
    std::cin >> numberUser;
    std::cout << "\n Enter a larger integer: ";
    int largerNumberUser;
    std::cin >> largerNumberUser;
    { // if blouck would have been sufficient for this quiz, which was not clear from the formulation
        int number;
        int largerNumber;
        if (numberUser > largerNumberUser)
        {
            std::cout << "Swapping the values\n";
            number=largerNumberUser;
            largerNumber=numberUser;
        }
        else
        {
            number=numberUser;
            largerNumber=largerNumberUser;
        }
        numberUser=number;
        largerNumberUser=largerNumber;
    }
    // numer and largerNumber die here
    std::cout << "The smaller value is " << numberUser << "\n";
    std::cout << "The larger value is " << largerNumberUser << "\n";
    return 0;
}
// numberUser and largerNumberUser die here
