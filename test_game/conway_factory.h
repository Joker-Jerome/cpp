#ifndef __CONWAY_FACTORY_H__
#define __CONWAY_FACTORY_H__

#include "puzzle_factory.h"
#include "conway.h"

using namespace std;


namespace cs427_527
{
	class ConwayFactory: public PuzzleFactory
	{
	public:
	    /**
	     * Creates a puzzle object.
	     */
		ConwayFactory();


		virtual ~ConwayFactory();

		virtual Puzzle puzzleFromString(string init);

		virtual Puzzle puzzleFromStream(ifstream init);

		virtual Puzzle defaultPuzzle();


	};

}



#endif /* _SPINOUT_FACTORY_H_ */
