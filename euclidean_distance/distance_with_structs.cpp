#include <iostream>

#include "geometry.h"

// create an alias so we don't have to keep typing "geometry::point"
using Point2D = geometry::point;

int main(int argc, char **argv)
{
  double totalDistance = 0.0;

  // read into 1st point
  Point2D last;
  std::cin >> last.x >> last.y;

  Point2D curr;
  // keep reading points until we can't any more
  while (std::cin >> curr.x >> curr.y)
    {
      // add the distance from the current point to the last one into total
      totalDistance += euclideanDistance(curr, last);

      // remember current point for next time around loop
      last = curr;
    }
  
  std::cout << totalDistance << std::endl;
}
