#include "HelloWorld.h"

#include <iostream>

namespace exec2
{
HelloWorld::HelloWorld()
{
   std::cout << "Create HelloWorld instance \n";
   m_data = new char[14];
   const char *init = "Hello, World!";
   for (int i = 0; i < 14; ++i)
      m_data[i] = init[i];
}

HelloWorld::~HelloWorld()
{
   std::cout << "Delete HelloWorld instance \n";
   delete[] m_data;
}

void HelloWorld::print() const
{
   std::cout << m_data << std::endl;
}

} /* namespace exec2 */
