#ifndef SRC_CHAPTER8_SUMMARY_MONSTER_H_
#define SRC_CHAPTER8_SUMMARY_MONSTER_H_

#include <string>

namespace monsterGen
{

class Monster
{
public:
   enum MonsterType
   {
      Dragon,
      Goblin,
      Ogre,
      Orc,
      Skeleton,
      Troll,
      Vampire,
      Zombie,
      MAX_MONSTER_TYPES
   };
private:
   MonsterType m_type;
   std::string m_name;
   std::string m_roar;
   int m_hitPoints;

public:
   Monster(const MonsterType type, const std::string name,
         const std::string roar, const int hp);
   void print(void) const;

private:
   std::string typeToString(void) const;

};

} /* namespace monsterGen */

#endif /* SRC_CHAPTER8_SUMMARY_MONSTER_H_ */
