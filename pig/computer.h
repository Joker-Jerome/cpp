#ifndef __COMPUTER_H__
#define __COMPUTER_H__

#include <string>

#include <vector>

#include "player.h"

namespace cs427_527
{
  class Computer : public Player
  {
  public:
    /**
     * Creates a computer player with the given name that rolls again
     * until the turn total is at least the given threshold.
     *
     * @param n a string
     * @param t a positive integer
     */
    Computer(const std::string& n, int t);

    /**
     * Destroys this player.
     */
    ~Computer();

    /**
     * Determines if this player wants to roll again.  This implementation
     * returns true if and only if the turn total is less than this
     * player's threshold.
     *
     * @param scores a non-empty vector of nonnegative integers
     * @param turnTotal a positive integer
     * @param target a positive integer
     * @return true if and only if this player wants to roll again
     */
    bool rollAgain(std::vector<int> scores, int turnTotal, int target);

  private:
    int threshold;
  };
}

#endif
