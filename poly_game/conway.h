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
		bool isLegalMove(int fromR, int fromC, int toR, int toC) const;

		/**
		 * 	Makes the move if the
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
