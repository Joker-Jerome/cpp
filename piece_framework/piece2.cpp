#include <memory>

#include "piece.h"
#include "pieceboard.h"
#include "king.h"

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
    int dist = distance(row, col, toR, toC);
    return (board.inBounds(row, col) && board.inBounds(toR, toC)
	    && isLegalDirection(toR, toC)
	    && isLegalDistance(dist)
	    && (dist == 1 || isLegalJump(board, toR, toC))
	    && isLegalDestination(board, toR, toC));
  }

  bool Piece::isLegalDestination(const PieceBoard& board, int toR, int toC) const
  { 
    // destination must be empty
    return board.getPiece(toR, toC) == nullptr;
  }
  
  void Piece::makeMove(PieceBoard& board, int toR, int toC)
  {
    if (isLegalMove(board, toR, toC))
      {
	// get a shared pointer to this piece (consider what happens
	// after remove without this)
	std::shared_ptr<Piece> self = board.getPiece(row, col);

	// remove this piece from original location
	board.removePiece(row, col);

	int dist = distance(row, col, toR, toC);
	if (dist > 1)
	  {
	    // handle jump
	    jump(board, toR, toC);
	  }

	// update location of this piece
	row = toR;
	col = toC;
	
	// check for promotion
	if (checkPromote(board, toR, toC))
	  {
	    // return a new King at the to location
	    board.placePiece(toR, toC, promote());
	  }
	else
	  {
	    board.placePiece(toR, toC, self);
	  }
      }
  }

  std::shared_ptr<Piece> Piece::promote() const
  {
    return std::make_shared<King>(player, row, col);
  }
  
  bool Piece::checkPromote(const PieceBoard& board, int toR, int toC) const
  {
    return ((player == 0 && toR == board.getHeight() - 1)
	    || (player == 1 && toR == 0));

  }
  
  void Piece::jump(PieceBoard& board, int toR, int toC) const
  {
    board.removePiece((row + toR) / 2, (col + toC) / 2);
  }

  bool Piece::canMoveBackwards() const
  {
    return false;
  }

  bool Piece::isLegalDistance(int d) const
  {
    return d == 1 || d == 2;
  }
  
  bool Piece::isLegalDirection(int toR, int toC) const
  {
    // direction legal if (can move backwards or moving forward) and diagonal
    return ((canMoveBackwards()
	     || (player == 0 && toR > row) || (player == 1 && toR < row))
	    && iabs(row - toR) == iabs(col - toC));
  }

  bool Piece::isLegalJump(const PieceBoard& board, int toR, int toC) const
  {
    // get piece in middle
    std::shared_ptr<const Piece> jumped = board.getPiece((toR + row) / 2, (toC + col) / 2);
    // jump legal if there is a piece belonging to other player
    return (jumped != nullptr && jumped->player != player);
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
