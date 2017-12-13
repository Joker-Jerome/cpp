#include <iostream>

class Object
{
};

class Integer : public Object
{
public:
  Integer(int n) { value = n; }
  int intValue() const { return value; }
private:
  int value;
};

class String : public Object
{
public:
  String(const std::string& s) { value = s; }
  std::string toString() const { return value; }
private:
  std::string value;
};

int main(int argc, char **argv)
{
  Integer *primes[] = { new Integer(2),
			new Integer(3),
			new Integer(5),
			new Integer(7),
			nullptr
  };
  Integer **p = primes;
  
  Object **arr = p;   // arrays are not covariant in C++ so this is illegal

  arr[4] = new String("Eleven");
}

