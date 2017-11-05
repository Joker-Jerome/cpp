#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <string>

#include <vector>

namespace cs427_527
{
  class Strategy;
  
  class Player
  {
  public:
    Player(std::string name, Strategy *strat);
    virtual ~Player();

    const std::string& getName() const;
    
    bool rollAgain(std::vector<int> scores, int turnTotal, int target);

    virtual void acknowledge() const;

  private:
    std::string name;
    Strategy *strategy;
  };
}

#endif
