#include "math.h"

namespace cs427_527
{
  int imax(int a, int b)
  {
    return (a > b) ? a : b;
  }
  
  int iabs(int a) {
    return (a < 0) ? -a : a;
  }

  int distance(int fromR, int fromC, int toR, int toC)
  {
    return imax(iabs(fromR - toR), iabs(fromC - toC));
  }
}
  
