#include <iostream>

enum class MonsterType
{
    OGRE,
    DRAGON,
    ORC,
    GIANT_SPIDER,
    SLIME,
};

struct Monster
{
    MonsterType type;
    std::string name;
    int health;
};

std::string getMonsterType(MonsterType type)
{
    if (type==MonsterType::OGRE)
        return "Ogre";
    if (type==MonsterType::DRAGON)
        return "Dragon";
    if (type==MonsterType::ORC)
        return "Orc";
    if (type==MonsterType::GIANT_SPIDER)
        return "Giant Spider";
    if (type==MonsterType::SLIME)
        return "Slime";
    return "Unknown";

}

void printMonster(Monster monster)
{
    std::cout << "This " << getMonsterType(monster.type) << " is named " << monster.name << " and has " << monster.health << " health. \n";
}

int main()
{
    Monster firstMonster{MonsterType::OGRE,"Torg",145};
    printMonster(firstMonster);
    Monster secondMonster{MonsterType::SLIME,"Blurp",23};
    printMonster(secondMonster);
    return 0;
}
