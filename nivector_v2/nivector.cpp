#include <string>
#include <sstream>

#include <vector>

namespace cs427_527
{
  template<typename T>
  NIVector<T>::NIVector()
  {
    count = 0;
  }

  template<typename T>
  void NIVector<T>::push_back(const T& s)
  {
    if (count % CHUNK_SIZE == 0)
      {
	// time for a new chunk
	elements.push_back(std::vector<T>(CHUNK_SIZE));
      }

    // put s in appropriate location in appropriate chunk
    elements[count / CHUNK_SIZE][count % CHUNK_SIZE] = s;

    count++;
  }

  template<typename T>
  int NIVector<T>::size() const
  {
    return count;
  }

  template<typename T>
  T& NIVector<T>::at(int i)
  {
    if (i >= 0 && i < count)
      {
	return elements[i / CHUNK_SIZE][i % CHUNK_SIZE];
      }
    else
      {
	std::ostringstream s;
	s << "index out of range: " << i << std::ends;
	throw s.str();
      }
  }

  template<typename T>
  typename NIVector<T>::iterator NIVector<T>::begin()
  {
    return iterator(*this, 0);
  }

  template<typename T>
  typename NIVector<T>::iterator NIVector<T>::end()
  {
    return iterator(*this, count);
  }

  template<typename T>
  NIVector<T>::iterator::iterator(NIVector& v, int i)
    : vec(v)
  {
    index = i;
  }

  template<typename T>
  bool NIVector<T>::iterator::operator==(const NIVector<T>::iterator& rhs)
  {
    // check that lhs and rhs are at the same position in the same vector
    return index == rhs.index && &vec == &rhs.vec;
  }

  template<typename T>
  bool NIVector<T>::iterator::operator!=(const NIVector<T>::iterator& rhs)
  {
    // check that lhs and rhs are at different positions or in diff vectors
    return index != rhs.index || &vec != &rhs.vec;
  }

  template<typename T>
  T& NIVector<T>::iterator::operator*()
  {
    return vec.at(index);
  }

  template<typename T>
  typename NIVector<T>::iterator& NIVector<T>::iterator::operator++()
  {
    index++;
    return *this;
  }

}
