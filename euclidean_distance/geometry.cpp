#include <cmath>

#include "geometry.h"

namespace geometry
{
  /**
   * Computes the Euclidean distance between two points (x1, y1) and (x2, y2).
   *
   * @param x1 a double
   * @param y1 a double
   * @param x2 a double
   * @param y2 a double
   * @return the Euclidean distance between (x1, y1) and (x2, y2)
   */
  double euclideanDistance(double x1, double y1, double x2, double y2)
  {
    double d = std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
    return d;
  }

  double euclideanDistance(const point& p1, const point& p2)
  {
    return euclideanDistance(p1.x, p1.y, p2.x, p2.y);
  }

  Point::Point()
  {
    x = 0.0;
    y = 0.0;
  }

  Point::Point(double xIn, double yIn)
  {
    x = xIn;
    y = yIn;
  }

  double Point::distanceTo(const Point& p) const
  {
    return euclideanDistance(x, y, p.x, p.y);
  }
  
}
