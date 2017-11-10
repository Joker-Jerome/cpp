#ifndef __HUMAN_H__
#define __HUMAN_H__

#include <string>

#include <vector>

#include "player.h"

namespace cs427_527
{
  class Human : public Player
  {
  public:
    /**
     * Creates a human player with the given name.
     *
     * @param n a string
     */
    Human(const std::string& n);

    /**
     * Destroys this player.
     */
    ~Human();

    /**
     * Uses standard input and output to ask the user whether they
     * want to roll again.
     *
     * @param scores a non-empty vector of nonnegative integers
     * @param turnTotal a positive integer
     * @param target a positive integer
     * @return true if and only if this player wants to roll again
     */
    bool rollAgain(std::vector<int> scores, int turnTotal, int target);

    /**
     * Pauses until a newline appears on standard input.
     */
    void acknowledge() const;
    
  private:
  };
}

#endif
