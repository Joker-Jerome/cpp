#include <memory>

#include "piece.h"
#include "pieceboard.h"
#include "math.h"

namespace cs427_527
{
  Piece::Piece(int p, int r, int c)
    : player(p),
      row(r),
      col(c)
  {
  }

  Piece::~Piece()
  {
  }

  bool Piece::isLegalMove(const PieceBoard& board, int toR, int toC) const
  {
	  return 0;

  }


  bool Piece::isLegalDestination(const PieceBoard& board, int toR, int toC) const
  { 
    // destination must be empty
    return 0;
  }
  
  void Piece::makeMove(PieceBoard& board, int toR, int toC)
  {

  }

  std::shared_ptr<Piece> Piece::promote() const
  {
    return nullptr;
  }
  
  bool Piece::checkPromote(const PieceBoard& board, int toR, int toC) const
  {
    return 0;

  }
  
  void Piece::jump(PieceBoard& board, int toR, int toC) const
  {

  }

  bool Piece::canMoveBackwards() const
  {
    return 0;
  }

  bool Piece::isLegalDistance(int d) const
  {
    return d == 1 || d == 2;
  }
  
  bool Piece::isLegalDirection(int toR, int toC) const
  {
    // direction legal if (can move backwards or moving forward) and diagonal
    return 0;
  }

  bool Piece::isLegalJump(const PieceBoard& board, int toR, int toC) const
  {
    // get piece in middle
    return 0;
  }

  int Piece::getPlayer() const
  {
    return player;
  }

  std::string Piece::toString() const
  {
    return (player == 0 ? "bb" : "rr");
  }
}
