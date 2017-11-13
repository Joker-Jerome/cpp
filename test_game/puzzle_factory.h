#ifndef __PUZZLE_FACTORY_H__
#define __PUZZLE_FACTORY_H__

#include <istream>
#include <sstream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include "puzzle_move.h"
#include "puzzle.h"

using namespace std;
using cs427_527::PuzzleMove;

namespace cs427_527
{
	class PuzzleFactory
	{
	public:
	    /**
	     * Creates a puzzle object.
	     */
		PuzzleFactory();


		virtual ~PuzzleFactory();

		virtual Puzzle puzzleFromString(string init);

		virtual Puzzle puzzleFromStream(ifstream init);

		virtual Puzzle defaultPuzzle();




	};

}




#endif /* CONWAY_H_ */
