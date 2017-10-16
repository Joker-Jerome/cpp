#include <iostream>
#include <sstream>
#include <string>
#include "poll.h"

using std::cout;
using std::endl;

namespace cs427_527{
  Poll::Poll(int n): size(n)
  {
    if(n > 0)
      {
      options = new int[size]();
      }
    else
      {
        throw "Error! Need size greater than 0";
      }
  }

  Poll::~Poll()
  {
    delete [] options;
  }

  Poll::Poll(const cs427_527::Poll &toCopy)
  {
    // Copy members from rhs
    size = toCopy.size;

    // Make deep copy of rhs data
    options = new int[size];
    for (int i = 0; i < size; i++)
      {
        options[i] = toCopy.options[i];
      }
  }

  Poll::Poll(cs427_527::Poll &&toMove)
  {
    // Steal members
    size = toMove.size;
    options =toMove.options;

    // Zero the rhs
    toMove.size = 0;
    toMove.options = NULL;

  }

  cs427_527::Poll& Poll::operator+=(const int rhs)
  {
    (*this).addVote(rhs);
    return *this;
  }

  cs427_527::Poll Poll::operator+(const cs427_527::Poll &rhs) const

  {
    return (*this).merge(rhs);
  }

  cs427_527::Poll& Poll::operator=(const Poll &rhs)
  {
    if(&rhs != this)
      {
        // free old list first
        delete [] options;

        // copy members from rhs
        size = rhs.size;

        // Make deep copy of data
        options = new int[size];
        for(int i = 0; i < size; i++)
          {
            options[i] = rhs.options[i];
          }

      }
    return *this;
  }

  cs427_527::Poll& Poll::operator=(Poll &&rhs)
  {
    if(&rhs != this)
      {
        delete [] options;

        // steal members
        size = rhs.size;
        options = rhs.options;

        // zero out rhs members.
        rhs.size = 0;
        rhs.options = NULL;
      }
    return *this;
  }

  void Poll::addVote(int opt)
  {
    if(opt >= size || opt < 0)
      {
	// do nothing
      }
    else
      {
        options[opt] += 1;
      }
  }

  int Poll::getLeader() const
  {
    int leader_val = options[0], leader_idx = 0;
    for(int i = 0; i < size; i++)
      {
        if(leader_val < options[i])
          {
            leader_val = options[i];
            leader_idx = i;
          }
      }
    return leader_idx;
  }

  cs427_527::Poll Poll::merge(cs427_527::Poll other) const
  {
    // Can only merge polls of like size
    if(size == other.size)
      {
        cs427_527::Poll return_poll(size);
        for (int i = 0; i < size; i++)
          {
            return_poll.options[i] = options[i] + other.options[i];
          }

        return return_poll;
      }
    else
      {
        throw "Error, polls are not the same size!";
      }
  }
  std::string Poll::toString() const
  {
    std::ostringstream oss;
    // Add brackets for nice formatting
    oss << "[";

    // Loop through elements until penultimate one
    // to avoid conditional
    for(int i = 0; i < size - 1; i++)
      {
        oss << options[i] << ", ";
      }
    // Need closing bracket
    oss << options[size - 1] << "]" << endl;
    return oss.str();
  }
  std::ostream& operator<<(std::ostream& os, const Poll& p )
  {
    return os << p.toString();
  }
}
