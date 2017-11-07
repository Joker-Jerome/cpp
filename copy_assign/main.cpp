#include <iostream>
#include "mystring.h"

int main()
{
	MyString hello("Hello, world!");
    	{
        MyString copy = hello; // use default copy constructor  	
 
    	std::cout << copy.getString() << '\n'; // this will have undefined behavior
	} // copy is a local variable, so it gets destroyed here.  The destructor deletes copy's string, which leaves hello with a dangling pointer
 
    	std::cout << hello.getString() << '\n'; // this will have undefined behavior
 
   	return 0;


}

