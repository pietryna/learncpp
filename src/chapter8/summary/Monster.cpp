#include "Monster.h"

#include <iostream>

namespace monsterGen
{

Monster::Monster(const MonsterType type, const std::string name, const std::string roar, const int hp) :
      m_type(type), m_name(name), m_roar(roar), m_hitPoints(hp) {}

std::string Monster::typeToString(void) const
{
   switch (m_type)
   {
   case Dragon:
      return "dragon";
   case Goblin:
      return "goblin";
   case Ogre:
      return "ogre";
   case Orc:
      return "orc";
   case Skeleton:
      return "skeleton";
   case Troll:
      return "troll";
   case Vampire:
      return "vampire";
   case Zombie:
      return "zombie";
   default:
      return "FAIL";
   }
}

void Monster::print(void) const
{
   std::cout << m_name << " the " << typeToString() << " has " << m_hitPoints
         << " hit points and says " << m_roar << " \n";
}
} /* namespace monsterGen */
