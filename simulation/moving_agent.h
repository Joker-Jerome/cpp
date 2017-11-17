#ifndef __MOVING_AGENT_H__
#define __MOVING_AGENT_H__

#include "abstract_agent.h"

namespace cs427_527
{

  class MovingAgent : public AbstractAgent
  {
  public:
    MovingAgent(const World& w);
    MovingAgent(const World& w, const Hex& start, const Hex& g);
    ~MovingAgent() {}

    virtual void update();

  protected:
    Hex goal;
  };

}
#endif
