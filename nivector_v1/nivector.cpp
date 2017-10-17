#include <string>
#include <vector>

#include "nivector.h"

NIVector::NIVector()
{
  count = 0;
}

void NIVector::push_back(const std::string& s)
{
  if (count % CHUNK_SIZE == 0)
    {
      // time for a new chunk
      elements.push_back(std::vector<std::string>(CHUNK_SIZE));
    }

  // put s in appropriate location in appropriate chunk
  elements[count / CHUNK_SIZE][count % CHUNK_SIZE] = s;

  count++;
}

int NIVector::size() const
{
  return count;
}

std::string& NIVector::at(int i)
{
  return elements[i / CHUNK_SIZE][i % CHUNK_SIZE];
}
