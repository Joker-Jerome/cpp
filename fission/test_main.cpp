#include "checkerboard.h"

#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <fstream>

#include "checkerboard.h"
#include "piece.h"


using cs427_527::CheckerBoard;
using cs427_527::PieceBoard;


void outputHTML(CheckerBoard &b) {

	std::ofstream fo;
	std::string colBoard;
	std::string colPiece;
	int light;

	fo.open("fission_output.html");

	fo <<  	"<!DOCTYPE html>\n"
			<<"<html>\n"
			<<"<head>\n"
			<<"<meta charset=" << "\"UTF-8\"" << ">\n"
			<<"<title>Fission</title>\n"
			<<"</head>\n"
			<<"<body>\n"
			<< "<canvas id=" <<"\"board\" " << "width=" << "\"" << 20*b.getWidth() << "\"" << "height=" << "\"" << 20*b.getHeight() << "\"" << "></canvas>\n"
			<<"<script>\n"
			<<"var canvas = document.getElementById('board');\n"
			<<"var g = canvas.getContext('2d');\n";

	// draw the board

	for (int i = 0; i < b.getWidth(); i++) {
		for (int j = 0; j < b.getHeight(); j++) {
			if (b.getBoardColor(j, i) == PieceBoard::Color::RED) {
				colBoard = "#FFFFFF";
			} else {
				colBoard = "#808080";
			}
			fo << "g.fillStyle = '" << colBoard << "';" << std::endl;
			fo << "g.fillRect("<<j*20 << ", " << i*20 << ", 20, 20);" << std::endl;
		}
	}

	// draw the pieces

	for (int j = 0; j < b.getHeight(); j++){
			for (int i = 0; i < b.getWidth(); i++) {
				if (b.getPiece(j, i) != nullptr) {
					if (b.getPiece(j, i)->getPlayer() == 0) {
						colPiece = "#FF0000";
					} else {
						colPiece = "#0000FF";
					}
					if (b.getPiece(j, i)->getLight()) {
						light = 5;
					} else {
						light = 8;
					}

					fo <<"g.beginPath();" << std::endl;
					fo << "g.arc(" << std::to_string(10+20*i) << ", " << std::to_string(10+20*j) << ", " << light <<", 0, 2*Math.PI);" << std::endl;
					fo << "g.fillStyle = '" << colPiece << "';" << std::endl;
					fo << "g.fill();" << std::endl;
				}
		}
	}
	fo << "</script>\n" << "</body>\n" << "</html>\n";


	fo.close();


}

void play(CheckerBoard &b) {
	// game is going on
	while (!b.gameOver() && !b.isDraw() && std::cin)
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
		// game is over
	  if (b.gameOver())
	    {
	      std::cout << (b.getCurrentPlayer() + 1) % 2 << " wins" << std::endl;
	    }
	  	 // game is draw
	  if (b.isDraw())
		{
		  std::cout << "Draw" << std::endl;
		}
	  outputHTML(b);
}




int main(int argc, char **argv)
{


  if (argc == 3) {				// width and height specified
	  int r, c;
	  r = atoi(argv[1]);
	  c = atoi(argv[2]);

	  // check the input
	  if (r % 2 != 0 || c % 2 !=0 || r < c || r < 4 || c < 4) {
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


}


