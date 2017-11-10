#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

#include <algorithm>

#include "pig.h"
#include "die.h"

namespace cs427_527
{
  PigGame::PigGame(std::shared_ptr<Player> p1, std::shared_ptr<Player> p2, int t)
    :       scores(2, 0),
	    target(t),
	    turn(0)
  {
    if (target < 1)
      {
	std::ostringstream os;
	os << "target must be positive: " << target;
	throw os.str();
      }
    
    players.push_back(p1);
    players.push_back(p2);
  }

  PigGame::~PigGame()
  {
  }

  void PigGame::playTurn()
  {
    Die die(NUM_SIDES);
    int turnTotal = die.getNumber();
    bool again = true;

    std::cout << *this << std::endl
	      << "Roll: " << die << std::endl;

    while (!busted(die) && again && scores[turn] + turnTotal < target)
      {
	std::cout << scores[turn] << "+" << turnTotal << "="
		  << scores[turn] + turnTotal
		  << std::endl;

	// reorder the scores so current player's is first
	std::vector<int> copyScores = scores;
	for (unsigned int i = 0; i < turn; i++)
	  {
	    copyScores.push_back(copyScores[0]);
	    copyScores.erase(copyScores.begin());
	  }
	again = players[turn]->rollAgain(copyScores, turnTotal, target);
	
	if (again)
	  {
	    die.roll();
	    turnTotal += die.getNumber();
	    std::cout << "Roll: " << die << std::endl;
	  }
      }

    // end of turn -- bust or success?
    if (busted(die))
      {
	// bust; wait for player to acknowledge
	std::cout << "PIG!" << std::endl;
	players[turn]->acknowledge();
      }
    else
      {
	// success -- add turn total to score
	scores[turn] += turnTotal;
      }

    // next player's turn
    turn = 1 - turn;
  }

  bool PigGame::busted(const Die& die) const
  {
    return die.getNumber() == 1;
  }

  bool PigGame::gameOver() const
  {
    return std::find_if(scores.begin(), scores.end(), [&](int score) { return score >= target; }) != scores.end();
  }
  
  void PigGame::playGame()
  {
    while (!gameOver())
      {
	playTurn();
      }
    std::cout << *this << std::endl;
  }

  std::string PigGame::toString() const
  {
    std::ostringstream out;
    for (unsigned int p = 0; p < players.size(); p++)
      {
	out << (turn == p ? "> " : "  ")         // mark current player
	    << std::setw(4) << scores[p] << " "  // output score
	    << players[p]->getName()             // output name
	    << std::endl;
      }
    return out.str();
  }

  std::ostream& operator<<(std::ostream& os, const PigGame& game)
  {
    return os << game.toString();
  }
  
}
