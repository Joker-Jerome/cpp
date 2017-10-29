/*
 * cooccur.h
 *
 *  Created on: Oct 25, 2017
 *      Author: jerome
 */

#ifndef __COOCCUR_H__
#define __COOCCUR_H__

#include <iostream>
#include <string.h>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <iomanip>

/**
 * A cooccurrence matrix.
 */
// 527: uncomment this and change std::string to T in all parameters and
// return types
// template<typename T>
class CooccurrenceMatrix
{
public:
  /**
   * Creates a cooccurrence matrix that counts cooccurrences of the given keywords
   * and is initialized to 0 for all entries.
   *
   * @param keywords a vector of unique strings
   */
  CooccurrenceMatrix(std::vector<std::string> keywords);
  ~CooccurrenceMatrix();

  /**
   * Reads keywords from the given matrix from the current line of the given stream.
   * A keyword is considered to have been read if it appears on the stream before
   * the next newline surrounded by whitespace, the beginning of input (as seen by
   * this function), or EOF.  The newline is read and removed from the stream.
   *
   * @param is an input stream
   * @return an set of strings containing all the keywords read
   */
  std::unordered_set<std::string> readContext(std::istringstream& is) const;

  /**
   * Updates the given cooccurrence matrix by incrementing the counts for
   * each pair of keywords in the given context.
   *
   * @param context an set of strings that are keywords for this matrix
   */
  void update(const std::unordered_set<std::string>& context);

  /**
   * Returns the vector (row) for the given word in the given matrix.
   * Values in the returned array correspond to the keywords for the
   * given matrix in the order they were given in the array passed to
   * the constructor that created the given matrix.  Each
   * value is the proportion of times that the given keyword appeared in
   * a call to update for the given matrix that also contained
   * each other keyword.  If the given word is not a keyword for the
   * given matrix or the keyword has never appeared in a call to
   * update for the given matrix, then the returned array
   * contains 0.0 in every entry.
   *
   * @param keyword a string
   * @return an vector of doubles
   */
  std::vector<double> getVector(const std::string& keyword) const;
  void PrintMatrix();

private:
  int num;
  std::vector<std::vector<double>> comatrix;
  std::vector<std::string> wordvec;
  std::unordered_map<std::string,int> wordmap;
  std::vector<int> wordcount;
};

// 527: uncomment this line so your template implementation is
// included whenever someone includes this header
// #include "cooccur.cpp"

#endif
