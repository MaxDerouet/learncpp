#include <iostream>

struct advertising
{
    int number; //of ads
    double percentage; //of ads clicked
    double earning; //average

};

void printAdInfo(advertising ad)
{
    std::cout << "You advertise " << ad.number << " ads. \n";
    std::cout << "Users click on " << ad.percentage << "% of your ads. \n";
    std::cout << "For each click you earn " << ad.earning << ".\n";;
    double totalEarning(ad.number*(ad.percentage/100)*ad.earning);
    std::cout << "In total you earned " << totalEarning << ".\n";
}



int main()
{
    int numberAds;
    std::cout << "How many ads were shown today? ";
    std::cin >> numberAds;
    double percentagAds;
    std::cout << "What percentage of users clicked on the ads? ";
    std::cin >> percentagAds;
    double earningAds;
    std::cout << "What was the average earnings per click? ";
    std::cin >> earningAds;
    advertising ad{numberAds,percentagAds,earningAds};
    printAdInfo(ad);
    return 0;
}
