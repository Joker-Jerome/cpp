#ifndef __SPINOUT_H__
#define __SPINOUT_H__

#include <iostream>
#include <string>

namespace cs427_527
{
class SpinOut
{
 public:
  SpinOut();
  SpinOut(const std::string& s);
  SpinOut(std::istream& is);
  
  bool isLegalMove(int i) const;
  void makeMove(int i);
  int totalMoves() const;
  bool isSolved() const;
  void toCString(char *s) const;
  std::string toString() const;
  
  static const int SIZE = 7;
  static const char VCHAR = '/';
  static const char HCHAR = '-';
  enum Direction {vertical, horizontal};

  typedef int Move;
  
 private:
  int moveCount;
  Direction pieces[SIZE];
};

 std::ostream& operator<<(std::ostream& os, const SpinOut& game);
 
}
#endif
