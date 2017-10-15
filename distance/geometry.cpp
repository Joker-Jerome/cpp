#include <cmath>

#include "geometry.h"

namespace geometry
{

double euclideanDistance(double x1, double y1, double x2, double y2)
{
  double distance = std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
  return distance;
}

}
