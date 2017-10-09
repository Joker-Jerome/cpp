#include <cmath>

#include <string>
#include <iostream>
#include <sstream>

#include "point.h"

namespace cs427_527
{
  double euclideanDistance(double x1, double y1, double x2, double y2)
  {
    double distance = std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
    return distance;
  }

  Point::Point(double xIn, double yIn)
  {
    x = xIn;
    y = yIn;
  }
  

  bool Point::operator<(const Point& rhs) const
  {
    return x < rhs.x || (x == rhs.x && y < rhs.y);
  }

  std::string Point::toString() const
  {
    std::ostringstream out;
    out << "(" << x << ", " << y << ")";
    return out.str();
  }
  
  double Point::distanceTo(const Point& p) const
  {
    return euclideanDistance(x, y, p.x, p.y);
  }

  std::ostream& operator<<(std::ostream& out, const Point& p)
  {
    return out << p.toString();
  }

}
