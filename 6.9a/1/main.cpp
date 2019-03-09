#include <iostream>
#include <algorithm>
#include <string.h>

int getNoNames();
void typeInNames(std::string *namesPtr, int noNames);
void sortNames(std::string *array, int noNames);
void printSortedNames(std::string *namesPtr, int noNames);


int getNoNames()
{
    std::cout << "How many names would you like to enter? ";
    int number;
    std::cin >> number;
    return number;
}

void typeInNames(std::string *namesPtr, int noNames)
{
    std::string currentName;
    for (int noCurrentName=0; noCurrentName < noNames; ++noCurrentName)
    {
        std::cout << "Enter name #" << noCurrentName+1 << ": ";
        std::cin >> currentName;
        namesPtr[noCurrentName] = currentName;
    }
}


void sortNames(std::string *names, int noNames) // bubblesort
{
    bool arraySorted(false);
    while (!arraySorted)
    {
        arraySorted=true;
        for (int index=0; index<noNames-1; ++index)
        {
            if (names[index]>names[index+1])
                {
                    std::swap(names[index],names[index+1]);
                    arraySorted=false;
                }
        }
        --noNames; // the biggest element of the current subarray is the last element after one iteration
    }
}

void printSortedNames(std::string *namesPtr, int noNames)
{
    std::cout << "\nHere is your sorted list:\n";
    for (int noCurrentName=0; noCurrentName < noNames; ++noCurrentName)
        std::cout << "Name #" << noCurrentName+1 << ": " << namesPtr[noCurrentName] << "\n";
}

int main()
{
    const int noNames(getNoNames());
    std::string *namesPtr=new std::string[noNames];
    typeInNames(namesPtr, noNames);
    sortNames(namesPtr, noNames);
    printSortedNames(namesPtr, noNames);
    delete[] namesPtr;
    return 0;
}
