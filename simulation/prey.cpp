#include "prey.h"

#include "world.h"

namespace cs427_527
{

  Prey::Prey(const World& w) : MovingAgent(w)
  {
    eaten = false;
  }

  void Prey::actOn(Patient& p) const
  {
    p.acceptAction(*this);
  }

  void Prey::acceptAction(const Predator& p)
  {
    eaten = true;
  }

  void Prey::acceptAction(const Scent& s)
  {
    goal = s.getOrigin();
  }

  bool Prey::isAlive() const
  {
    return !eaten;
  }

}
