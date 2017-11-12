/*
 * spinout.h
 *
 *      Author: jerome
 */

#ifndef __SPINOUT_H__
#define __SPINOUT_H__

#include <iostream>
#include <string>
#include <sstream>

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
		bool isLegalMove(int i) const;

		/**
		 * 	Rotates the indicated disk if the
		 * 	move is legal.
		 */
		void makeMove(int i);

		/**
		 * 	Counts the total moves.
		 */
		int totalMoves() const;

		/**
		 * 	Determines if the current object
		 * 	is in its solved configuration.
		 */
		bool isSolved() const;

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
