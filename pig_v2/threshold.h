#ifndef __THRESHOLD_H__
#define __THRESHOLD_H__

#include "strategy.h"

namespace cs427_527
{
  class ThresholdStrategy : public Strategy
  {
  public:
    ThresholdStrategy(int thresh);
    bool rollAgain(std::vector<int> scores, int turnTotal, int target);

  protected:
    int threshold;
  };
}

#endif
