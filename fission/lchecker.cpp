#include <memory>

#include "lchecker.h"
#include "king.h"

#include "math.h"

namespace cs427_527
{
  LChecker::LChecker(int p, int r, int c)
    : Checker(p,r,c)
  {
	  player = p;
	  row = r;
	  col = c;
  }

  LChecker::~LChecker()
  {
  }

  int LChecker::getPlayer() const
  {
    return player;
  }

  std::string LChecker::toString() const
  {
    return (player == 0 ? "bb" : "rr");
  }

  bool LChecker::getLight() const
  {
  	return true;
  }
}
