#include "abstract_agent.h"

#include <cstdlib>

#include "world.h"
#include "hex.h"

namespace cs427_527
{

  AbstractAgent::AbstractAgent(const World& w) :
    world(w), position(w.randomLocation())
  {
  }

  AbstractAgent::AbstractAgent(const World& w, const Hex& p) :
    world(w), position(p)
  {
  }

  Hex AbstractAgent::getPosition() const
  {
    return position;
  }

  void AbstractAgent::update()
  {
  }

  Agent *AbstractAgent::spawn()
  {
    return NULL;
  }

  bool AbstractAgent::isAlive() const
  {
    return true;
  }

  void AbstractAgent::acceptAction(const Predator& p)
  {
  }

  void AbstractAgent::acceptAction(const Scent& s)
  {
  }

  void AbstractAgent::acceptAction(const Prey& p)
  {
  }

  void AbstractAgent::acceptAction(const Food& p)
  {
  }

}
