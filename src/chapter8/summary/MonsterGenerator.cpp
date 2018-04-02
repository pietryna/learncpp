#include "MonsterGenerator.h"

#include <utility>

namespace monsterGen
{

constexpr short NO_OF_ELEMS = 6;

Monster MonsterGenerator::generateMonster(void)
{
   static std::array<std::string, NO_OF_ELEMS> m_NamesList =
   {"Frank", "Bill", "Andrew", "Joshua", "Brandon", "Jeff"};
   static std::array<std::string, NO_OF_ELEMS> m_RoarsList =
         {"Die fool", "It's your last day here", "Hahahaha",
          "What's that smell?", "Scumbag!", "Whatever..."};

   return Monster(
         static_cast<Monster::MonsterType>(getRandomNumber(0,
               Monster::MAX_MONSTER_TYPES - 1)),
         m_NamesList[getRandomNumber(0, NO_OF_ELEMS-1)],
         m_RoarsList[getRandomNumber(0, NO_OF_ELEMS-1)], getRandomNumber(1, 100));
}

// Generate a random number between min and max (inclusive)
// Assumes srand() has already been called
int MonsterGenerator::getRandomNumber(int min, int max)
{
   static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
   // evenly distribute the random number across our range
   return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

} /* namespace monsterGen */
