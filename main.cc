#include <iostream>

#include "src/chapter6/blackjack.h"
#include "src/chapter7/prototypes.h"
#include "src/chapter7/calculator.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
   cout << "learncpp.com main" << endl;
   int returnVal = 0;

   //returnVal = main_blackjack();
   //returnVal = main_prototypes();
   returnVal = main_calculator();

   return returnVal;
}
