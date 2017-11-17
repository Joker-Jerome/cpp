#ifndef __PREY_H__
#define __PREY_H__

#include "moving_agent.h"
#include "world.h"
#include "predator.h"
#include "scent.h"

namespace cs427_527
{

  class Prey : public MovingAgent
  {
  public:
    Prey(const World &w);
    ~Prey() {}

    virtual void actOn(Patient& p) const;
    virtual void acceptAction(const Predator& p);
    virtual void acceptAction(const Scent& s);
    virtual bool isAlive() const;

  protected:
    bool eaten;
  };
  
}
#endif
