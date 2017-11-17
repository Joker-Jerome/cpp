#include "predator.h"

#include "world.h"
#include "scent.h"

namespace cs427_527
{

  Predator::Predator(const World &w) : MovingAgent(w)
  {
  }

  void Predator::actOn(Patient& p) const
  {
    p.acceptAction(*this);
  }

  void Predator::acceptAction(const Scent &s)
  {
    goal = s.getOrigin();
  }

}
