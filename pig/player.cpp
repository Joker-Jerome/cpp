#include <string>

#include "player.h"

namespace cs427_527
{
  Player::Player(const std::string& n)
    : name(n)
  {
  }

  Player::~Player()
  {
  }
  
  const std::string& Player::getName() const
  {
    return name;
  }

  void Player::acknowledge() const
  {
  }
  
}
