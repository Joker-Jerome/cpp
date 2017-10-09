#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

#include <string>
#include <iostream>

namespace cs427_527
{
  class Point
  {
  public:
    Point(double xIn, double yIn);
    bool operator<(const Point& rhs) const;
    double distanceTo(const Point& p) const;
    std::string toString() const;
  private:
    double x;
    double y;
  };

  double euclideanDistance(double, double, double, double);

  std::ostream& operator<<(std::ostream& out, const Point& p);
}

#endif
