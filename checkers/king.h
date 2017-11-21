#ifndef __KING_H__
#define __KING_H__

#include <string>

#include "checker.h"

namespace cs427_527
{
  class CheckerBoard;
  
  class King : public Checker
  {
  public:
    /**
     * Creates a king owned by the given player at the given position.
     *
     * @param p 0 or 1
     * @param r a nonnegative integer
     * @param c a nonnegative integer
     */
    King(int p, int r, int c);

    /**
     * Destroys this king.
     */
    ~King();

    /**
     * Returns a printable representation of this checker.
     *
     * @return a printable representation of this checker
     */
    std::string toString() const override;

  protected:
    /**
     * Returns whether this checker can move backwards.
     *
     * @return true if and only if this checker can move backwards
     */
    bool canMoveBackwards() const override;

    /**
     * Determines if this checker is promoted if moving to the given
     * location.
     *
     * @param board the board this checker is on
     * @param toR a row on that board
     * @param toC a column on that board
     * @return true if this checker is promoted
     */
    bool checkPromote(const CheckerBoard& board, int toR, int toC) const override;

  };
}
#endif
