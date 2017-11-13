#ifndef __SPINOUT_FACTORY_H__
#define __SPINOUT_FACTORY_H__

#include "puzzle_factory.h"
#include "spinout.h"

using namespace std;


namespace cs427_527
{
	class SpinOutFactory: public PuzzleFactory
	{
	public:
	    /**
	     * Creates a puzzle object.
	     */
		SpinOutFactory();


		virtual ~SpinOutFactory();

		virtual Puzzle* puzzleFromString(string init);

//		virtual Puzzle* puzzleFromStream(ifstream& init);

		virtual Puzzle* defaultPuzzle();


	};

}



#endif /* _SPINOUT_FACTORY_H_ */
