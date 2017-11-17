#include <iostream>

#include "world.h"

using World = cs427_527::World;

int main(int argc, char **argv)
{
  World w(12, 10, 1, 10);

  for (int i = 0; i < 100; i++)
    {
      w.update();
      std::cout << w << std::endl << std::endl;
      std::cin.get();
    }
}
