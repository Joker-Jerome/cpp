#ifndef __WORLD_H__
#define __WORLD_H__

#include <vector>
#include <iostream>

#include "agent.h"
#include "patient.h"
#include "hex.h"

namespace cs427_527
{

  class World
  {
  public:
    World(int size, int numPrey, int numPredators, int numFood);
    ~World();

    int getWidth() const;
    int getHeight() const;
    Hex randomLocation() const;
    void update();
    void actOn(Patient& p) const;
    void printTo(std::ostream& os) const;

  private:
    int width;
    int height;
    std::vector<Agent *> agents;
  };

  std::ostream& operator<<(std::ostream& os, const World& w);

  class AgentMap : public Patient
  {
  public:
    AgentMap(int w, int h);
    virtual ~AgentMap();

    void acceptAction(const Predator& p);
    void acceptAction(const Prey& p);
    void acceptAction(const Food& f);
    void acceptAction(const Scent& s);

    void printTo(std::ostream& os) const;

  private:
    void markMap(int r, int c, char ch);

    char **map;
    int width;
    int height;
  };
  
}
#endif
