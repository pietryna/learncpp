#include "Point2d.h"

#include <iostream>
#include <cmath>

namespace exec1
{
void Point2d::print(void) const
{
   std::cout << "Point2d(" << m_x << ", " << m_y << ")" << std::endl;
}
// sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2))
double Point2d::distanceTo(const Point2d &p) const
{
   return std::sqrt(std::pow((m_x - p.m_x), 2) + std::pow((m_y - p.m_y), 2));
}
double distanceFrom(const Point2d &p1, const Point2d &p2)
{
   return std::sqrt(std::pow((p1.m_x - p2.m_x), 2) + std::pow((p1.m_y - p2.m_y), 2));
}

} /* namespace exec1 */
