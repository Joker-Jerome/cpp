#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

namespace geometry
{
  struct point { double x, y; };
  
  double euclideanDistance(double x1, double y1, double x2, double y2);
  double euclideanDistance(const point& p1, const point& p2);

  class Point
  {
  public:
    /**
     * Initializes this point to the origin (0, 0).
     */
    Point();

    /**
     * Initializes this point to (x, y).
     *
     * @param x a double
     * @param y a double
     */
    Point(double x, double y);

    /**
     * Calculates the Euclidean distance from this point to the given point.
     *
     * @param p a point
     * @return the distance from this point to p
     */
    double distanceTo(const Point& p) const;
    
  private:
    /**
     * The x-coordinate of this point.
     */
    double x;

    /**
     * The y-coordinate of this point.
     */
    double y;
  };
}
  
#endif
