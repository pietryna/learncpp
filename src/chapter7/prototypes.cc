#include <iostream>
#include <limits.h>

#include "prototypes.h"

int sumTo(const int lim)
{
   int sum = 0;
   for (int i = 1; i <= lim; i++)
      sum += i;
   return sum;
}

struct Employee
{
   std::string name
   { };
   unsigned short age;
};

void printEmployeeName(const Employee &record)
{
   std::cout << record.name << std::endl;
}

void minMax(const int A, const int B, int &out_smaller, int &out_higher)
{
   if (A < B)
   {
      out_higher = B;
      out_smaller = A;
   }
   else
   {
      out_higher = A;
      out_smaller = B;
   }
}

int getIndexOfLargest(const int tab[], const int size)
{
   int largestValue = INT_MIN;
   int index = 0;

   for(int i = 0; i < size; ++i)
   {
      if (tab[i] > largestValue)
      {
         largestValue = tab[i];
         index = i;
      }
   }
   return index;
}

const int &getElement(const int tab[], const int index)
{
   return static_cast<const int&>(tab[index]);
}

int main_prototypes()
{
   std::cout << std::endl << "-------------------------------" << std::endl
         << "main prototypes" << std::endl;

   std::cout << "Sum from 1 to 5: " << sumTo(5) << std::endl;

   Employee employee
   { "Alex", 25u };
   printEmployeeName(employee);

   int small(0), high(0);
   minMax(2, 3, small, high);
   std::cout << "Which is smaller 2 or 3? Smaller: " << small << " Higher: "
         << high << std::endl;

   const int tab[]
   { 1, 5, 32, 7, -12, -2, 33 };
   std::cout << "Index of highest value {1, 5, 32, 7, -12, -2, 33} is: "
         << getIndexOfLargest(tab, sizeof(tab) / sizeof(int)) << std::endl;

   std::cout << "Value of this element is "
         << getElement(tab, getIndexOfLargest(tab, sizeof(tab) / sizeof(int)))
         << std::endl;

   std::cout << "-------------------------------";
   return 0;
}
