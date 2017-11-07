#include <iostream>
#include <memory>

#include <cstdlib>
#include <ctime>
#include <cstring>

#include "pig.h"
#include "player.h"
#include "computer.h"
#include "dynamic.h"
#include "human.h"
#include "player_factory.h"
#include "computer_factory.h"
#include "dynamic_factory.h"

using cs427_527::PigGame;
using cs427_527::Player;
using cs427_527::Computer;
using cs427_527::DynamicComputer;
using cs427_527::PlayerFactory;
using cs427_527::ComputerFactory;
using cs427_527::DynamicFactory;
using cs427_527::Human;

int main(int argc, char **argv)
{
  if (argc < 3)
    {
      std::cerr << "USAGE: " << argv[0] << " target player-name-1 [aggressiveness] player-name-2 [aggressiveness]" << std::endl;
      return 1;
    }

  // seed random number generator
  std::srand(std::time(NULL));

  int a = 2;
  std::vector<std::shared_ptr<Player>> players;
  while (a < argc && players.size() < 2)
    {
      std::shared_ptr<PlayerFactory> factory;
      
      if (strcmp(argv[a], "Computer") == 0)
	{
	  factory = std::make_shared<ComputerFactory>();
	}
      else if (strcmp(argv[a], "DynamicComputer") == 0)
	{
	  factory = std::make_shared<DynamicFactory>();
	}

      std::shared_ptr<Player> p;
      if (factory.get() != nullptr)
	{
	  if (a + 1 < argc && strcmp(argv[a + 1], "aggressive") == 0)
	    {
	      p = factory->makeAggressive();
	      a += 2;
	    }
	  else if (a + 1 < argc && strcmp(argv[a + 1], "conservative") == 0)
	    {
	      p = factory->makeConservative();
	      a += 2;
	    }
	  else if (a + 1 < argc && strcmp(argv[a + 1], "default") == 0)
	    {
	      p = factory->makeDefault();
	      a += 2;
	    }
	  else
	    {
	      p = factory->makeDefault();
	      a += 1;
	    }
	}
      else
	{
	  p = std::make_shared<Human>(argv[a]);
	  a += 1;
	}
      players.push_back(p);
    }

  if (players.size() == 2)
    {
      PigGame game(players[0], players[1], std::atoi(argv[1]));
      game.playGame();
    }
}

