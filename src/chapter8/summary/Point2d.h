#ifndef SRC_CHAPTER8_SUMMARY_POINT2D_H_
#define SRC_CHAPTER8_SUMMARY_POINT2D_H_

namespace exec1
{

class Point2d
{
private:
   double m_x, m_y;

public:
   Point2d(const double x = 0, const double y = 0) : m_x(x), m_y(y) {}
   void print(void) const;
   double distanceTo(const Point2d &point) const;
   friend double distanceFrom(const Point2d &p1, const Point2d &p2);
};

double distanceFrom(const Point2d &p1, const Point2d &p2);

} /* namespace exec1 */

#endif /* SRC_CHAPTER8_SUMMARY_POINT2D_H_ */
