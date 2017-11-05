#ifndef __STRATEGY_H__
#define __STRATEGY_H__

#include <vector>

namespace cs427_527
{
  class Strategy
  {
  public:
    virtual ~Strategy();
    virtual bool rollAgain(std::vector<int> scores, int turnTotal, int target) = 0;
  };
}

#endif
