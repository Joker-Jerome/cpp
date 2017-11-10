#ifndef __DYNAMIC_H__
#define __DYNAMIC_H__

#include <string>

#include <vector>

#include "computer.h"

namespace cs427_527
{

  class DynamicComputer : public Computer
  {
  public:
    DynamicComputer(const std::string& n, int t);
    ~DynamicComputer();
  protected:
    int getThreshold(std::vector<int> scores, int target) const;

  };
}

#endif
