#include <iostream>
#include <array>
#include <assert.h>

#include "../startStop.h"
#include "accessSpecifiers.h"

class Point3d
{
private:
   double m_X, m_Y, m_Z;
public:
   void setValues(const double x, const double y, const double z)
   {
      m_X = x;
      m_Y = y;
      m_Z = z;
   }

   void print(void)
   {
      std::cout << "<" << m_X << ", " << m_Y << ", " << m_Z << ">" << std::endl;
   }

   bool isEqual(const Point3d &point)
   {
      if(this->m_X != point.m_X)
         return false;
      if(this->m_Y != point.m_Y)
         return false;
      if(this->m_Z != point.m_Z)
         return false;
      return true;
   }
};

class Stack
{
private:
   std::array<int, 10> stack;
   unsigned short stackPointer = 0;

public:
   void reset(void)
   {
      stack.fill(0);
      stackPointer = 0;
   }
   bool push(const int elem)
   {
      if(stackPointer < stack.size())
      {
         stack.at(stackPointer++) = elem;
         return true;
      }
      else
         return false;
   }
   int pop(void)
   {
      assert(stackPointer > 0);
      return stack.at(stackPointer--);
   }
   void print(void)
   {
      std::cout << "( ";
      for(int i = 0; i < stackPointer; ++i)
      {
         std::cout << stack.at(i) << " ";
      }
      std::cout << ")" << std::endl;
   }
};

void exe1(void)
{
   Point3d point;
   point.setValues(1.0, 2.0, 3.0);

   point.print();
}

void exe2(void)
{
   Point3d point1;
   point1.setValues(1.0, 2.0, 3.0);
   point1.print();

   Point3d point2;
   point2.setValues(1.0, 2.0, 3.0);
   point2.print();

   if (point1.isEqual(point2))
       std::cout << "point1 and point2 are equal\n";
   else
       std::cout << "point1 and point2 are not equal\n";

   Point3d point3;
   point3.setValues(3.0, 4.0, 5.0);
   point3.print();

   if (point1.isEqual(point3))
       std::cout << "point1 and point3 are equal\n";
   else
       std::cout << "point1 and point3 are not equal\n";
}

void exe3(void)
{
   std::cout << std::endl << "Stack" << std::endl;
   Stack stack;
   stack.reset();

   stack.print();

   stack.push(5);
   stack.push(3);
   stack.push(8);
   stack.print();

   stack.pop();
   stack.print();

   stack.pop();
   stack.pop();

   stack.print();
}

int main_accesSpecifiers(void)
{
   printStartBar(__FILE__);
   exe1();
   exe2();
   exe3();
   printStopBar(__FILE__);
   return 0;
}
