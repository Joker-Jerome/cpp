#ifndef __AGENT_H__
#define __AGENT_H__

#include "patient.h"
#include "hex.h"

namespace cs427_527
{
  class Agent : public Patient
  {
  public:
    ~Agent() {}
    virtual Hex getPosition() const = 0;
    virtual void update() = 0;
    virtual bool isAlive() const = 0;
    virtual Agent *spawn() = 0;
    virtual void actOn(Patient& a) const = 0;
  };
}

#endif
