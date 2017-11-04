#include <string>
#include <sstream>

#include <ctime>
#include <cstdlib>

#include "die.h"

namespace cs427_527
{
  Die::Die(int s)
    : numSides(s)
  {
    if (numSides < 1)
      {
	std::ostringstream os;
	os << "number of sides must be positive: " << numSides;
	throw os.str();
      }

    roll();
  }

  void Die::roll()
  {
    numShowing = (rand() % numSides) + 1; // not quite uniform, but whatevs
  }

  int Die::getNumber() const
  {
    return numShowing;
  }

  std::ostream& operator<<(std::ostream& os, const Die& die)
  {
    return os << die.getNumber();
  }
}
