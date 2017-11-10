#include "computer.h"
#include "dynamic.h"

namespace cs427_527
{
  DynamicComputer::DynamicComputer(const std::string& n, int t)
    : Computer(n, t)
  {
  }

  DynamicComputer::~DynamicComputer()
  {
  }

  int DynamicComputer::getThreshold(std::vector<int> scores, int target) const
  {
    return threshold - (scores[0] - scores[1]) / 10;
  }

  
}
