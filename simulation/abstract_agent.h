#ifndef __ABSTRACT_AGENT_H__
#define __ABSTRACT_AGENT_H__

#include "world.h"
#include "hex.h"
#include "agent.h"

namespace cs427_527
{

  class AbstractAgent : public Agent
  {
  public:
    AbstractAgent(const World &w);
    AbstractAgent(const World &w, const Hex &pos);
    ~AbstractAgent() {}
  
    virtual Hex getPosition() const;
    virtual void update();
    virtual bool isAlive() const;
    virtual Agent *spawn();
    virtual void actOn(Patient& a) const = 0;

    virtual void acceptAction(const Predator& p);
    virtual void acceptAction(const Prey& p);
    virtual void acceptAction(const Food& f);
    virtual void acceptAction(const Scent& s);

  protected:
    const World &world;
    Hex position;
  };

}
#endif
