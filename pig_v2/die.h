#ifndef __DIE_H__
#define __DIE_H__

#include <iostream>

namespace cs427_527
{
  /**
   * A fair n-sided die.  Rolls are generated by the C library function
   * rand and it is the responsibility of the user of this class to
   * seed the random number generator.
   */
  class Die
  {
  public:
    /**
     * Creates and rolls a die with the given number of sides.
     *
     * @param s a positive number
     */
    Die(int s);

    /**
     * Rolls this die.  The number showing will be chosen randomly and uniformly
     * from the range from 1 to the number of sides on this die.
     */   
    void roll();

    /**
     * Returns the number showing on this die.
     *
     * @return the number showing on this die
     */
    int getNumber() const;
  private:
    /**
     * The number of sides on this die.*
     */
    int numSides;

    /**
     * The number showing on this die.
     */
    int numShowing;
  };

  /**
   * Prints the given die to the given stream.
   *
   * @param os an output stream
   * @param die a die
   * @return the output stream
   */
  std::ostream& operator<<(std::ostream& os, const Die &die);
}



#endif