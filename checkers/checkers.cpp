#include <iostream>
#include <memory>
#include <sstream>
#include <string>

#include "checkerboard.h"

using cs427_527::CheckerBoard;

int main(int argc, char **argv)
{
  CheckerBoard b;

  std::cout << b;
  while (!b.gameOver() && std::cin)
    {
      std::cout << "PLAYER " << b.getCurrentPlayer() << std::endl;
      std::string move;
      if (std::getline(std::cin, move))
	{
	  std::istringstream in(move);
	  int fromR, fromC, toR, toC;
	  if (in >> fromR >> fromC >> toR >> toC)
	    {
	      if (b.isLegalMove(fromR, fromC, toR, toC))
		{
		  b.makeMove(fromR, fromC, toR, toC);
		  std::cout << b;
		}
	      else
		{
		  std::cout << "illegal move" << std::endl;
		}
	    }
	  else
	    {
	      std::cout << "invalid input" << std::endl;
	    }
	}
    }
  if (b.gameOver())
    {
      std::cout << (b.getCurrentPlayer() + 1) % 2 << " wins" << std::endl;
    }
}
