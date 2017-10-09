#include <iostream>
#include <string>

#include <cstdlib>

#include "civector.h"

using AirportVector = cs427_527::CIVector<std::string>;

int distance(const std::string& s1, const std::string& s2);
bool closer_to_bwi(const std::string& s1, const std::string& s2);

class CloserToBWI
{
public:
  bool operator()(const std::string& s1, const std::string& s2)
  { return distance(s1, "BWI") < distance(s2, "BWI"); }
};

class CloserTo
{
public:
  CloserTo(const std::string& s) { base = s; }
  
  bool operator()(const std::string& s1, const std::string& s2)
  { return distance(s1, base) < distance(s2, base); }

private:
  std::string base;
};
  
int main(int argc, char **argv)
{
  AirportVector route;
  
  for (int i = 1; i < argc; i++)
    {
      std::cout << argv[i] << " = " << distance(argv[i], "BWI") << std::endl;
      route.push_back(std::string(argv[i]));
    }

  AirportVector copy = route;
  
  route.sort(std::less<std::string>());

  std::cout << route << std::endl;

  copy.sort(closer_to_bwi);

  std::cout << copy << std::endl;

  AirportVector anotherCopy = route;
  anotherCopy.sort(CloserToBWI());
  std::cout << anotherCopy << std::endl;

  AirportVector yetAnotherCopy = route;
  yetAnotherCopy.sort(CloserTo("BWI"));
  std::cout << yetAnotherCopy << std::endl;
  yetAnotherCopy.sort(CloserTo("SEA"));
  std::cout << yetAnotherCopy << std::endl;

  yetAnotherCopy.sort([](const std::string& s1, const std::string& s2)
		      { return distance(s1, "PVG") < distance(s2, "PVG"); });
  std::cout << yetAnotherCopy << std::endl;

  std::string home = "BWI";
  yetAnotherCopy.sort([&](const std::string& s1, const std::string& s2)
		      { return distance(s1, home) < distance(s2, home); });
  std::cout << yetAnotherCopy << std::endl;
}

int distance(const std::string& s1, const std::string& s2)
{
  int d = 0;
  for (auto i = s1.begin(), j = s2.begin();
       i != s1.end() && j != s2.end();
       i++, j++)
    {
      d += std::abs(*i - *j);
    }
  return d;
}

bool closer_to_bwi(const std::string& s1, const std::string& s2)
{
  return distance(s1, "BWI") < distance(s2, "BWI");
}
