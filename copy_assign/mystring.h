#include <cstring> // for strlen()
#include <cassert> // for assert()
 
class MyString
{
private:
    char *m_data;
    int m_length;
 
public:
    MyString(const char *source="")
    {
        assert(source); // make sure source isn't a null string
 
        // Find the length of the string
        // Plus one character for a terminator
        m_length = strlen(source) + 1;
        
	std::cout << "Hey! First Constructor!" << std::endl;
        // Allocate a buffer equal to this length
        m_data = new char[m_length];
        
        // Copy the parameter string into our internal buffer
        for (int i=0; i < m_length; ++i)
            m_data[i] = source[i];
    
        // Make sure the string is terminated
        m_data[m_length-1] = '\0';
    }

	MyString(const MyString& source)
	{	
		m_length = source.m_length;
		std::cout << "Hey!" << std::endl;
		if (source.m_data)
		{
			m_data = new char[m_length];
			for (int i =0; i < m_length; ++i)
				m_data[i] = source.m_data[i];
		}
		else
			m_data = 0;
	}
 
    ~MyString() // destructor
    {
     
	// We need to deallocate our string
	delete[] m_data;
	}        

	MyString& operator=(const MyString & source)

{
    // check for self-assignment
    if (this == &source)
        return *this;
 
    // first we need to deallocate any value that this string is holding!
    //delete[] m_data;
 
    // because m_length is not a pointer, we can shallow copy it
    m_length = source.m_length;
 
    // m_data is a pointer, so we need to deep copy it if it is non-null
    if (source.m_data)
    {
        // allocate memory for our copy
        m_data = new char[m_length];
 
        // do the copy
        for (int i=0; i < m_length; ++i)
            m_data[i] = source.m_data[i];
    }
    else
        m_data = 0;
 
    return *this;
    }

	
	
    

     	
    char* getString() { return m_data; }
    int getLength() { return m_length; }
};
