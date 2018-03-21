#include <iostream>

#include <cstdlib>
#include <time.h>

#include "recursion.h"

using std::cout;
using std::cin;
using std::endl;

int factorial(int N)
{
   if (N == 0 || N == 1)
      return 1;
   else
      return factorial(N - 1) * N;
}

int digitSum(int N)
{
   if (N < 10)
      return N;
   else
      // N/10 drops rightmost digit, N%10 extracts this one for addition
      return digitSum(N / 10) + N % 10;
}

void intToBin(int N)
{
   unsigned int uN = static_cast<unsigned int>(N);
   if( uN == 0 )
   {
      cout << '0';
      return;
   }

   intToBin(uN/2);

   cout << uN%2;
}

int main_recursion()
{
   std::cout << std::endl << "-------------------------------" << std::endl
            << "main recursion" << std::endl;

   srand(time(0));
   rand();

   cout << "Recursion" << endl;

   cout << "Factorial:" << endl;
   for (int i = 0; i < 8; ++i)
      cout << i << "! = " << factorial(i) << endl;
   cout << endl;

   cout << "Digits sum:" << endl;
   for( int i = 0; i < 5; ++i)
   {
      const int min = 1, max = 9999;
      unsigned int tmp = min + (rand() % static_cast<int>(max - min + 1));
      cout << "Number: " << tmp << " sum: " << digitSum(tmp) << endl;
   }
   cout << endl;

   cout << "Int to bin:" << endl;
   intToBin(0xAF);
   cout << endl;
   intToBin(0x5A);
   cout << endl;
   intToBin(0x01);
   cout << endl;
   intToBin(0x80);
   cout << endl;
   intToBin(-15);
   cout << endl;
   intToBin(0);
   cout << endl;

   std::cout << "-------------------------------";
   return 0;
}
