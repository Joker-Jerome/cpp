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
		//Puzzle(istream& s);

		/**
		 * copy constructor.
		 */
		//Puzzle(const Puzzle& obj);
		/**
		 * move constructor.
		 */
		//Puzzle(Puzzle &&rhs);

		/**
		 *  Destroys a puzzle object.
		 */
		virtual ~Puzzle();

//		Puzzle& operator=(const Puzzle &rhs);
//		Puzzle& operator=(Puzzle &&rhs);
		friend  ostream& operator<<(ostream& output, const Puzzle& obj);
		virtual void print(ostream& output) const;

		/**
		 *  Takes four integers 
		 *  and determines whether the move is legal.
		 */
        virtual PuzzleMove* readMove(istringstream& input);
        virtual PuzzleMove* readMove(istream& input);

		virtual bool isLegalMove(PuzzleMove *curMove) const;

		/**
		 * 	Makes the move if the
		 * 	move is legal.
		 */
		virtual void makeMove(PuzzleMove *curMove);

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
//		int rowNum,colNum;
//		char** ary;
		int totalCounts;


	};
}




#endif /* CONWAY_H_ */
