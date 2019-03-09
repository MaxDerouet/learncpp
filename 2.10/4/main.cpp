/*
The state of a ball dropped from a user-specified height is calculated afte 1,2,3,4 and 5 seconds
*/

#include <iostream>
#include "constants.h"
#include "4.h"

double getHeight()
{
    std::cout << "Enter the height of the tower in meters ";
    int height;
    std::cin >> height;
    return height;
}

double calculateHeight(double startingHeight, double time)
{
    return startingHeight-constants::gravity*time*time/2;
}

void printHeight(double height, double time)
{
    if (height > 0.0)
        std::cout << "At "<< time << " seconds, the ball is at height: " << height << "meters \n";
    else
        std::cout << "At "<< time << " seconds, the ball is on the ground \n";
}

int main()
{
    double startingHeight(getHeight());
    constexpr double startingTime(0);
    printHeight(calculateHeight(startingHeight,startingTime),startingTime);
    printHeight(calculateHeight(startingHeight,startingTime+1),startingTime+1);
    printHeight(calculateHeight(startingHeight,startingTime+2),startingTime+2);
    printHeight(calculateHeight(startingHeight,startingTime+3),startingTime+3);
    printHeight(calculateHeight(startingHeight,startingTime+4),startingTime+4);
    printHeight(calculateHeight(startingHeight,startingTime+5),startingTime+5);
}
