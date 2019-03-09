#include <iostream>
#include <string>
#include <array>
#include <cstdlib> // for std::rand() and std::srand()
#include <ctime> // for std::time()


class Monster
{
public:
    enum MonsterType
    {
        DRAGON,
        GOBLIN,
        OGRE,
        SKELETON,
        TROLL,
        VAMPIRE,
        ZOMBIE,
        MAX_MONSTER_TYPES,
    };
    Monster(MonsterType type, std::string name, std::string roar, int hitPoints):m_type{type},m_name{name},m_roar{roar},m_hitPoints{hitPoints}
    {
    }
    void print() const;
private:
    MonsterType m_type;
    std::string m_name;
    std::string m_roar;
    int m_hitPoints;
    std::string getTypeString() const;
};

void Monster::print() const
{
    std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar;
}

std::string Monster::getTypeString() const
{
    switch(m_type)
    {
        case(DRAGON):   return "dragon";
        case(GOBLIN):   return "goblin";
        case(OGRE):     return "ogre";
        case(SKELETON): return "skeleton";
        case(TROLL):    return "troll";
        case(VAMPIRE):  return "vampire";
        case(ZOMBIE):   return "zombie";
        default:        return "???";
    }
}

class MonsterGenerator
{
public:
    static int getRandomNumber(int min, int max)
    {
        static const double fraction = 1.0 / (RAND_MAX + 1.0);
        return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
    }
    static Monster generateMonster()
    {
        static std::array<std::string,6> s_names={"Igor","Bob","Smaug","Olaf","Thrall","Fred"};
        static std::array<std::string,6> s_roars={"*rattle*","roar","wuhu","raaaaaa","hehehe","zzzzz"};
        Monster::MonsterType type(static_cast<Monster::MonsterType>((getRandomNumber(0,static_cast<int>(Monster::MAX_MONSTER_TYPES)-1))));
        int hitPoints(getRandomNumber(0,100));
        return Monster(type, s_names[getRandomNumber(0,s_names.size()-1)], s_roars[getRandomNumber(0,s_roars.size()-1)] , hitPoints);
    }
};



int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::rand();
	Monster m = MonsterGenerator::generateMonster();
	m.print();

    return 0;
}
