#include <iostream>
#include <iomanip>
#include <string>

#include "rational.h"

using std::cout;
using std::endl;
using std::setw;
using std::istringstream;
using std::ostringstream;
using std::string;

using cs427_527::Rational;

int main(int argc, char *argv[])
{
  Rational pi(22, 7);
  Rational zero;
  Rational one(1);
  Rational half(std::string("1/2"));
  Rational third("1/3");

  Rational sum = half + third;
  half.print(cout);
  cout << " + ";
  third.print(cout);
  cout << " = ";
  sum.print(cout) << endl;
    
  sum += one;
  cout << "adding one: " << sum << endl;
  
  sum += 1;
  //sum += "2/10";
  cout << "after adding 1 and 2/10: " << setw(16) << sum << endl;

  int x = pi;
  cout << "pi is approx " << x << endl;
}
