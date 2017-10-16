#include <iostream>
#include <string>

#include <cstdlib>

#include "civector.h"


namespace cs427_527
{
  template<typename Iterator, typename Value, typename Function>
    Value fold_l(const Iterator& begin, const Iterator &end, Value init, Function f)
  {
    Value result = init;
    for (Iterator i = begin; i != end; i++)
      {
	result = f(result, *i);
      }
    return result;
  }
}

using cs427_527::fold_l;
using cs427_527::CIVector;

int add(int x, int y);

int main(int argc, char **argv)
{
  CIVector<int> ints;
  CIVector<std::string> strings;
  
  for (int i = 1; i < argc; i++)
    {
      strings.push_back(std::string(argv[i]));
      ints.push_back(std::atoi(argv[i]));
    }

  std::cout << fold_l(ints.begin(), ints.end(),
		      0,
		      add)
	    << std::endl;
  
  std::cout << fold_l(ints.begin(), ints.end(),
		      0,
		      [] (int x, int y) { return x + y; })
	    << std::endl;
  
  std::cout << fold_l(strings.begin(), strings.end(),
		      std::string(""),
		      [] (const std::string& x, const std::string& y) { return x + y; })
	    << std::endl;
  
}

int add(int x, int y)
{
  return x + y;
}
