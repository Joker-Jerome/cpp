#include <iostream>

#include "interactive.h"

namespace cs427_527
{
  bool InteractiveStrategy::rollAgain(std::vector<int> scores, int turnTotal, int target)
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
}
