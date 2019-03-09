#include <iostream>
#include <array>
#include <random> // for std::mt19937
#include <ctime> // for std::time
#include "constants.h"

enum class Rank;
enum class Suit;
enum class GameOutcome;
struct Card;
void swapCard(Card &firstCard, Card &secondCard);
void printCard(const Card &card);
std::array<Card, Constants::noCards> createDeck();
void printDeck(const std::array<Card, Constants::noCards> &deck);
void swapCard(Card &firstCard, Card &secondCard);
void shuffleDeck(std::array<Card, Constants::noCards> &deck, std::mt19937 &mersenne,std::uniform_int_distribution<> &die);
int getCardValue(const Card &card);
GameOutcome playBlackjack(const std::array<Card, Constants::noCards> &deck);

enum class Rank
{
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE,
    MAX,
};

enum class Suit
{
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES,
    MAX,
};

enum class GameOutcome
{
    PLAYER_WINS,
    PLAYER_LOSES,
    TIE,
};

struct Card
{
    Rank rank;
    Suit suit;
};

using cardIndex = std::array<Card, Constants::noCards>::size_type;

void printCard(const Card &card)
{
    switch (card.rank)
    {
        case (Rank::TWO):
            std::cout << "2";
            break;
        case (Rank::THREE):
            std::cout << "3";
            break;
        case (Rank::FOUR):
            std::cout << "4";
            break;
        case (Rank::FIVE):
            std::cout << "5";
            break;
        case (Rank::SIX):
            std::cout << "6";
            break;
        case (Rank::SEVEN):
            std::cout << "7";
            break;
        case (Rank::EIGHT):
            std::cout << "8";
            break;
        case (Rank::NINE):
            std::cout << "9";
            break;
        case (Rank::TEN):
            std::cout << "10";
            break;
        case (Rank::JACK):
            std::cout << "J";
            break;
        case (Rank::QUEEN):
            std::cout << "Q";
            break;
        case (Rank::KING):
            std::cout << "K";
            break;
        case (Rank::ACE):
            std::cout << "A";
            break;
        default:
            std::cout << "?";
    }
    switch (card.suit)
    {
        case (Suit::CLUBS):
            std::cout << "C";
            break;
        case (Suit::DIAMONDS):
            std::cout << "D";
            break;
        case (Suit::HEARTS):
            std::cout << "H";
            break;
        case (Suit::SPADES):
            std::cout << "S";
            break;
    }
}

std::array<Card, Constants::noCards> createDeck()
{
    std::array<Card, Constants::noCards> deck;
    for (cardIndex index=0; index<Constants::noCards; ++index)
    {
        deck[index].suit=static_cast<Suit>(index%static_cast<int>(Suit::MAX));
        deck[index].rank=static_cast<Rank>(index%static_cast<int>(Rank::MAX));
    }
    return deck;
}

void printDeck(const std::array<Card, Constants::noCards> &deck)
{
    for (const Card &card : deck)
        {
            printCard(card);
            std::cout << " ";
        }

}

void swapCard(Card &firstCard, Card &secondCard)
{
    Card temp=firstCard;
    firstCard=secondCard;
    secondCard=temp;
}

void shuffleDeck(std::array<Card, Constants::noCards> &deck, std::mt19937 &mersenne,std::uniform_int_distribution<> &die) //is this the way to seed mersenne only once?
{

    for (cardIndex index=0; index<Constants::noCards; ++index)
        swapCard(deck[index], deck[die(mersenne)]);
}

int getCardValue(const Card &card)
{
    switch (card.rank)
    {
        case (Rank::TWO):
            return 2;
        case (Rank::THREE):
            return 3;
        case (Rank::FOUR):
            return 4;
        case (Rank::FIVE):
            return 5;
        case (Rank::SIX):
            return 6;
        case (Rank::SEVEN):
            return 7;
        case (Rank::EIGHT):
            return 8;
        case (Rank::NINE):
            return 9;
        case (Rank::TEN):
        case (Rank::JACK):
        case (Rank::QUEEN):
        case (Rank::KING):
            return 10;
        case (Rank::ACE):
            return 11;
    }
}

GameOutcome playBlackjack(const std::array<Card, Constants::noCards> &deck)
{

    const Card *cardPtr=&deck[0];
    int playerScore(0);
    int dealerScore(0);
    dealerScore+=getCardValue(*cardPtr);
    std::cout << "The dealer drew ";
    printCard(*cardPtr);
    std::cout << ". Their score now is " << dealerScore << "\n";
    ++cardPtr;
    playerScore+=getCardValue(*cardPtr);
    std::cout << "You drew ";
    printCard(*cardPtr);
    ++cardPtr;
    playerScore+=getCardValue(*cardPtr);
    std::cout << " and ";
    printCard(*cardPtr);
    ++cardPtr;
    std::cout << ". Your score now is " << playerScore << "\n";
    if (playerScore>Constants::criticalScore)
        return GameOutcome::PLAYER_LOSES;
    char hitOrStand;
    bool hit(true);
    do
    {
        while(true)
        {
            std::cout << "Do you want to hit(=h) or stand(=s)? ";
            std::cin >> hitOrStand;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(333,'\n');
            }
            else
            {
                std::cin.ignore(333,'\n');
                if (hitOrStand=='h' || hitOrStand=='s')
                    break;
            }
        }
        if (hitOrStand=='s')
        {
            std::cout << "Your final score is " << playerScore << "\n";
            hit=false;
        }
        else
        {
            playerScore+=getCardValue(*cardPtr);
            std::cout << "You got the ";
            printCard(*cardPtr);
            std::cout << ". Your score now is " << playerScore << "\n";
            if (playerScore>Constants::criticalScore)
                return GameOutcome::PLAYER_LOSES;
            ++cardPtr;
        }

    } while(hit);

    do
    {
        dealerScore+=getCardValue(*cardPtr);
        std::cout << "The dealer drew ";
        printCard(*cardPtr);
        std::cout << ". Their score now is " << dealerScore << "\n";
        if (dealerScore>Constants::criticalScore)
            return GameOutcome::PLAYER_WINS;
        ++cardPtr;
    }while(dealerScore<=Constants::changeTacticsScore);
    if (dealerScore>playerScore)
        return GameOutcome::PLAYER_LOSES;
    else if ((dealerScore==playerScore))
        return GameOutcome::TIE;
}

int main()
{
    std::mt19937 mersenne(static_cast<unsigned int>(std::time(nullptr)));
    std::uniform_int_distribution<> die(0, 51);
    std::array<Card, Constants::noCards> deck(createDeck());

    //printDeck(deck);
    bool continuePlaying(true);
    GameOutcome gameOutcome;
    char anotherRound;
    while(continuePlaying)
    {
        shuffleDeck(deck, mersenne, die);
        gameOutcome=(playBlackjack(deck));
        if (gameOutcome==GameOutcome::PLAYER_WINS)
            std::cout << "You won! Congratulations! \n";
        else if (gameOutcome==GameOutcome::TIE)
            std::cout << "It's a tie. \n";
        else
            std::cout << "You lost... Maybe next time... \n";
        while (true)
        {
            std::cout << "Do you want to play another round (y/n)? ";
            std::cin >> anotherRound;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(333,'\n');
            }
            else
            {
                std::cin.ignore(333,'\n');
                if (anotherRound=='n')
                {
                    continuePlaying=false;
                    break;
                }
                else if (anotherRound=='y')
                    break;
            }
        }
    }
    return 0;
}
