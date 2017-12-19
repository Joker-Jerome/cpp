#ifndef __NIVECTOR_H__
#define __NIVECTOR_H__

#include <string>
#include <vector>

namespace cs427_527
{

  /**
   * A vector that does not invalidate references on push_back.
   *
   * @param T a type that is default-constructable and assignable
   */
  
  template<typename T>
    class NIVector
    {
    public:
      /**
       * An iterator through an NIVector.
       * (We can't use plain pointers because the elements in an NIVector
       * are not all contiguous in memory since they are stored in many
       * different std::vectors inside the NIVector.)
       */
      class iterator
      {
      public:
	iterator(NIVector&, int);

	bool operator==(const iterator& rhs);
	bool operator!=(const iterator& rhs);
	T& operator*();
	iterator& operator++();

      private:
	/**
	 * The vector this iterator iterates through.
	 */
	NIVector &vec;

	/**
	 * This iterator's index into that vector.
	 */
	int index;
      };
  
      NIVector();

      /**
       * Adds the given item to the end of this vector.
       *
       * @param s an item
       */
      void push_back(const T& s);

      /**
       * Returns a reference to the item at the given location in this vector.
       * Throws a std::string if the index is not valid.
       *
       * @param i an index into this vector
       * @return a reference to the item at that index
       */
      T& at(int i);

      /**
       * Returns the number of items in this vector.
       *
       * @return the number of items in this vector
       */
      int size() const;

      /**
       * Returns an iterator positioned at the beginning of this vector.
       *
       * @return an iterator positioned at the beginning of this vector
       */
      iterator begin();

      /**
       * Returns an iterator positioned at the end of this vector.
       *
       * @return an iterator positioned at the end of this vector
       */
      iterator end();
  
    private:
      /**
       * A vector of chunks.  Items are added to the last chunk.
       * When the last chunk grows to the size given below then
       * a new chunk is created.
       */
      std::vector< std::vector<T> > elements;

      /**
       * The number of items in this vector.
       */
      int count;

      /**
       * The maximum size of each chunk.
       */
      static const int CHUNK_SIZE = 10;
    };
}
 
#include "nivector.cpp"
 
#endif

