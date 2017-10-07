#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

#include "rational.h"

namespace cs427_527
{

  Rational::Rational(int n, int d)
  {
    numerator = n;
    denominator = d;
  }

  Rational::Rational(const std::string& s)
  {
    std::istringstream in(s);
    read(in);
  }

  
  std::ostream& Rational::print(std::ostream& os) const
  {
    std::ostringstream out;

    int numWidth = (os.width() - 1) / 2;

    out << std::setw(numWidth) << numerator << "/"
	<< std::setw(os.width() - 1 - numWidth) << denominator;

    os << out.str();

    return os;
  }

  std::istream& Rational::read(std::istream& is)
  {
    char sep;
    is >> numerator >> sep >> denominator;
    
    return is;
  }
  
  Rational Rational::operator +(const Rational& rhs) const
  {
    return Rational(numerator * rhs.denominator + rhs.numerator * denominator,
		    denominator * rhs.denominator);
  }
  
  Rational& Rational::operator +=(const Rational& rhs)
  {
    numerator *= rhs.denominator;
    numerator += rhs.numerator * denominator;
    denominator *= rhs.denominator;

    return *this;
  }
    
  Rational::operator int() const
    {
      return numerator / denominator;
    }
  
  std::ostream& operator<<(std::ostream& os, const Rational& r)
  {
    return r.print(os);
  }
  
  std::istream& operator>>(std::istream& is, Rational& r)
  {
    return r.read(is);
  }
}
