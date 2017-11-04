#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <sstream>

#include "merlin.h"
#include "spinout.h"

using cs427_527::Merlin;
using cs427_527::SpinOut;

template< typename G >
int play(int argc, char **argv)
{
  // check for interactive mode option
  bool interactive = (argc > 1 && strcmp(argv[1], "-i") == 0);

  // compute indices of command-line arguments for start indices and move
  // (will update index of move if there is a starting configuration)
  int indexOfStartConfig = (interactive ? 2 : 1);
  int indexOfMove = indexOfStartConfig;

  // make initial default puzzle (will replace if starting config was given)
  G puzzle;

  // check for config file or config string given on command line
  if (indexOfStartConfig + 1 < argc && strcmp(argv[indexOfStartConfig], "-f") == 0)
    {
      std::ifstream in(argv[indexOfStartConfig + 1]);
      
      puzzle = G(in);
      indexOfMove += 2;
    }
  else if (indexOfStartConfig + 1 < argc && strcmp(argv[indexOfStartConfig], "-s") == 0)
    {
      std::string init(argv[indexOfStartConfig + 1]);
      puzzle = G(init);
    }
  
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
      typename G::Move move;
      while (movesIn >> move)
	{
	  if (puzzle.isLegalMove(move))
	    {
	      puzzle.makeMove(move);
	      indexOfMove++;
	    }
	  else
	    {
	      std::cout << "illegal move" << move
			<< " in position " << indexOfMove
			<< " for" << std::endl
			<< puzzle << std::endl;
	      return 1;
	    }
	}
      
      if (puzzle.isSolved())
	{
	  std::cout << "SOLVED" << std::endl;
	}
      else
	{
	  std::cout << puzzle << std::endl;
	}
    }
  else // interactive mode
    {
      std::cout << puzzle << std::endl;
      
      // loop until puzzle is solved or player gives up
      typename G::Move move;
      while (!puzzle.isSolved() && std::cin >> move)
	{
	  if (puzzle.isLegalMove(move))
	    {
	      puzzle.makeMove(move);
	      
	      std::cout << puzzle << std::endl;
	    }
	  else
	    {
	      std::cout << "illegal move" << std::endl;
	    }
	}
      if (puzzle.isSolved())
	{
	  std::cout << puzzle.totalMoves() << " moves" << std::endl;
	}
    }

  return 0;
}

int main(int argc, char **argv)
{
  if (argc < 2)
    {
      std::cerr << "USAGE: " << argv[0]
		<< " {merlin|spinout} [-i] [-f config-file | -s config] [moves...]"
		<< std::endl;

      return 1;
    }
  
  try
    {
      if (strcmp(argv[1], "merlin") == 0)
	{
	  return play<Merlin>(argc - 1, argv + 1);
	}
      else
	{
	  return play<SpinOut>(argc - 1, argv + 1);
	}
    }
  catch (const char *s)
    {
      std::cout << argv[0] << ": " << s << std::endl;
      return 1;
    }
}
