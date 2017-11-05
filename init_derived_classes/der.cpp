#include <iostream>

using namespace std;

class Base
{
public:
    int m_id;
 
    Base(int id=0)
        : m_id(id)
    {
    }
 
    int getId() const { return m_id; }
};
 
class Derived: public Base
{
public:
    double m_cost;
 
    Derived(double cost=0.0, int id=999)
        : Base(id),m_cost(cost)
    {
    }
 
    double getCost() const { return m_cost; }
};

int main()
{
    Base base(5); // use Base(int) constructor
    Derived derived; // use Derived(double) constructor
    cout << derived.getId() << endl;
    cout << derived.getCost() << endl;
    return 0;
}
