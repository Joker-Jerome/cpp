#include <iostream>

#include "geometry.h"

// like java's import java.util.LinkedList;

using std::cout;
using std::cin;
using std::endl;

// like java's import java.util.*;
// (not considered good practice)
//using namespace bloxomo;
//using namespace std;

int main(int argc, char **argv)
{
  double totalDistance = 0.0;
  double lastX, lastY;
  double x, y;

  cin >> lastX;
  cin >> lastY;
  while (cin >> x >> y)
    {
      totalDistance += geometry::euclideanDistance(x, y, lastX, lastY);
      lastX = x;
      lastY = y;
    }
  cout << totalDistance << endl;
}
