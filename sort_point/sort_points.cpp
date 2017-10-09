#include <iostream>

#include <utility>

#include "point.h"
#include "civector.h"


using cs427_527::Point;

int main(int argc, char **argv)
{
  cs427_527::CIVector<Point> pts;

  for (int i = 1; i + 1 < argc; i += 2)
    {
      pts.push_back(Point(std::atoi(argv[i]), std::atoi(argv[i + 1])));
    }

  pts.sort(std::less<Point>());

  std::cout << pts << std::endl;
}

