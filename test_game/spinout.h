/*
 * spinout.h
 *
 *      Author: jerome
 */

#ifndef __SPINOUT_H__
#define __SPINOUT_H__

#include "puzzle.h"

using namespace std;


namespace cs427_527
{
	class SpinOut : public Puzzle
	{
	public:
	  static const int SIZE = 7; 
    /**
	     * Creates a spinout object.
	     */
		SpinOut();

		/**
		 * Creates a spinout object with param.
		 */
		SpinOut(const std::string& s);

		/**
		 *  Destroys a spinout object..
		 */
		~SpinOut();

		/**
		 *  Takes an integer between 0 and 6
		 *  and determine whether is legal.
		 */
		virtual PuzzleMove* readMove(istringstream& input);
        virtual PuzzleMove* readMove(istream& input);
		virtual bool isLegalMove(PuzzleMove *curMove) const;

		friend ostream& operator<<(ostream& output, const SpinOut& obj);
		virtual void print(ostream& output) const;


		/**
		 * 	Rotates the indicated disk if the
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

		/**
		 * 	Returns a string representation of
		 * 	the current object.
		 */
		string toString() const;

	private:
		char oriSeq[SIZE+1];
		char currSeq[SIZE+1];
		int totalCounts;


	};
}



#endif /* SPINOUT_H_ */
