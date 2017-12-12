#include <vector>
#include <memory>
#include <iostream>
#include <sstream>


#include "checkerboard.h"
#include "checker.h"
#include "lchecker.h"

#include "math.h"

namespace cs427_527
{
  CheckerBoard::CheckerBoard()
    : board(8, std::vector<std::shared_ptr<Piece>>(8, nullptr)),
      width(8),
      height(8),
      turn(0),
      jumping(nullptr)
  {

    for (int r = 0; r < height; r++)
      {
    	for (int c = r % 2; c < width; c += 2)
	  {
	    board[r][c] = std::make_shared<Checker>(0, r, c);
	  }
      }

    for (int r = 0; r < height; r++)
      {
	for (int c = 1-(r % 2); c < width; c += 2)
	  {
	    board[r][c] = std::make_shared<Checker>(1, r, c);

	  }
      }
    for (int r = 0; r < height; r++) {
    		board[r][0] = nullptr;
		board[r][width-1] = nullptr;
    }
    for (int c = 1; c < width-1; c++) {
        	board[0][c] = nullptr;
    		board[height-1][c] = nullptr;
    }
    for (int r = height/2 - 2, i = 1 ; r > 0; r--, i++){
		for (int j = 0; j < i; j++) {
			board[r][1 + j] = nullptr;
			board[r][width - 2 - j] = nullptr;
		}

    }
    for (int r = height/2 + 1, i = 1 ; r < height - 1; r++, i++){
    		for (int j = 0; j < i; j++) {
			board[r][1 + j] = nullptr;
			board[r][width - 2 - j] = nullptr;
		}
    }
    for (int i = 0; i < width; i++) {
    		int count = 0;
    		for (int j = 0; j < height; j++) {
    			if (board[i][j] != nullptr) {
    				count++;
    			}
    		}
    		if (count == 4) {
    			for(int h = height/2 - 2; h < height/2 + 2; h++) {
    				//Piece tmp_piece = board[i][h];
    				int tmp_player = board[h][i]->getPlayer();
    				board[h][i] = std::make_shared<LChecker>(tmp_player, h, i);
    			}
    		}
    }

  }

  CheckerBoard::CheckerBoard(int col,int row)
      : board(row, std::vector<std::shared_ptr<Piece>>(col, nullptr)),
        width(col),
        height(row),
        turn(0),
        jumping(nullptr)
    {
	  int flag1 = (height/2) % 2;
	  int flag2 = (width/2) % 2;
	  int flag3 = (flag1 + flag2) %2;
      for (int r = 0; r < height; r++)
        {
      	for (int c = r % 2; c < width; c += 2)
  	  {
  	    board[r][c] = std::make_shared<Checker>(0 + flag3, r, c);
  	  }
        }

      for (int r = 0; r < height; r++)
        {
  	for (int c = 1-(r % 2); c < width; c += 2)
  	  {
  	    board[r][c] = std::make_shared<Checker>(1 - flag3, r, c);

  	  }
        }
      for (int r = 0; r < height; r++) {
      		board[r][0] = nullptr;
  		board[r][width-1] = nullptr;
      }
      for (int c = 1; c < width-1; c++) {
          	board[0][c] = nullptr;
      		board[height-1][c] = nullptr;
      }

      for (int r = height/2 - 2, i = 1 ; r > 0; r--, i++){
  		for (int j = 0; j < i; j++) {
  			board[r][1 + j] = nullptr;
  			board[r][width - 2 - j] = nullptr;
  		}

      }

      for (int r = height/2 + 1, i = 1 ; r < height - 1; r++, i++){
      		for (int j = 0; j < i; j++) {
  			board[r][1 + j] = nullptr;
  			board[r][width - 2 - j] = nullptr;
  		}
      }

      for (int i = 0; i < width; i++) {
      		int count = 0;
      		for (int j = 0; j < height; j++) {
      			if (board[j][i] != nullptr) {
      				count++;
      			}
      		}


      		if (count == 4) {
      			for(int h = height/2 - 2; h < height/2 + 2; h++) {
      				//Piece tmp_piece = board[i][h];
      				int tmp_player = board[h][i]->getPlayer();
      				board[h][i] = std::make_shared<LChecker>(tmp_player, h, i);
      			}
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

  std::shared_ptr<Piece> CheckerBoard::getPiece(int r, int c)
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

  std::shared_ptr<const Piece> CheckerBoard::getPiece(int r, int c) const
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

  void CheckerBoard::placePiece(int r, int c, std::shared_ptr<Piece> p)
  {
    if (inBounds(r, c))
      {
	board[r][c] = p;
      }
  }

  PieceBoard::Color CheckerBoard::getBoardColor(int r, int c) const
  {
    if (r % 2 == c % 2)
      {
	return PieceBoard::Color::RED;
      }
    else
      {
	return PieceBoard::Color::BLACK;
      }
  }

  bool CheckerBoard::isLegalMove(int fromR, int fromC, int toR, int toC) const
  {
    if (!inBounds(fromR, fromC) || !inBounds(toR, toC))
      {
    		return false;
      }

	// move is legal if is moves current player's checker legally
	std::shared_ptr<const Piece> moving = getPiece(fromR, fromC);
	return (moving != nullptr
		&& moving->getPlayer() == turn
		&& moving->isLegalMove(*this, toR, toC));

  }



  void CheckerBoard::makeMove(int fromR, int fromC, int toR, int toC)
  {
    if (isLegalMove(fromR, fromC, toR, toC))
      {
    		std::shared_ptr<Piece> moving = getPiece(fromR, fromC);
    		moving->makeMove(*this, toR, toC);
    		this->turn = 1 - turn;
      }
  }

  int CheckerBoard::getCurrentPlayer() const
  {
    return turn;
  }

  bool CheckerBoard::gameOver() const
  {
    // game is over if no moves for current player
	int countCurrent = 0;
	int countOpponent = 0;
	int currentPlayer = getCurrentPlayer();
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (getPiece(i,j) != nullptr) {
				if (getPiece(i,j)->getPlayer() == currentPlayer) {
					countCurrent++;
				} else if (getPiece(i,j)->getPlayer() == (1-currentPlayer)) {
					countOpponent++;
				}
			}

		}
	}
	if (countCurrent == 0 && countOpponent > 0) {
		return true;
	}
    return false;
  }

  bool CheckerBoard::isDraw() const
    {
      // game is over if no moves for current player
  	int count = 0;
  	for (int i = 0; i < height; i++) {
  		for (int j = 0; j < width; j++) {
  			if (getPiece(i,j) != nullptr) {
  				count++;
  			}


  		}
  	}
  	if (count == 0 ) {
  		return true;
  	}
    		return false;
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
		if (getBoardColor(r, c) == PieceBoard::Color::RED)
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
  
}

