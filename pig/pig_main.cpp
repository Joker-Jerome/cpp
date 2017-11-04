#include <iostream>

#include <cstdlib>
#include <ctime>
#include <cstring>

#include "pig.h"
#include "player.h"
#include "computer.h"
#include "human.h"

using cs427_527::PigGame;
using cs427_527::Player;
using cs427_527::Human;
using cs427_527::Computer;

int main(int argc, char **argv)
{
  if (argc < 4)
    {
      std::cerr << "USAGE: " << argv[0] << " target player-name-1 player-name-2" << std::endl;
      return 1;
    }

  // seed random number generator
  std::srand(std::time(NULL));

  Player *p1;
  if (strcmp(argv[2], "Computer") == 0)
    {
      p1 = new Computer(argv[2], 20);
    }
  else
    {
      p1 = new Human(argv[2]);
    }

  Player *p2;
  if (strcmp(argv[3], "Computer") == 0)
    {
      p2 = new Computer(argv[3], 20);
    }
  else
    {
      p2 = new Human(argv[3]);
    }

  PigGame game(p1, p2, std::atoi(argv[1]));
  game.playGame();
}

