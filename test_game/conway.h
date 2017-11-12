#ifndef CONWAY_H_
#define CONWAY_H_

#include "puzzle.h"

using namespace std;

namespace cs427_527
{
	class Conway: public Puzzle
	{
	public:
	    /**
	     * Creates a conway object.
	     */
		Conway();

		/**
		 * Creates a conway object
		 */
		Conway(istream& s);

		/**
		 * copy constructor.
		 */
		Conway(const Conway& obj);
		/**
		 * move constructor.
		 */
		Conway(Conway &&rhs);

		/**
		 *  Destroys a conway object.
		 */
		~Conway();

		Conway& operator=(const Conway &rhs);
		Conway& operator=(Conway &&rhs);
		friend ostream& operator<<(ostream& output, const Conway& obj);
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
		int rowNum,colNum;
		char** ary;
		int totalCounts;


	};
}




#endif /* CONWAY_H_ */
