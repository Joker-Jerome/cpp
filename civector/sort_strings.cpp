#include <iostream>
#include <string>

#include <cstdlib>

#include "civector.h"

using AirportVector = cs427_527::CIVector<std::string>;

int distance(const std::string& s1, const std::string& s2);
bool closer_to_bwi(const std::string& s1, const std::string& s2);

void print(const std::string& s);
void print_vector(const cs427_527::CIVector<std::string>& vec);

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

template <class T>
void print_backwards(const cs427_527::CIVector<T>& vec)
{
  for (auto i = vec.rbegin(); i != vec.rend(); i++)
    {
      std::cout << *i << std::endl;
    }
}

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

  std::cout << "=== Output via iterator ===" << std::endl;
  for (AirportVector::iterator i = copy.begin();
       i != copy.end();
       i++)
    {
      std::cout << *i << std::endl;
    }

  std::cout << "=== Output via const iterator ===" << std::endl;
  print_vector(copy);

  std::cout << "=== Output via reverse iterator ===" << std::endl;
  for (auto i = copy.rbegin();
       i != copy.rend();
       i++)
    {
      std::cout << *i << std::endl;
    }

  std::cout << "=== Output via const reverse iterator ===" << std::endl;
  print_backwards(copy);

  std::cout << "=== Output via for_each ===" << std::endl;
  cs427_527::for_each(copy.begin(), copy.end(), print);

  std::cout << "=== Reverse output via for_each ===" << std::endl;
  cs427_527::for_each(copy.rbegin(), copy.rend(), print);

  std::cout << "=== Output via for_each with lambda ===" << std::endl;
  cs427_527::for_each(copy.begin(), copy.end(), [](const std::string& s) { std::cout << s << std::endl; } );

  std::cout << "=== find_if ===" << std::endl;
  auto s_first = cs427_527::find_if(copy.begin(), copy.end(), [](const std::string& s) { return s.length() > 0 && s[0] == 'S'; });
  if (s_first != copy.end())
    {
      std::cout << "first starting with S = " << *s_first << std::endl;
    }
  else
    {
      std::cout << "none start with S" << std::endl;
    }

  auto s_last = cs427_527::find_if(copy.rbegin(), copy.rend(), [](const std::string& s) { return s.length() > 0 && s[0] == 'S'; });
  if (s_last != copy.rend()) // forgot to change from end at first!
    {
      std::cout << "last starting with S = " << *s_last << std::endl;
    }
  else
    {
      std::cout << "none start with S" << std::endl;
    }
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

void print(const std::string& s)
{
  std::cout << s << std::endl;
}

void print_vector(const cs427_527::CIVector<std::string>& vec)
{
  // i is const_iterator b/c vec is a const CIVector&
  for (auto i = vec.begin(); i != vec.end(); i++)
    {
      std::cout << *i << std::endl;
    }
}
