#include "conway_factory.h"
using namespace std;

namespace cs427_527
{
/**
 * Creates a puzzle factory .
 */
	ConwayFactory::ConwayFactory()
	{

	}


	ConwayFactory::~ConwayFactory(){

	}

	Puzzle ConwayFactory::puzzleFromString(string init){
		Puzzle *puzzle;
		puzzle = new Conway(init);

		return(puzzle);

	}

	Puzzle ConwayFactory::puzzleFromStream(ifstream init){
		Puzzle *puzzle;
		puzzle = new Conway(init);

		return(puzzle);
	}

	Puzzle ConwayFactory::defaultPuzzle(){
			Puzzle *puzzle;
			puzzle = new Conway();

			return(puzzle);
		}



}
