#ifndef __POLL_H__
#define __POLL_H__

#include <iostream>
#include <string>

namespace cs427_527
{
  class Poll
  {
  public:
    /**
     * initialized a Poll with n options
     */
    Poll(int n);

    ~Poll();

    /**
     * Copy and move constructors
     */
    Poll(const Poll &toCopy);
    Poll(Poll &&toMove);

    /**
     * Merges counts in two polls
     *
     *  @param rhs, A Poll to be merged
     *  @return a reference to the lhs Poll with merged options
     */
    Poll& operator+=(const int rhs);

    /**
     * Copy and move assignment operators
     */
    Poll& operator=(const Poll &rhs);
    Poll& operator=(Poll &&rhs);

    /**
     * Increments count at option rhs
     *
     *  @param rhs, the option to be incremented
     *  @return a reference to Poll object being incremented
     */
    Poll operator+(const Poll &rhs) const;

    /**
     * Increments count at option opt
     *
     *  @param opt, the option to be incremented
     *  @return nothing
     */
    void addVote(int opt);

    /**
     * Creates a string representation of the options
     *
     *  @param nothing
     *  @return A string of the options
     */
    std::string toString() const;

    /**
     *  Returns the index of the option currently with the most votes,
     *  with ties broken in favor of lower index
     *
     *  @param nothing
     *  @return Index of leading option
     */
    int getLeader() const;

    /**
     * Merges options of two polls
     *
     *  @param other, A Poll to be merged
     *  @return a new, merged poll
     */
    Poll merge(Poll other) const;
  private:

    int size;
    /**
     * Dynamic array of options
     */
    int *options;
  };

  /**
   * Prints options for a given poll
   *
   *  @param os, a stream to output to
      @param p, a reference to a poll to be printed
   *  @return a stream containing the p's options
   */
  std::ostream& operator<<(std::ostream& os, const Poll& p );
}

#endif
