#ifndef __LCHECKER_H__
#define __LCHECKER_H__

#include <string>
#include <memory>

#include "checker.h"
#include "checkerboard.h"

namespace cs427_527
{
  class PieceBoard;

  /**
   * A checker.
   */
  class LChecker : public Checker
  {
  public:
    /**
     * Creates a checker owned by the given player at the given position.
     *
     * @param p 0 or 1
     * @param r a nonnegative integer
     * @param c a nonnegative integer
     */
    LChecker(int p, int r, int c);

    /**
     * Destroys this checker.
     */
    virtual ~LChecker();



    /**
     * Returns the index of the player this checker belongs to.
     *
     * @return the index of the owner
     */
    virtual int getPlayer() const;

    /**
     * Returns a printable representation of this checker.
     *
     * @return a printable representation of this checker
     */
    virtual std::string toString() const;
    
    virtual bool getLight() const;

  };
}

#endif
