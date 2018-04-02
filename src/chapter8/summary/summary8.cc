#include "summary8.h"

#include <iostream>
#include <utility>

#include "../../startStop.h"
#include "Point2d.h"
#include "HelloWorld.h"
#include "Monster.h"
#include "MonsterGenerator.h"

int main_summary8(void)
{
   printStartBar(__FILE__);
   exec1::Point2d first;
   exec1::Point2d second(3.0, 4.0);
   first.print();
   second.print();
   std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';
   std::cout << "Distance between two points: " << exec1::distanceFrom(first, second) << '\n';

   exec2::HelloWorld instance;
   instance.print();

   srand(static_cast<unsigned int>(time(0)));
   monsterGen::Monster m = monsterGen::MonsterGenerator::generateMonster();
   m.print();

   printStopBar(__FILE__);
   return 0;
}


