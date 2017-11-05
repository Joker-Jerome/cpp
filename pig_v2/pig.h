#ifndef __PIG_H__
#define __PIG_H__

#include <iostream>
#include <string>

#include <vector>

namespace cs427_527
{
  class Die;
  class Player;
  
  class PigGame
  {
  public:
    /**
     * @param t a positive integer
     */
    PigGame(Player *p1, Player *p2, int t);

    ~PigGame();
    
    /**
     * Plays one turn of this game.  The turn starts with the current
     * player and ends when that player wins, busts, or gives up control.
     */
    void playTurn();

    /**
     * Determines if the given roll is a bust.
     *
     * @param die a number between 1 and 6
     * @return true if and only if the given roll is a bust
     */
    bool busted(const Die& die) const;
    
    /**
     * Determines if this game is over.  This game is over if one player has
     * reached the target.
     *
     * @return true if and only if this game is over
     */
    bool gameOver() const;

    /**
     * Plays this game until it is over.
     */
    void playGame();

    /**
     * Returns a printable representation of this game.
     *
     * @return a printable representation of this game
     */
    std::string toString() const;
    
  private:
    /**
     * A vector of the players' names.
     */
    std::vector<Player *> players;

    /**
     * A vector of the players' scores.
     */
    std::vector<int> scores;

    /**
     * The score needed to win this game.
     */
    int target;

    /**
     * The 0-based index of the player whose turn it is in this game.
     */
    unsigned int turn;

    /**
     * The number of sides on the die to play with.
     */
    static const int NUM_SIDES = 6;
  };

  /**
   * Writes the given game to the given stream.
   *
   * @param os an output stream
   * @param game a game
   * @return the output stream
   */
  std::ostream& operator<<(std::ostream& os, const PigGame& game);
}

#endif
