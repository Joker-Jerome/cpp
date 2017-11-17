#ifndef __FOOD_H__
#define __FOOD_H__

#include "agent.h"
#include "abstract_agent.h"
#include "world.h"
#include "prey.h"

namespace cs427_527
{

  class Food : public virtual AbstractAgent
  {
  public:
    Food(const World &w);
    ~Food() {}

    virtual void actOn(Patient& p) const;
    virtual void acceptAction(const Prey& p);
    virtual bool isAlive() const;
    virtual Agent *spawn();

  protected:
    bool eaten;
  };

}
#endif
