#include "scent.h"

#include "moving_agent.h"
#include "world.h"
#include "hex.h"

namespace cs427_527
{

  Scent::Scent(const World& w, const Hex& start) :
    MovingAgent(w, start, w.randomLocation()),
    origin(start)
  {
  }

  void Scent::actOn(Patient& p) const
  {
    p.acceptAction(*this);
  }

  bool Scent::isAlive() const
  {
    return !(position == goal);
  }

  Hex Scent::getOrigin() const
  {
    return origin;
  }
}
