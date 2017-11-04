#ifndef __MERLIN_H__
#define __MERLIN_H__

#include <iostream>
#include <string>
#include <vector>

namespace cs427_527
{

class Merlin
{
 public:
  Merlin();
  Merlin(const std::string& s); 
  Merlin(std::istream& is);

  bool isLegalMove(const std::string&) const;
  void makeMove(const std::string&);
  int totalMoves() const;
  bool isSolved() const;
  std::string toString() const;
  
  static const int DEFAULT_SIZE = 3;

  typedef std::string Move;
  
 private:
  std::vector<std::vector<bool>> board;
  int moveCount;
};

std::ostream& operator<<(std::ostream&, const Merlin&);

}

#endif
