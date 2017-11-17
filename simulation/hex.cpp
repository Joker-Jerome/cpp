#include <cmath>

#include "hex.h"

namespace cs427_527
{

  Hex::Hex(int r, int c)
  {
    row = r;
    column = c;
  }

  int Hex::getColumn() const
  {
    return column;
  }

  int Hex::getRow() const
  {
    return row;
  }

  double Hex::getX() const
  {
    return column + (row % 2 == 0 ? 0.0 : 0.5);
  }

  double Hex::getY() const
  {
    return row * sqrt(3) / 2.0;
  }

  double Hex::distance(const Hex& other) const
  {
    double x1 = getX();
    double y1 = getY();
    double x2 = other.getX();
    double y2 = other.getY();

    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
  }

  bool Hex::isAdjacent(const Hex& other) const
  {
    double dist = distance(other);
    return dist > 0.0 && dist < 1.1; // 1.1 to account for inaccuracy of doubles
  }

  Hex Hex::closer(const Hex& other) const
  {
    double min = distance(other);
    Hex closest = *this;

    for (int dr = -1; dr <= 1; dr++)
      {
	for (int dc = -1; dc <= 1; dc++)
	  {
	    Hex cand(row + dr, column + dc);
	    if (isAdjacent(cand) && cand.distance(other) < min)
	      {
		min = cand.distance(other);
		closest = cand;
	      }
	  }
      }

    return closest;
  }

  Hex Hex::further(const Hex& other) const
  {
    double max = distance(other);
    Hex furthest = *this;

    for (int dr = -1; dr <= 1; dr++)
      {
	for (int dc = -1; dc <= 1; dc++)
	  {
	    Hex cand(row + dr, column + dc);
	    if (isAdjacent(cand) && cand.distance(other) > max)
	      {
		max = cand.distance(other);
		furthest = cand;
	      }
	  }
      }

    return furthest;
  }

  bool Hex::operator==(const Hex& rhs) const
  {
    return row == rhs.row && column == rhs.column;
  }

}
