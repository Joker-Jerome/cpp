#include <iostream>
#include <string>

#include <algorithm>

#include <cstdlib>

#include "nivector.h"

//using Vector = std::vector<std::string>;
using Vector = cs427_527::NIVector<std::string>;

int main(int argc, char **argv)
{
  if (argc < 3)
    {
      std::cerr << "USAGE: " << argv[0] << " num-to-add-before-getting-refernce  num-to-add-after-getting-referece" << std::endl;
      return 1;
    }
  
  Vector v;

  int x = std::atoi(argv[1]);
  int y = std::atoi(argv[2]);

  for (int i = 0; i < x; i++)
    {
      v.push_back("X");
    }

  std::string& first = v.at(0);

  for (int i = 0; i < y; i++)
    {
      v.push_back("Y");
    }
  
  // this will fail for std::vector for large enough values of y because
  // the reference is invalidated once the array inside the vector is resized;
  // it should work for NIVector
  first = "Z";

  std::for_each(v.begin(), v.end(), [](const std::string& s) { std::cout << s; });
  std::cout << std::endl;

  cs427_527::NIVector<int> lengths; // (yes, they will all be ones)
  std::for_each(v.begin(), v.end(), [&](const std::string& s) { lengths.push_back(s.length()); });

  int totalLength = 0;
  std::for_each(lengths.begin(), lengths.end(), [&](int len) { totalLength += len; });
  std::cout << "total length = " << totalLength << std::endl;
  
  try
    {
      std::string s = *(v.end());
      
      std::cout << "dereferencing end iterator should fail; instead returned"
		<< std::endl
		<< s
		<< std::endl;
    }
  catch (const std::string& ex)
    {
      std::cout << "can't dereference end iterator, as expected" << std::endl;
    }
}

  
