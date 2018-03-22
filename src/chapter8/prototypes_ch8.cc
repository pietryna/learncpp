#include <iostream>

#include <cstring>

#include "../startStop.h"
#include "prototypes_ch8.h"


class IntPair {
private:
   int m_A, m_B;
public:
   IntPair() : m_A(0), m_B(0) {}
   IntPair(int a, int b) : m_A(a), m_B(b) {}

   void set(int a, int b);
   void print(void);
};

void IntPair::set(int a, int b)
{
   m_A = a;
   m_B = b;
}

void IntPair::print(void)
{
   std::cout << "m_A = " << m_A << ", m_B = " << m_B << std::endl;
}


int main_ch8_prototypes(void)
{
   printStartBar(__FILE__);

   IntPair p1;
   p1.set(1,4);

   IntPair p2{3,6};

   p1.print();
   p2.print();

   printStopBar(__FILE__);
   return 0;
}
