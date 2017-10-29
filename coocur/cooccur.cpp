/*
 * cooccur.cpp
 *
 *  Created on: Oct 25, 2017
 *      Author: jerome
 */

#include "cooccur.h"


  CooccurrenceMatrix::CooccurrenceMatrix(std::vector<std::string> keywords)
  :comatrix(keywords.size(),std::vector<double>(keywords.size())),
   wordcount(keywords.size())

  {
	  num = keywords.size();
	  wordvec = keywords;
	  //comatrix(num,std::vector<double>(num));
	  //for (int i = 0; i < num; i++) {
	  //	  comatrix[i].resize(num);
	  //}
	  for(int i = 0; i < num; i++) {
		  wordmap[keywords[i]] = i;
	  }


  }

  CooccurrenceMatrix::~CooccurrenceMatrix(){

  }


  /**
   * Reads keywords from the given matrix from the current line of the given stream.
   * A keyword is considered to have been read if it appears on the stream before
   * the next newline surrounded by whitespace, the beginning of input (as seen by
   * this function), or EOF.  The newline is read and removed from the stream.
   *
   * @param is an input stream
   * @return an set of strings containing all the keywords read
   */
  std::unordered_set<std::string> CooccurrenceMatrix::readContext(std::istringstream& is) const{
	  std::unordered_set<std::string> keyword_set;
	  std::string tmp_word;

		while(is >> tmp_word) {
			  for(int i = 0; i < this->num; i++) {
			  if(this->wordvec[i]==tmp_word && keyword_set.count(tmp_word) == 0) {
				  keyword_set.insert(tmp_word);
			  }
		  }
	  }
	  return keyword_set;

  }

  /**
   * Updates the given cooccurrence matrix by incrementing the counts for
   * each pair of keywords in the given context.
   *
   * @param context an set of strings that are keywords for this matrix
   */
  void CooccurrenceMatrix::update(const std::unordered_set<std::string>& context){
	  int len = context.size();
	  if (len > 0) {
		  std::vector<int> tmp_context(len);
		  std::unordered_set<std::string>::iterator iter;
		  int i = 0;
		  for(iter=context.begin(); iter!=context.end();++iter) {
		  	    tmp_context[i] = this->wordmap[*iter];
		  	    i++;
		  	}
		  for(int i = 0; i < len; i++) {
			  this->wordcount[tmp_context[i]]++;
			  for(int j = 0; j < len; j++) {
				  this->comatrix[tmp_context[i]][tmp_context[j]] += 1;
			  }
		  }
	  }


  }

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
  std::vector<double> CooccurrenceMatrix::getVector(const std::string& keyword) const{
	  std::string word = keyword;
	  int total_counts = this->wordcount[wordmap.at(word)];
	  int index = this->wordmap.at(word);
	  std::vector<double> cooccur_vec = this->comatrix[index];
	  if (total_counts == 0) {
		  std::vector<double> cooccur_vec_f(cooccur_vec.size(),0);
		  return(cooccur_vec_f);
	  } else {
		  std::vector<double> cooccur_vec_f(cooccur_vec.size(),0);
		  for(int i = 0; i < cooccur_vec.size(); i++) {
			  cooccur_vec_f[i] = cooccur_vec[i]/total_counts;
		  }
		  return(cooccur_vec_f);
	  }

  }
  void CooccurrenceMatrix::PrintMatrix (){
	  int num_w = this->num;

	  for(int i = 0; i < num_w; i++) {
		  std::cout << this->wordcount[i] << std::endl;
	  	    		for(int j = 0; j < num_w; j++) {
	  	    			std::cout << this->comatrix[i][j] << std::endl;

	  	    		}
	  	    }
  }
