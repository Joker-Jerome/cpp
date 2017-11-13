#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <sstream>

#include "puzzle.h"
#include "conway.h"
#include "spinout.h"

#include "puzzle_move.h"

using cs427_527::Puzzle;
using cs427_527::Conway;
using cs427_527::SpinOut;
using cs427_527::PuzzleMove;

#ifdef CS527
#include "puzzle_factory.h"
#include "conway_factory.h"
#include "spinout_factory.h"
using cs427_527::PuzzleFactory;
using cs427_527::ConwayFactory;
using cs427_527::SpinOutFactory;
#endif

int play(Puzzle *puzzle, int argc, char **argv)
{
  // check for interactive mode option
  bool interactive = (argc > 0 && strcmp(argv[0], "-i") == 0);

  // compute indices of command-line arguments for start indices and move
  // (will update index of move if there is a starting configuration)
  int indexOfMove = (interactive ? 1 : 0);

  if (!interactive)
    {
      // non-interactive mode -- gather moves from command line into a string
      std::string moves;
      for (int a = indexOfMove; a < argc; a++)
	{
	  if (a > indexOfMove)
	    {
	      moves += ' ';
	    }
	  
	  moves += argv[a];
	}

      // put moves into a string stream for reading
      std::istringstream movesIn(moves);

      // keep track of 1-based move counter for use in error messages
      int indexOfMove = 1;

      // loop over all moves
      PuzzleMove *move;
      while ((move = puzzle->readMove(movesIn)) && movesIn)
	{
	  if (puzzle->isLegalMove(move))
	    {
	      puzzle->makeMove(move);
	      indexOfMove++;
	    }
	  else
	    {
	      std::cout << "illegal move " << *move
			<< " in position " << indexOfMove
			<< " for" << std::endl
			<< *puzzle << std::endl;

	      delete move;

	      return 1;
	    }

	  delete move;
	}
      
      if (puzzle->isSolved())
	{
	  std::cout << "SOLVED" << std::endl;
	}
      else
	{
	  std::cout << *puzzle << std::endl;
	}
    }
  else // interactive mode
    {
      std::cout << *puzzle << std::endl;
      
      // loop until puzzle is solved or player gives up
      PuzzleMove *move;
      while (!puzzle->isSolved() && (move = puzzle->readMove(std::cin)) && std::cin)
	{
	  if (puzzle->isLegalMove(move))
	    {
	      puzzle->makeMove(move);

	      std::cout << *puzzle << std::endl;
	    }
	  else
	    {
	      std::cout << "illegal move" << std::endl;
	    }
      
	  delete move;
	}
      if (puzzle->isSolved())
	{
	  std::cout << puzzle->totalMoves() << " moves" << std::endl;
	}
    }

  return 0;
}

int main(int argc, char **argv)
{
  if (argc < 2)
    {
      std::cerr << "USAGE: " << argv[0]
		<< " {spinout|conway} [-f config-file | -s config] [-i] [moves...]"
		<< std::endl;

      return 1;
    }

  int skipArgs = 2;
  
  try
    {
      Puzzle *puzzle;

#ifdef CS527
      PuzzleFactory *factory;

      // make a puzzle factory according to 1st command-line argument
      if (strcmp(argv[1], "spinout") == 0)
	{
	  factory = new SpinOutFactory();
	}
      else if (strcmp(argv[1], "conway") == 0)
	{
	  factory = new ConwayFactory();
	}
      else
	{
	  std::cerr << argv[0] << ": invalid game " << argv[1] << std::endl;
	  return 1;
	}

      // get a puzzle from the factory according to initialization
      if (argc >= 4 && strcmp(argv[2], "-s") == 0)
	{
	  std::string init(argv[3]);
	  puzzle = factory->puzzleFromString(init);
	  skipArgs += 2;
	}
      else if (argc >= 4 && strcmp(argv[2], "-f") == 0)
	{
	  std::ifstream in(argv[3]);
	  puzzle = factory->puzzleFromStream(in);
	  skipArgs += 2;
	}
      else
	{
	  puzzle = factory->defaultPuzzle();
	}

      delete factory;
#else
      if (strcmp(argv[1], "spinout") == 0)
	{
	  if (argc >= 4 && strcmp(argv[2], "-s") == 0)
	    {
	      std::string init(argv[3]);
	      puzzle = new SpinOut(init);
	      skipArgs += 2;
	    }
	  else
	    {
	      puzzle = new SpinOut();

	    }
	}
      else if (strcmp(argv[1], "conway") == 0)
	{
	  if (argc >= 4 && strcmp(argv[2], "-f") == 0)
	    {
	      std::ifstream in(argv[3]);
	      puzzle = new Conway(in);
	      skipArgs += 2;
	    }
	  else
	    {
	      puzzle = new Conway();
	    }
	}
      else
	{
	  std::cerr << argv[0] << ": invalid game " << argv[1] << std::endl;
	  return 1;
	}
#endif
      
      // play the puzzle
      if (puzzle != nullptr)
	{
	  int result = play(puzzle, argc - skipArgs, argv + skipArgs);

	  delete puzzle;

	  return result;
	}
      else
	{
	  return 1;
	}
    }
  catch (const char *s)
    {
      std::cerr << argv[0] << ": " << s << std::endl;
      return 1;
    }
  catch (const std::string& s)
    {
      std::cerr << argv[0] << ": " << s << std::endl;
      return 1;
    }
  catch (...)
    {
      std::cerr << argv[0] << ": terminated with exception" << std::endl;
    }
}
