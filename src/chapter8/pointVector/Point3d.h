#ifndef SRC_CHAPTER8_POINTVECTOR_POINT3D_H_
#define SRC_CHAPTER8_POINTVECTOR_POINT3D_H_

class Vector3d;

class Point3d_v2
{
private:
   double m_x, m_y, m_z;

public:
   Point3d_v2(double x = 0.0, double y = 0.0, double z = 0.0)
      : m_x(x), m_y(y), m_z(z) {}

   void print();
   void moveByVector(const Vector3d &v);
};

#endif /* SRC_CHAPTER8_POINTVECTOR_POINT3D_H_ */
