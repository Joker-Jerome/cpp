#include <vector>
#include <memory>
#include <iostream>
#include <sstream>

#include "pieceboard.h"
#include "piece.h"

#include "math.h"

namespace cs427_527
{
  PieceBoard::PieceBoard()
    : board(8, std::vector<std::shared_ptr<Piece>>(8, nullptr)),
      width(8),
      height(8),
      turn(0),
      jumping(nullptr)
  {
    for (int r = 0; r < 3; r++)
      {
	for (int c = r % 2; c < width; c += 2)
	  {
	    board[r][c] = std::make_shared<Piece>(0, r, c);
	  }
      }

    for (int r = height - 3; r < height; r++)
      {
	for (int c = r % 2; c < width; c += 2)
	  {
	    board[r][c] = std::make_shared<Piece>(1, r, c);
	  }
      }
  }

  PieceBoard::~PieceBoard()
  {
  }
  
  int PieceBoard::getWidth() const
  {
    return width;
  }

  int PieceBoard::getHeight() const
  {
    return height;
  }

  std::shared_ptr<Piece> PieceBoard::getPiece(int r, int c)
  {
    return nullptr;
  }

  std::shared_ptr<const Piece> PieceBoard::getPiece(int r, int c) const
  {

	return nullptr;

  }

  void PieceBoard::removePiece(int r, int c)
  {
    if (inBounds(r, c))
      {
	board[r][c] = nullptr;
      }
  }

  void PieceBoard::placePiece(int r, int c, std::shared_ptr<Piece> p)
  {
    if (inBounds(r, c))
      {
	board[r][c] = p;
      }
  }

  PieceBoard::Color PieceBoard::getBoardColor(int r, int c) const
  {
    if (r % 2 == c % 2)
      {
	return Color::RED;
      }
    else
      {
	return Color::BLACK;
      }
  }

  bool PieceBoard::isLegalMove(int fromR, int fromC, int toR, int toC) const
  {
    if (!inBounds(fromR, fromC) || !inBounds(toR, toC))
      {
	return false;
      }
    
    return true;
  }



  void PieceBoard::makeMove(int fromR, int fromC, int toR, int toC)
  {

  }

  int PieceBoard::getCurrentPlayer() const
  {
    return turn;
  }

  bool PieceBoard::gameOver() const
  {
    return 0;
  }

  std::string PieceBoard::toString() const
  {
    std::ostringstream os;

    for (int r = 0; r < height; r++)
      {
	for (int c = 0; c < width; c++)
	  {
	    if (getPiece(r, c) == nullptr)
	      {
		if (getBoardColor(r, c) == Color::RED)
		  {
		    os << "..";
		  }
		else
		  {
		    os << "  ";
		  }
	      }
	    else
	      {
		os << getPiece(r, c)->toString();
	      }
	  }
	os << std::endl;
      }

    return os.str();
  }

  bool PieceBoard::inBounds(int r, int c) const
  {
    return r >= 0 && r < height && c >= 0 && c < width;
  }
  
  std::ostream& operator<<(std::ostream& os, const PieceBoard &board)
  {
    return os << board.toString();
  }
}

