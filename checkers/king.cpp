#include <algorithm>
#include <cctype>

#include "king.h"
#include "checker.h"

namespace cs427_527
{
  King::King(int p, int r, int c)
    : Checker(p, r, c)
  {
  }

  King::~King()
  {
  }

  bool King::canMoveBackwards() const
  {
    // kings can move backwards
    return true;
  }

  bool King::checkPromote(const CheckerBoard& board, int toR, int toC) const
  {
    // kings are never promoted
    return false;
  }

  std::string King::toString() const
  {
    // convert base class's result to upper case
    std::string result = Checker::toString();
    std::transform(result.begin(), result.end(), result.begin(), toupper);
    return result;
  }
}

