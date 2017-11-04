#include <string>
#include <iostream>

#include "human.h"

namespace cs427_527
{
  Human::Human(const std::string& n)
    : Player(n)
  {
  }

  Human::~Human()
  {
  }

  bool Human::rollAgain(std::vector<int> scores, int turnTotal, int target)
  {
    std::string response;
    do
      {
	std::cout << "Roll again (y/n)?" << std::endl;
	std::getline(std::cin, response);
      }
    while (std::cin && (response.length() == 0 || (response[0] != 'y' && response[0] != 'n')));
    
    return (response.length() > 0 && response[0] == 'y');
  }

  void Human::acknowledge() const
  {
    std::string ack;
    std::getline(std::cin, ack);
  }
}
