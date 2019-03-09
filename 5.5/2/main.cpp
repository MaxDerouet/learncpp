#include <iostream>

void printLetters()
{
    char letter('a');
    while (letter<='z')
    {
        std::cout << "The letter " << letter << " has the ASCII-code " << static_cast<int>(letter) << ".\n";
        ++letter;
    }
}

int main()
{
    printLetters();
    return 0;
}
