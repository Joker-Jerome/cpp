#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <string>

#include <vector>

namespace cs427_527
{
  class Player
  {
  public:
    /**
     * Creates a player with the given name.
     *
     * @param n a strng
     */
    Player(const std::string& n);

    /**
     * Destroys this player.
     */
    virtual ~Player();

    /**
     * Returns this player's name.
     *
     * @return this player's name
     */
    const std::string& getName() const;

    /**
     * Determines if this player wants to roll again in the given
     * situation.  The input is the players' scores starting with this
     * one, the current turn total, and the score needed to win the game.
     *
     * @param scores a non-empty vector of nonnegative integers
     * @param turnTotal a positive integer
     * @param target a positive integer
     * @return true if and only if this player wants to roll again
     */
    virtual bool rollAgain(std::vector<int> scores, int turnTotal, int target) = 0;

    /**
     * Allows this player to pause until they have acknowledged
     * the current state of the game.  The default implementation does
     * nothing.
     */
    virtual void acknowledge() const;

    
  private:
    std::string name;
  };
}

#endif
