#ifndef CONWAY_H_
#define CONWAY_H_

#include <istream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

namespace cs427_527
{
	class Conway
	{
	public:
	    /**
	     * Creates an empty to-do list.
	     */
		Conway();

		/**
		 * Creates an empty to-do list.
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
		 *  Destroys a to-do list.
		 */
		~Conway();

		Conway& Conway::operator=(const Conway &rhs);
		Conway& Conway::operator=(Conway &&rhs);
		/**
		 *  Takes an integer between 0 and 6
		 *  and determine whether is legal.
		 */
		bool isLegalMove(int fromR, int fromC, int toR, int toC) const;

		/**
		 * 	Rotates the indicated disk if the
		 * 	move is legal.
		 */
		void makeMove(int fromR, int fromC, int toR, int toC);

		/**
		 * 	Counts the total moves.
		 */
		int totalMoves() const;

		/**
		 * 	Determines if the current object
		 * 	is in its solved configuration.
		 */
		bool isSolved() const;

	private:
		int rowNum,colNum;
		char** ary;
		int totalCounts;


	};
}




#endif /* CONWAY_H_ */
