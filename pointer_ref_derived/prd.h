#ifndef __PRD_H__
#define __PRD_H__

#include <string>
#include <iostream>


class Base
{
protected:
    int m_value;
 
public:
    Base(int value)
        : m_value(value)
    {
    }
 
    const char* getName() { return "Base"; }

    int getValue() { return m_value; }
};
 
class Derived: public Base
{
public:
    Derived(int value)
        : Base(value)
    {
    }
 
    const char* getName() { return "Derived"; }
    int getValueDoubled() { return m_value * 2; }
};

#endif
