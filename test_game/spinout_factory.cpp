#include "spinout_factory.h"
using namespace std;

namespace cs427_527
{
/**
 * Creates a puzzle factory .
 */
	SpinOutFactory::SpinOutFactory()
	{

	}


	SpinOutFactory::~SpinOutFactory(){

	}

	Puzzle SpinOutFactory::puzzleFromString(string init){
		Puzzle *puzzle;
		puzzle = new SpinOut(init);

		return(puzzle);

	}

	Puzzle SpinOutFactory::puzzleFromStream(ifstream init){
		Puzzle *puzzle;
		puzzle = new SpinOut(init);

		return(puzzle);
	}

	Puzzle SpinOutFactory::defaultPuzzle(){
			Puzzle *puzzle;
			puzzle = new SpinOut();

			return(puzzle);
		}



}
