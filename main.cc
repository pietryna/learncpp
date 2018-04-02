#include <iostream>

#include "src/startStop.h"
#include "src/chapter6/blackjack.h"
#include "src/chapter7/prototypes.h"
#include "src/chapter7/calculator.h"
#include "src/chapter7/recursion.h"
#include "src/chapter7/summary.h"
#include "src/chapter8/prototypes_ch8.h"
#include "src/chapter8/accessSpecifiers.h"
#include "src/chapter8/pointVector/pointVector.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
   printStartBar(__FILE__);
   int returnVal = 0;

//   returnVal = main_blackjack();
//   returnVal = main_prototypes();
//   returnVal = main_calculator();
//   returnVal = main_recursion();
//   returnVal = main_summary();
//   returnVal = main_ch8_prototypes();
//   returnVal = main_accesSpecifiers();
   returnVal = main_pointVector();

   printStopBar(__FILE__);
   return returnVal;
}
