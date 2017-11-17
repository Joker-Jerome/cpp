#include "moving_agent.h"

namespace cs427_527
{
  
  MovingAgent::MovingAgent(const World& w) :
    AbstractAgent(w), goal(w.randomLocation())
  {
  }

  MovingAgent::MovingAgent(const World& w, const Hex& start, const Hex& g) :
    AbstractAgent(w, start), goal(g)
  {
  }

  void MovingAgent::update()
  {
    if (position == goal)
      {
	goal = world.randomLocation();
      }

    position = position.closer(goal);
  }

}
