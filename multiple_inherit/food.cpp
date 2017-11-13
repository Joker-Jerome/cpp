#include <cstdlib>

#include "food.h"

namespace cs427_527
{

  Food::Food(const World& w) : AbstractAgent(w)
  {
  }

  void Food::actOn(Patient& p) const
  {
    p.acceptAction(*this);
  }

  void Food::acceptAction(const Prey& p)
  {
    eaten = true;
  }

  bool Food::isAlive() const
  {
    return !eaten;
  }

  Agent *Food::spawn()
  {
    if (random() % 12 == 0)
      {
	return new Scent(world, position);
      }
    else
      {
	return NULL;
      }
  }

}

