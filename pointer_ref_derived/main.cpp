#include <iostream>
#include "prd.h"

int main()
{
    Derived derived(5);
    std::cout << "derived is a " << derived.getName() << " and has value " << derived.getValue() << '\n';
 
    Derived &rDerived = derived;
    std::cout << "rDerived is a " << rDerived.getName() << " and has value " << rDerived.getValue() << '\n';
 
    Derived *pDerived = &derived;
    std::cout << "pDerived is a " << pDerived->getName() << " and has value " << pDerived->getValue() << '\n';
 
    return 0;
}
