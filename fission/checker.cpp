#include <memory>

#include "checker.h"
#include "checkerboard.h"

#include "math.h"

namespace cs427_527
{
  Checker::Checker(int p, int r, int c)
    : Piece(p,r,c)
  {
	  player = p;
	  row = r;
	  col = c;
  }

  Checker::~Checker()
  {
  }

  bool Checker::isLegalMove(const PieceBoard& board, int toR, int toC) const
  {
    //std::cout << "checker!" << std::endl;

	//int dist = distance(row, col, toR, toC);
//	std::cout << row << col << toR <<toC << "\t" << std::endl;
//	std::cout << board.inBounds(row, col) << std::endl;
//	std::cout << board.inBounds(toR, toC) << std::endl;
//	std::cout << isLegalDirection(board, toR, toC) << std::endl;
//	std::cout << isLegalDestination(board, toR, toC) << std::endl;

    return (board.inBounds(row, col) && board.inBounds(toR, toC)
	    && isLegalDirection(board, toR, toC)
	    && isLegalDestination(board, toR, toC));
  }
  bool Checker::isClosePiece(const PieceBoard& board, int toR, int toC) const
    {
	  	int rowNext;
		int colNext;
		// calculate the next piece
		if (toR == row) { rowNext = toR; } else {
			rowNext = toR + (toR - row)/iabs(toR - row);
		}
		if (toC == col) { colNext = toC; } else {
			colNext = toC + (toC - col)/iabs(toC - col);
		}
  	if (board.inBounds(rowNext, colNext)) {
  		if (board.getPiece(rowNext, colNext) != nullptr) {
  			return true;
  		}
  	}
  	return false;
    }

    // check if the piece is stopped by another piece
  bool Checker::isStopOnEdge(const PieceBoard& board, int toR, int toC) const
    {
  	int rowNext;
  	int colNext;
  	// calculate the next piece
  	if (toR == row) {
  		rowNext = toR;
  	} else {
  		rowNext = toR + (toR - row)/iabs(toR - row);
  	}
  	if (toC == col) {
  		 colNext = toC;
  	} else {
  		colNext = toC + (toC - col)/iabs(toC - col);
  	}
  	if (!board.inBounds(rowNext, colNext)) {
  		return true;
  	}
  	return false;
    }

  bool Checker::isLegalDestination(const PieceBoard& board, int toR, int toC) const
  { 
    // destination must be empty
	// the path should be empty
    return((isStopOnEdge(board, toR, toC))|| (isClosePiece(board, toR, toC)));
  }
  
  // check if the piece is stopped by edge


  void Checker::makeMove(PieceBoard& board, int toR, int toC)
  {
    //if (isLegalMove(board, toR, toC))
      //{
	// get a shared pointer to this piece (consider what happens
	// after remove without this)
	std::shared_ptr<Piece> self = board.getPiece(row, col);

	if (isStopOnEdge(board, toR, toC)) {
		board.removePiece(row, col);
		// update the location
		row = toR;
		col = toC;
		board.placePiece(toR, toC, self);
	} else if (isClosePiece(board, toR, toC)) {
		// remove this piece from original location
		board.removePiece(row, col);

		// get the next piece
		int rowNext;
		int colNext;
		// calculate the next piece
		if (toR == row) {
			rowNext = toR;
		} else {
			rowNext = toR + (toR - row)/iabs(toR - row);
		}
		if (toC == col) {
			 colNext = toC;
		} else {
			colNext = toC + (toC - col)/iabs(toC - col);
		}

		// check for the light piece
		if (board.getPiece(rowNext, colNext)->getLight()){
			board.removePiece(rowNext, colNext);

		} else {
			for (int i = toR-1;i < toR+2;i++){
				for (int j = toC-1; j < toC+2;j++) {
					if (board.inBounds(i,j)) {
						if (board.getPiece(i,j) != nullptr) {
							board.removePiece(i,j);
					}

					}
				}
			}
		}
	}


  }



  bool Checker::isLegalDistance(int d) const
  {
    return d == 1 || d == 2;
  }
  
  bool Checker::isLegalDirection(const PieceBoard& board, int toR, int toC) const
  {
    // direction legal if (can move backwards or moving forward) and diagonal
	bool sameCol = (col == toC) && (row != toR);
	bool sameRow = (row == toR) && (col != toC);
	bool orth = iabs(row - toR) == iabs(col - toC);
	bool clearCol = true;
	bool clearRow = true;
	bool clearOrth = true;
	// same column
	if (sameCol) {
		if (row < toR) {
			for (int i = row + 1; i< toR + 1; i++){
				if (board.getPiece(i, col) != nullptr) {
					clearCol = false;
					break;
				}
			}
		} else {
			for (int i = row - 1; i> toR - 1; i--){
				if (board.getPiece(i, col) != nullptr) {
					clearCol = false;
					break;
				}
			}
		}
	}
	// same row
	if (sameRow) {
			if (col < toC) {
				for (int i = col + 1; i< toC + 1; i++){
					if (board.getPiece(row, i) != nullptr) {
						clearRow = false;
						break;
					}
				}
			} else {
				for (int i = col - 1; i> toC - 1; i--){
					if (board.getPiece(row, i) != nullptr) {
						clearRow = false;
						break;
					}
				}
			}
	}
	// orth
	if (orth) {
		int rowMove;
		int colMove;
		// calculate the move
		if (toR == row) {
			rowMove = 0;
		} else {
			rowMove = (toR - row)/iabs(toR - row);
		}
		if (toC == col) {
			 colMove = 0;
		} else {
			colMove = (toC - col)/iabs(toC - col);
		}
		std::cout << rowMove << std::endl;
		std::cout << colMove << std::endl;

		for (int i = toR,j = toC; i != row && j != col ; i = i - rowMove, j = j - colMove){
			//std::cout << i << j <<std::endl;
			if (board.getPiece(i, j) != nullptr) {
				clearOrth = false;
				break;
			}
		}

	}
    return(((sameCol && clearCol) || (sameRow && clearRow) || (orth && clearOrth)));
  }

  int Checker::getPlayer() const
  {
    return player;
  }

  std::string Checker::toString() const
  {
    return (player == 1 ? "BB" : "RR");
  }

  bool Checker::getLight() const
  {
	return false;
  }
}
