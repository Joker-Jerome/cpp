#ifndef __SCENT_H__
#define __SCENT_H__

#include "moving_agent.h"
#include "world.h"

namespace cs427_527
{ 

  class Scent : public MovingAgent
  {
  public:
    Scent(const World& w, const Hex& start);
    ~Scent() {}

    Hex getOrigin() const;

    virtual void actOn(Patient& p) const;
    virtual bool isAlive() const;

  protected:
    Hex origin;
  };
  
}
#endif
