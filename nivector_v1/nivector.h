#ifndef __NIVECTOR_H__
#define __NIVECTOR_H__

#include <string>
#include <vector>

class NIVector
{
 public:
  NIVector();

  /**
   * Adds the given item to the end of this vector.
   *
   * @param s an item
   */
  void push_back(const std::string& s);

  /**
   * Returns a reference to the item at the given location in this vector.
   * Throws a std::string if the index is not valid.
   *
   * @param i an index into this vector
   * @return a reference to the item at that index
   */
  std::string& at(int i);

  /**
   * Returns the number of items in this vector.
   *
   * @return the number of items in this vector
   */
  int size() const;
  
 private:
  /**
   * A vector of chunks.  Items are added to the last chunk.
   * When the last chunk grows to the size given below then
   * a new chunk is created.
   */
  std::vector< std::vector<std::string> > elements;

  /**
   * The number of items in this vector.
   */
  int count;

  /**
   * The maximum size of each chunk.
   */
  static const int CHUNK_SIZE = 10;
};

#endif
