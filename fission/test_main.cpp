#include "checkerboard.h"

#include <iostream>
#include <memory>
#include <sstream>
#include <string>

#include "checkerboard.h"

using cs427_527::CheckerBoard;


void play(CheckerBoard &b) {
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
			  std::cout << "legal!" << std::endl;
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


int main(int argc, char **argv)
{


  if (argc == 3) {				// width and height specified
	  int r, c;
	  r = atoi(argv[1]);
	  c = atoi(argv[2]);

	  // check the input
	  if (r % 2 != 0 || c % 2 !=0 || r > c || r < 4 || c < 4) {
		  return 1;
	  }

	  //std::cout << r << c;
	  CheckerBoard b(r, c);
	  std::cout << b;
	  play(b);

  } else if (argc == 1) {		// width and height not specified

	  CheckerBoard b;
	  std::cout << b;
	  play(b);
  } else {
	  return 1;
  }

//  while (!b.gameOver() && std::cin)
//      {
//        std::cout << "PLAYER " << b.getCurrentPlayer() << std::endl;
//        std::string move;
//        if (std::getline(std::cin, move))
//  	{
//  	  std::istringstream in(move);
//  	  int fromR, fromC, toR, toC;
//  	  if (in >> fromR >> fromC >> toR >> toC)
//  	    {
//  	      if (b.isLegalMove(fromR, fromC, toR, toC))
//  		{
//  		  b.makeMove(fromR, fromC, toR, toC);
//  		  std::cout << b;
//  		}
//  	      else
//  		{
//  		  std::cout << "illegal move" << std::endl;
//  		}
//  	    }
//  	  else
//  	    {
//  	      std::cout << "invalid input" << std::endl;
//  	    }
//  	}
//      }
//    if (b.gameOver())
//      {
//        std::cout << (b.getCurrentPlayer() + 1) % 2 << " wins" << std::endl;
//      }
//  return 1;
}


