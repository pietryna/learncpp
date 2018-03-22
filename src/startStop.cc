#include <iostream>
#include <string.h>

#include <cstring>

#include "startStop.h"


void printStartBar(const char* filename)
{
   std::string startBar =
         "------------------------------------------------------------";
   std::string start = " START: ";
   start.append(filename);
   start.append(" ");

   startBar.erase(5, strlen(start.c_str()));
   startBar.insert(5, start);
   std::cout << startBar << std::endl;
}

void printStopBar(const char* filename)
{
   std::string stopBar =
         "------------------------------------------------------------";
   std::string end = " END:   ";
   end.append(filename);
   end.append(" ");

   stopBar.erase(5, strlen(end.c_str()));
   stopBar.insert(5, end);
   std::cout << stopBar << std::endl << std::endl;
}
