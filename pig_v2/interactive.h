#ifndef __INTERACTIVE_H__
#define __INTERACTIVE_H__

#include "strategy.h"

namespace cs427_527
{
  class InteractiveStrategy : public Strategy
  {
  public:
    bool rollAgain(std::vector<int> scores, int turnTotal, int target);
  };
}

#endif
