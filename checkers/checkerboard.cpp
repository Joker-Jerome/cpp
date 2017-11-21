#include <vector>
#include <memory>
#include <iostream>
#include <sstream>

#include "checkerboard.h"
#include "checker.h"

#include "math.h"

namespace cs427_527
{
  CheckerBoard::CheckerBoard()
    : board(8, std::vector<std::shared_ptr<Checker>>(8, nullptr)),
      width(8),
      height(8),
      turn(0),
      jumping(nullptr)
  {
    for (int r = 0; r < 3; r++)
      {
	for (int c = r % 2; c < width; c += 2)
	  {
	    board[r][c] = std::make_shared<Checker>(0, r, c);
	  }
      }

    for (int r = height - 3; r < height; r++)
      {
	for (int c = r % 2; c < width; c += 2)
	  {
	    board[r][c] = std::make_shared<Checker>(1, r, c);
	  }
      }
  }

  CheckerBoard::~CheckerBoard()
  {
  }
  
  int CheckerBoard::getWidth() const
  {
    return width;
  }

  int CheckerBoard::getHeight() const
  {
    return height;
  }

  std::shared_ptr<Checker> CheckerBoard::getPiece(int r, int c)
  {
    if (inBounds(r, c))
      {
	return board[r][c];
      }
    else
      {
	return nullptr;
      }
  }

  std::shared_ptr<const Checker> CheckerBoard::getPiece(int r, int c) const
  {
    if (inBounds(r, c))
      {
	return board[r][c];
      }
    else
      {
	return nullptr;
      }
  }

  void CheckerBoard::removePiece(int r, int c)
  {
    if (inBounds(r, c))
      {
	board[r][c] = nullptr;
      }
  }

  void CheckerBoard::placePiece(int r, int c, std::shared_ptr<Checker> p)
  {
    if (inBounds(r, c))
      {
	board[r][c] = p;
      }
  }

  CheckerBoard::Color CheckerBoard::getBoardColor(int r, int c) const
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

  bool CheckerBoard::isLegalMove(int fromR, int fromC, int toR, int toC) const
  {
    if (!inBounds(fromR, fromC) || !inBounds(toR, toC))
      {
	return false;
      }
    
    if (jumping != nullptr)
      {
	// in the middle of a sequence of jumps
	return (jumping == getPiece(fromR, fromC)
		&& jumping->isLegalMove(*this, toR, toC)
		&& iabs(fromR - toR) > 1);
      }
    else
      {
	// check if jump is available
	int distance = findLongestMove();
	
	// move is legal if is moves current player's checker legally
	std::shared_ptr<const Checker> moving = getPiece(fromR, fromC);
	return (imax(iabs(fromR - toR), iabs(fromC - toC)) == distance
		&& moving != nullptr
		&& moving->getPlayer() == turn
		&& moving->isLegalMove(*this, toR, toC));
      }
  }

  int CheckerBoard::findLongestMove() const
  {
    int longest = 0;
    for (int fromR = 0; fromR < height; fromR++)
      {
	for (int fromC = 0; fromC < width; fromC++)
	  {
	    if (getPiece(fromR, fromC) != nullptr
		&& getPiece(fromR, fromC)->getPlayer() == turn)
	      {
		longest = imax(longest, findLongestMove(fromR, fromC));
	      }
	  }
      }
    return longest;
  }

  int CheckerBoard::findLongestMove(int fromR, int fromC) const
  {
    int longest = 0;
    for (int toR = 0; toR < height; toR++)
      {
	for (int toC = 0; toC < width; toC++)
	  {
	    if (distance(fromR, fromC, toR, toC) > longest
		&& getPiece(fromR, fromC)->isLegalMove(*this, toR, toC))
	      {
		longest = distance(fromR, fromC, toR, toC);
	      }
	  }
      }
    return longest;
  }

  void CheckerBoard::makeMove(int fromR, int fromC, int toR, int toC)
  {
    if (isLegalMove(fromR, fromC, toR, toC))
      {
	std::shared_ptr<Checker> moving = getPiece(fromR, fromC);
	moving->makeMove(*this, toR, toC);

	// check if further jumps available
	if (distance(fromR, fromC, toR, toC) > 1
	    && moving == getPiece(toR, toC)
	    && findLongestMove(toR, toC) > 1)
	  {
	    jumping = moving;
	  }
	else
	  {
	    // change turn
	    turn = (turn + 1) % 2;
	    jumping = nullptr;
	  }
      }
  }

  int CheckerBoard::getCurrentPlayer() const
  {
    return turn;
  }

  bool CheckerBoard::gameOver() const
  {
    // game is over if no moves for current player
    return findLongestMove() == 0;
  }

  std::string CheckerBoard::toString() const
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

  bool CheckerBoard::inBounds(int r, int c) const
  {
    return r >= 0 && r < height && c >= 0 && c < width;
  }
  
  std::ostream& operator<<(std::ostream& os, const CheckerBoard &board)
  {
    return os << board.toString();
  }
}

