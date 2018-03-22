#include <iostream>

#include <cstring>

#include "../startStop.h"
#include "calculator.h"

using std::cout;
using std::cin;
using std::endl;

typedef int (*arithmeticFcn)(int, int);

struct arithmeticStruct
{
   arithmeticFcn operation;
   char op;
};


int getInt(void)
{
   int value = 0;
   while (true)
   {
      cout << "Chose integer number: " << endl;
      cin >> value;

      if (cin.fail())
      {
         cout << "Wrong input! Try again" << endl;
         cin.sync();
         cin.clear();
      }
      else
         break;
   }

   return value;
}

char getOperator(void)
{
   char value = '\n';
   while (true)
   {
      cout << "Chose integer operation (+, -, *, /): " << endl;
      cin >> value;

      if (cin.fail())
      {
         cout << "Wrong input! Try again." << endl;
         cin.sync();
         cin.clear();
      }
      else if ('+' != value && '-' != value && '*' != value && '/' != value)
      {
         cout << "Wrong operation chosen! Try again." << endl;
      }
      else
         break;
   }

   return value;
}

int add(int a, int b)
{
   return a + b;
}
int substract(int a, int b)
{
   return a - b;
}
int multipy(int a, int b)
{
   return a * b;
}
int divide(int a, int b)
{
   return a / b;
}

static arithmeticStruct arithmeticArray[] = { { add, '+' }, { substract, '-' },
                                              { multipy, '*' }, { divide, '/' } };
arithmeticFcn getArithmeticFunction(char op)
{
   for(const auto &elem : arithmeticArray)
   {
      if (elem.op == op)
         return elem.operation;
   }
   cout << "Massive failure!" << endl;
   return nullptr;
}


int main_calculator()
{
   printStartBar(__FILE__);

   cout << "Calculator 0.00001" << endl;
   int A = getInt();
   char op = getOperator();
   int B = getInt();

   cout << "Result: " << getArithmeticFunction(op)(A,B) << endl;

   printStopBar(__FILE__);
   return 0;
}
