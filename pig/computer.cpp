#include <string>

#include "computer.h"

namespace cs427_527
{
  Computer::Computer(const std::string& n, int t)
    : Player(n),
      threshold(t)
  {
  }

  Computer::~Computer()
  {
  }

  bool Computer::rollAgain(std::vector<int> scores, int turnTotal, int target)
  {
    return turnTotal < threshold;
  }
}
