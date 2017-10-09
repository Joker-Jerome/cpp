#ifndef __CIVECTOR_H__
#define __CIVECTOR_H__

#include <iostream>
#include <string>
#include <sstream>
#include <functional>

#include <utility>

namespace cs427_527
{

  template <typename T>
    class CIVector
    {
    private:
      const int INITIAL_CAPACITY = 2;
      
    public:
      CIVector()
	{
	  capacity = INITIAL_CAPACITY;
	  count = 0;
	  elements = (T*)::operator new(sizeof(T) * capacity);
	}
      
      CIVector(const CIVector& toCopy)
	{
	  copy(toCopy);
	}
      
      CIVector(CIVector&& toMove)
	{
	  move(toMove);
	}
      
      ~CIVector()
	{
	  deallocate();
	}

      CIVector& operator=(const CIVector& rhs)
	{
	  if (this != &rhs)
	    {
	      deallocate();
	      copy(rhs);
	    }
	  return *this;
	}
      
      CIVector& operator=(CIVector&& rhs)
	{
	  if (this != &rhs)
	    {
	      deallocate();
	      move(rhs);
	    }

	  return *this;
	}
      
      T& operator[](int i)
	{
	  return elements[i];
	}
      
      const T& operator[](int i) const
      {
	return elements[i];
      }
      
      int size() const
      {
	return count;
      }
      
      void push_back(const T& item)
      {
	if (count == capacity)
	  {
	    embiggen();
	  }
	
	new (elements + count) T(item);
	count++;
      }
      
      template<typename Comparator>
	void sort(Comparator comp)
	{
	  // bubble sort!
	  for (int i = 0; i < count - 1; i++)
	    {
	      for (int j = 0; j < count - 1 - i; j++)
		{
		  if (comp(elements[j + 1], elements[j]))
		    {
		      std::swap(elements[j], elements[j + 1]);
		    }
		}
	    }
	}
      
      std::string toString() const
	{
	  std::ostringstream out;
	  
	  out << "[";
	  for (int i = 0; i < count; i++)
	    {
	      if (i > 0)
		{
		  out << ", ";
		}
	      out << elements[i];
	    }
	  out << "]";
	  
	  return out.str();
	}

    private:
      void deallocate()
      {
	for (int i = 0; i < count; i++)
	  {
	    elements[i].~T();
	  }
	::operator delete(elements);
      }
      
      void copy(const CIVector& toCopy)
      {
	capacity = toCopy.capacity;
	count = toCopy.count;
	
	elements = (T*)::operator new(capacity * sizeof(T));
	for (int i = 0; i < count; i++)
	  {
	    new (elements + i) T(toCopy.elements[i]);
	  }
      }
      
      void move(CIVector &toMove)
      {
	capacity = toMove.capacity;
	count = toMove.count;
	elements = toMove.elements;
	
	toMove.capacity = 0;
	toMove.count = 0;
	toMove.elements = nullptr;
      }
      
      void embiggen()
      {
	int newCapacity = capacity * 2;
	T *larger = (T*)::operator new(newCapacity * sizeof(T));
	for (int i = 0; i < count; i++)
	  {
	    new (larger + i) T(std::move(elements[i]));
	  }
	deallocate();
	elements = larger;
	capacity = newCapacity;
      }
      
      int capacity;
      int count;

      T* elements;
    };

  template<typename T>
    std::ostream& operator<<(std::ostream& os, const CIVector<T>& v)
    {
      return os << v.toString();
    }
}

#endif
