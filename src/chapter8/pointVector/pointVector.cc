#include <iostream>

#include "../../startStop.h"
#include "pointVector.h"
#include "Point3d.h"
#include "Vector3d.h"


int main_pointVector(void)
{
   printStartBar(__FILE__);
   Point3d_v2 p(1.0, 2.0, 3.0);
   Vector3d v(2.0, 2.0, -3.0);

   p.print();
   p.moveByVector(v);
   p.print();
   printStopBar(__FILE__);
   return 0;
}
