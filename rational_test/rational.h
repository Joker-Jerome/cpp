#ifndef __RATIONAL_H__
#define __RATIONAL_H__

#include <iostream>
#include <string>

namespace cs427_527
{
  class Rational
  {
  public:
    Rational(int n = 0, int d = 1);
    Rational(const std::string& s);

    std::ostream& print(std::ostream& os) const;
    std::istream& read(std::istream& is);
    
    Rational operator +(const Rational& rhs) const;
    Rational& operator +=(const Rational& rhs);
    operator int() const;

  private:
    int numerator;
    int denominator;
  };

  std::ostream& operator<<(std::ostream& os, const Rational& r);
  std::istream& operator>>(std::istream& is, Rational&);
  
}

#endif
