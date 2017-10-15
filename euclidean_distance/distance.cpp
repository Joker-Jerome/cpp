#include <iostream>

#include "geometry.h"

// create an alias so we don't have to keep typing "geometry::Point"
using Point2D = geometry::Point;

int main(int argc, char **argv)
{
  double totalDistance = 0.0;

  // read x and y
  double x, y;
  std::cin >> x >> y;

  // create the point (x, y)
  Point2D last(x, y);

  // keep reading x and y until we can't any more
  while (std::cin >> x >> y)
    {
      // make another point (x, y)
      Point2D curr(x, y);

      // add the distance from the current point to the last one into total
      totalDistance += curr.distanceTo(last);

      // remember current point for next time around loop
      last = curr;
    }
  
  std::cout << totalDistance << std::endl;
}
