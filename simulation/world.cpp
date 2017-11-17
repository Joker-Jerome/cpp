#include "world.h"

#include <vector>
#include <iostream>

#include <cstdlib>
#include <cmath>

#include "agent.h"
#include "prey.h"
#include "predator.h"
#include "food.h"
#include "hex.h"
#include "world.h"

namespace cs427_527
{

  World::World(int size, int numPrey, int numPredators, int numFood)
  {
    width = size;
    height = (int)(width * 2 / sqrt(3));

    for (int i = 0; i < numPrey; i++)
      {
	agents.push_back(new Prey(*this));
      }

    for (int i = 0; i < numPredators; i++)
      {
	agents.push_back(new Predator(*this));
      }

    for (int i = 0; i < numPrey; i++)
      {
	agents.push_back(new Food(*this));
      }
  }

  World::~World()
  {
    for (unsigned int i = 0; i < agents.size(); i++)
      {
	delete agents[i];
      }
  }

  int World::getWidth() const
  {
    return width;
  }

  int World::getHeight() const
  {
    return height;
  }

  Hex World::randomLocation() const
  {
    return Hex(rand() % width, rand() % height);
  }

  void World::update()
  {
    for (unsigned int i = 0; i < agents.size(); i++)
      {
	agents[i]->update();
      }

    for (unsigned int i = 0; i < agents.size(); i++)
      {
	for (unsigned int j = 0; j < agents.size(); j++)
	  {
	    if (i != j && agents[i]->getPosition() == agents[j]->getPosition())
	      {
		agents[i]->actOn(*agents[j]);
	      }
	  }
      }

    std::vector<Agent *> next;

    for (unsigned int i = 0; i < agents.size(); i++)
      {
	if (agents[i]->isAlive())
	  {
	    next.push_back(agents[i]);

	    Agent *spawn = agents[i]->spawn();
	    if (spawn != NULL)
	      {
		next.push_back(spawn);
	      }
	  }
	else
	  {
	    delete agents[i];
	  }
      }

    agents = next;
  }

  void World::actOn(Patient& p) const
  {
    for (unsigned int i = 0; i < agents.size(); i++)
      {
	agents[i]->actOn(p);
      }
  }

  void World::printTo(std::ostream& os) const
  {
    AgentMap map(width, height);

    actOn(map);

    map.printTo(os);
  }

  std::ostream& operator<<(std::ostream& os, const World& w)
  {
    w.printTo(os);
    return os;
  }

  AgentMap::AgentMap(int w, int h)
  {
    width = w;
    height = h;

    map = new char *[h];
    for (int r = 0; r < height; r++)
      {
	map[r] = new char[w];
	for (int c = 0; c < width; c++)
	  {
	    map[r][c] = '.';
	  }
      }
  }

  AgentMap::~AgentMap()
  {
    for (int r = 0; r < height; r++)
      {
	delete[] map[r];
      }
    delete[] map;
  }

  void AgentMap::printTo(std::ostream& os) const
  {
    for (int r = 0; r < height; r++)
      {
	if (r % 2 == 1)
	  {
	    os << ' ';
	  }

	for (int c = 0; c < width; c++)
	  {
	    os << map[r][c] << ' ';
	  }
	os << std::endl;
      }
  }

  void AgentMap::acceptAction(const Predator& p)
  {
    markMap(p.getPosition().getRow(), p.getPosition().getColumn(), 'P');
  }

  void AgentMap::acceptAction(const Prey& p)
  {
    markMap(p.getPosition().getRow(), p.getPosition().getColumn(), 'p');
  }

  void AgentMap::acceptAction(const Food& f)
  {
    markMap(f.getPosition().getRow(), f.getPosition().getColumn(), '*');
  }

  void AgentMap::acceptAction(const Scent& s)
  {
    markMap(s.getPosition().getRow(), s.getPosition().getColumn(), 'x');
  }

  void AgentMap::markMap(int r, int c, char ch)
  {
    if (r >= 0 && r < height && c >= 0 && c < width)
      {
	map[r][c] = ch;
      }
  }

}    
