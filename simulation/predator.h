#ifndef __PREDATOR_H__
#define __PREDATOR_H__

#include "moving_agent.h"

namespace cs427_527
{

  class Predator : public MovingAgent
  {
  public:
    Predator(const World& w);
    ~Predator() {}

    virtual void actOn(Patient& p) const;
    virtual void acceptAction(const Scent& s);
  };

}
#endif
