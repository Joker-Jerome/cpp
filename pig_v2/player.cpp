#include <string>

#include "player.h"
#include "strategy.h"

namespace cs427_527
{
  Player::Player(std::string n, Strategy *s)
    : name(n),
      strategy(s)
  {
  }

  Player::~Player()
  {
    delete strategy;
  }
  
  const std::string& Player::getName() const
  {
    return name;
  }

  bool Player::rollAgain(std::vector<int> scores, int turnTotal, int target)
  {
    return strategy->rollAgain(scores, turnTotal, target);
  }

  void Player::acknowledge() const
  {
  }
  
}
