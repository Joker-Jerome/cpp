#include <iostream>

#include <cstdlib>
#include <ctime>
#include <cstring>

#include "pig.h"
#include "player.h"
#include "interactive.h"
#include "threshold.h"

using cs427_527::PigGame;
using cs427_527::Player;
using cs427_527::InteractiveStrategy;
using cs427_527::ThresholdStrategy;

int main(int argc, char **argv)
{
  if (argc < 4)
    {
      std::cerr << "USAGE: " << argv[0] << " target player-name-1 player-name-2" << std::endl;
      return 1;
    }

  // seed random number generator
  std::srand(std::time(NULL));

  Player *p1 = (strcmp(argv[2], "Computer") == 0)
    ? new Player(argv[2], new ThresholdStrategy(20))
    : new Player(argv[2], new InteractiveStrategy());

  Player *p2 = (strcmp(argv[3], "Computer") == 0)
    ? new Player(argv[3], new ThresholdStrategy(20))
    : new Player(argv[3], new InteractiveStrategy());

  PigGame game(p1, p2, std::atoi(argv[1]));
  game.playGame();
}

