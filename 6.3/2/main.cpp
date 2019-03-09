#include <iostream>

int getUserInput()
{
    while(true)
    {
        std::cout << "Type in a number between 1 and 9 ";
        int number;
        std::cin >> number;
        if (std::cin.fail())
        {
            std::cin.clear(); // reset any error flags
            std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer
        }
        else
        {
            std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer
            if (1<=number && number<=9)
                return number;
        }
    }
}

int main()
{
    int array[] = { 4, 6, 7, 3, 8, 2, 1, 9, 5 };
    const int arrayLength=sizeof(array)/sizeof(array[0]);
    int number(getUserInput());
    int indexOfNumber;
    for (int index=0; index < arrayLength; ++index)
    {
        std::cout << array[index] << " ";
        if (array[index]==number)
            indexOfNumber=index;
    }
    std::cout << "\n";
    std::cout << "The index of your number is " << indexOfNumber;
    return 0;
}
