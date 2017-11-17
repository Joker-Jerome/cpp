#ifndef __HEX_H__
#define __HEX_H__

namespace cs427_527
{

  class Hex
  {
  public:
    Hex(int r, int c);
    int getRow() const;
    int getColumn() const;
    double getX() const;
    double getY() const;
    double distance(const Hex& other) const;
    bool isAdjacent(const Hex& other) const;
    Hex closer(const Hex& other) const;
    Hex further(const Hex& other) const;

    bool operator==(const Hex &rhs) const;

  private:
    int row;
    int column;
  };

}
#endif
