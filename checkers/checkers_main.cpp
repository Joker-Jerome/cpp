/*
 * 		checkers.cpp
 *
 *
 *      Author: jerome
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <sstream>
#include <memory>

#include "checker.h"
#include "king.h"
#include "checkerboard.h"
#include "math.h"

using cs427_527::Checker;
using cs427_527::King;
using cs427_527::CheckerBoard;

int play(CheckerBoard& board)
{

      std::cout << board << std::endl;

      // loop until game is over
      int fromR, fromC, toR, toC;
      while (!board.gameOver() && (std::cin >> fromR >> fromC >> toR >> toC))
	{
    	  std::shared_ptr<Checker> checker;
    	  checker = board.getPiece(fromR,fromC);
	  checker->makeMove(board,toR,toC);

	  std::cout << board << std::endl;
	 }
      if (board.gameOver())
	{
	  std::cout << "Game Over" << std::endl;
	}


  return 0;
}

int main(int argc, char **argv)
{
  if (argc > 1)
    {
      std::cerr << "USAGE: " << argv[0]
		<< " Unexpected Argument"
		<< std::endl;

      return 1;
    }

  int skipArgs = 2;

  try
    {
      CheckerBoard board;

      // play the game
      if (board != nullptr)
	{
	  int result = play(board);

	  delete board;

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



