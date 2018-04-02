#ifndef SRC_CHAPTER8_POINTVECTOR_VECTOR3D_H_
#define SRC_CHAPTER8_POINTVECTOR_VECTOR3D_H_

#include "Point3d.h"

class Vector3d
{
private:
   double m_x, m_y, m_z;

public:
   Vector3d(double x = 0.0, double y = 0.0, double z = 0.0)
      : m_x(x), m_y(y), m_z(z) {}

   void print();

   friend void Point3d_v2::moveByVector(const Vector3d &v);
};

#endif /* SRC_CHAPTER8_POINTVECTOR_VECTOR3D_H_ */
