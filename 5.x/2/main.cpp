#include <iostream>
#include <cstdlib> // for std::rand() and std::srand()
#include <ctime> // for std::time()
#include "constants.h"

int getRandomNumber(int min, int max);
bool restartGame();
int getGuess();


int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (RAND_MAX + 1.0);
    return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

bool restartGame()
{
    while (true)
        {
            std::cout << "Would you like to play another round? (y/n) ";
            char choice;
            std::cin >> choice;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(constants::ignoreCharacters,'\n');
            }
            else
            {
                std::cin.ignore(constants::ignoreCharacters,'\n');
                if (choice == 'y')
                    return true;
                else if (choice == 'n')
                    return false;
            }

        }

}

int getGuess()
{
    while (true)
    {
        std::cout << "Guess a number: ";
            int guess;
            std::cin >> guess;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(constants::ignoreCharacters,'\n');
        }
        else
        {
            std::cin.ignore(constants::ignoreCharacters,'\n');
            return guess;
        }
    }
}

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int numberToGuess(getRandomNumber(constants::lowerBound,constants::upperBound));
    int round(1);
    int guess;
    bool anotherRound(true);
    bool restart;
    bool gameLost(true);
    do
    {
        do
        {
            guess=getGuess();
            if (guess < numberToGuess)
            {
                std::cout << "Your number is too low... \n";
            }
            else if (guess > numberToGuess)
            {
                std::cout << "Your number is too high... \n";
            }
            else
            {
                std::cout << "You won! That was the right number! \n";
                anotherRound=false;
                gameLost=false;
            }
            ++round;
        } while (round<=constants::noGuesses && anotherRound);
        if (gameLost)
        {
            std::cout << "You lost! The number to guess was " << numberToGuess << "\n";
            std::cout << "Maybe next time... \n";
        }
        round=1;
        gameLost=true;
        restart=restartGame();
    } while (restart);
    return 0;
}
