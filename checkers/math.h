#ifndef __MATH_H__
#define __MATH_H__

namespace cs427_527
{
  /**
   * Returns the maximum of the two given integers.
   *
   * @param a an integer
   * @param b an integer
   * @return max(a, b)
   */
  int imax(int a, int b);

  /**
   * Returns the absolute value of the given integer.
   *
   * @param a an integer
   * @return abs(a)
   */
  int iabs(int a);

  /**
   * Returns the distance between the given positions on a grid.
   * The distance is defined as the larger of the absolute value
   * in the differences of the row indices and column indices.
   *
   * @param fromR an integer
   * @param fromC an integer
   * @param toR an integer
   * @param toC an integer
   * @return the distance between those two positions
   */
  int distance(int fromR, int fromC, int toR, int toC);
}
#endif
  
