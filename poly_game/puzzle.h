#ifndef __PUZZLE_H__
#define __PUZZLE_H__

#include <istream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include "puzzle_move.h"

using namespace std;
using cs427_527::PuzzleMove;

namespace cs427_527
{
	class Puzzle
	{
	public:
	    /**
	     * Creates a puzzle object.
	     */
		Puzzle();

		/**
		 * Creates a puzzle object
		 */
		Puzzle(istream& s);

		/**
		 * copy constructor.
		 */
		Puzzle(const Puzzle& obj);
		/**
		 * move constructor.
		 */
		Puzzle(Puzzle &&rhs);

		/**
		 *  Destroys a puzzle object.
		 */
		~Puzzle();

		Puzzle& operator=(const Puzzle &rhs);
		Puzzle& operator=(Puzzle &&rhs);
		friend ostream& operator<<(ostream& output, const Puzzle& obj);
		/**
		 *  Takes four integers 
		 *  and determines whether the move is legal.
		 */
    virtual PuzzleMove readMove(istringstream& input);
		virtual bool isLegalMove(int fromR, int fromC, int toR, int toC) const;

		/**
		 * 	Makes the move if the
		 * 	move is legal.
		 */
		virtual void makeMove(int fromR, int fromC, int toR, int toC);

		/**
		 * 	Counts the total moves.
		 */
		virtual int totalMoves() const;

		/**
		 * 	Determines if the current object
		 * 	is in its solved configuration.
		 */
		virtual bool isSolved() const;

	private:
		int rowNum,colNum;
		char** ary;
		int totalCounts;


	};
}




#endif /* CONWAY_H_ */
