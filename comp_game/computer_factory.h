#ifndef __COMPFACTORY_H__
#define __COMPFACTORY_H__

#include <memory>

#include "player_factory.h"
#include "player.h"
#include "computer.h"

namespace cs427_527
{

  class ComputerFactory : public PlayerFactory
  {
  public:
    ~ComputerFactory() {}
    std::shared_ptr<Player> makeAggressive() override
      { return std::make_shared<Computer>("Computer", 25); }

    std::shared_ptr<Player> makeConservative() override
      { return std::make_shared<Computer>("Computer", 15); }
  
    std::shared_ptr<Player> makeDefault() override
      { return std::make_shared<Computer>("Computer", 20); }
  };

}
#endif
