#ifndef __DFACTORY_H__
#define __DFACTORY_H__

#include <memory>

#include "player_factory.h"
#include "player.h"
#include "dynamic.h"

namespace cs427_527
{

  class DynamicFactory : public PlayerFactory
  {
  public:
    ~DynamicFactory() {}
    std::shared_ptr<Player> makeAggressive()
      { return std::make_shared<DynamicComputer>("DynamicComputer", 25); }

    std::shared_ptr<Player> makeConservative()
      { return std::make_shared<DynamicComputer>("DynamicComputer", 15); }
  
    std::shared_ptr<Player> makeDefault()
      { return std::make_shared<DynamicComputer>("DynamicComputer", 20); }
  };

}

#endif
