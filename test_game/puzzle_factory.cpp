#include "puzzle_factory.h"
using namespace std;

namespace cs427_527
{
/**
 * Creates a puzzle factory .
 */
	PuzzleFactory::PuzzleFactory()
	{

	}


	PuzzleFactory::~PuzzleFactory(){

	}

	Puzzle* PuzzleFactory::puzzleFromString(string init){
		Puzzle *puzzle;
		puzzle = new Puzzle;
		return(puzzle);

	}

	Puzzle* PuzzleFactory::puzzleFromStream(ifstream& init){
		Puzzle *puzzle;
		puzzle = new Puzzle;
		return(puzzle);
	}

	Puzzle* PuzzleFactory::defaultPuzzle(){
		Puzzle *puzzle;
		puzzle = new Puzzle;
		return(puzzle);

	}




}
