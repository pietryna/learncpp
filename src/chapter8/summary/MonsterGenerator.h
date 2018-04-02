#ifndef SRC_CHAPTER8_SUMMARY_MONSTERGENERATOR_H_
#define SRC_CHAPTER8_SUMMARY_MONSTERGENERATOR_H_

#include "Monster.h"
#include <array>
#include <string>

namespace monsterGen
{

class MonsterGenerator
{
public:
   static Monster generateMonster(void);
private:
   static int getRandomNumber(int min, int max);
};

} /* namespace monsterGen */

#endif /* SRC_CHAPTER8_SUMMARY_MONSTERGENERATOR_H_ */
