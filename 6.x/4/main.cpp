#include <iostream>

void printCStyleString(const char *CstyleString)
{
    while (*CstyleString!='\0')
    {
        std::cout << *CstyleString;
        ++CstyleString;
    }
}

int main()
{
    char Cstyletring[]="Hello World";
    printCStyleString(Cstyletring);
    return 0;
}
