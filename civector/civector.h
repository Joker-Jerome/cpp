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
      typedef T* iterator;
      typedef const T* const_iterator;

      class iterator_wrapper
      {
      public:
	iterator_wrapper(T* ptr) { current = ptr; }
	T& operator *() const { return *(current - 1); }
	iterator_wrapper& operator++(int) { current = current - 1; return *this; }
	bool operator==(const iterator_wrapper& rhs) const { return current == rhs.current; }
	bool operator!=(const iterator_wrapper& rhs) const { return !(*this == rhs); }
      private:
	T* current;
      };

      class const_iterator_wrapper
      {
      public:
	const_iterator_wrapper(const T* ptr) { current = ptr; }
	const T& operator *() const { return *(current - 1); }
	const_iterator_wrapper& operator++(int) { current = current - 1; return *this; }
	bool operator==(const const_iterator_wrapper& rhs) const { return current == rhs.current; }
	bool operator!=(const const_iterator_wrapper& rhs) const { return !(*this == rhs); }
      private:
	const T* current;
      };

      typedef iterator_wrapper reverse_iterator;
      typedef const_iterator_wrapper const_reverse_iterator;
      
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

      iterator begin()
      {
	return elements;
      }

      const_iterator begin() const
      {
	return elements;
      }

      iterator end()
      {
	return elements + count;
      }

      const_iterator end() const
      {
	return elements + count;
      }

      reverse_iterator rbegin()
      {
	return iterator_wrapper(end());
      }

      reverse_iterator rend()
      {
	return iterator_wrapper(begin());
      }
      
      const_reverse_iterator rbegin() const
      {
	return const_iterator_wrapper(end());
      }

      const_reverse_iterator rend() const
      {
	return const_iterator_wrapper(begin());
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

  template<typename Iterator, typename Function>
  void for_each(const Iterator& begin, const Iterator& end, Function f)
    {
      for (Iterator i = begin; i != end; i++)
	{
	  f(*i);
	}
    }

  template<typename Iterator, typename Predicate>
  Iterator find_if(const Iterator& begin, const Iterator& end, Predicate f)
    {
      Iterator i = begin;
      while (i != end && !f(*i))
	{
	  i++;
	}
      return i;
    }
}

#endif
