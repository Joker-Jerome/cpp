#ifndef __FACTORY_H__
#define __FACTORY_H__

#include <memory>

#include "puzzle.h"

namespace cs427_527
{
  
  class PlayerFactory
  {
  public:
    virtual ~PlayerFactory() {}
    virtual std::shared_ptr<Player> makeAggressive() = 0;
    virtual std::shared_ptr<Player> makeConservative() = 0;
    virtual std::shared_ptr<Player> makeDefault() = 0;
  };

}
#endif
