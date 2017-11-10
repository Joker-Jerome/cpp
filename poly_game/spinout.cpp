//============================================================================
// Name        : spinout.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

#include "spinout.h"
using namespace std;

namespace cs427_527
{
	SpinOut::SpinOut()
	{
		for (int i = 0; i < 7; i++)
		{
			oriSeq[i] = '/';
			currSeq[i] = '/';
		}
		//oriSeq = {'/','/','/','/','/','/','/','\0'};
		//currSeq = {'/','/','/','/','/','/','/','\0'};
		totalCounts = 0;
	}

	/**
	 * Creates an empty to-do list.
	 */
	SpinOut::SpinOut(const std::string& s)
	{
		std::string tmp_s = s;
		if (s.length() == 7)
		{
			for (int i = 0; i < 7; i++)
			{
				    if (s[i] != '/' && s[i] != '-')
				    {
				        tmp_s = "///////";
				        cout << "Input Invalid!"<< endl;
						break;
				    }
			}
		}
		else
		{
			tmp_s = "///////";
			cout << "Input Invalid!"<< endl;
		}
		for (int i = 0; i < 7; i++)
		{
			oriSeq[i] = tmp_s[i];
			currSeq[i] = tmp_s[i];
		}
		oriSeq[7] = '\0';
		currSeq[7] = '\0';
		totalCounts = 0;
	}

	/**
	 *  Destroys a to-do list.
	 */
	SpinOut::~SpinOut(){
		//cout << "Exit" << endl;
	}

	/**
	 *  Takes an integer between 0 and 6
	 *  and determine whether is legal.
	 */
	bool SpinOut::isLegalMove(int i) const
	{
		string tmpSeq(this->currSeq);
		int flag = 0;
		if ( i != 6) {
			if (tmpSeq[i+1] == '/') {
				for (int t = i + 2; t < 7; t++) {
					if (tmpSeq[t] != '-') flag = 1;
				}
			} else {
				flag = 1;
			}
		}
		//if (flag == 0) {
		//	for (int t = 0; t < i; t++) {
		//		if (tmpSeq[t] != "/")
		//	}
		if (flag == 0) {
			return 1;
		} else {
			return 0;
		}

	}

	/**
	 * 	Rotates the indicated disk if the
	 * 	move is legal.
	 */
	void SpinOut::makeMove(int i) {
		bool legal = this->isLegalMove(i);
		if (legal == 1) {
			if (this->currSeq[i] == '/') {
				this->currSeq[i] = '-';
			} else {
				this->currSeq[i] = '/';
			}
			this->totalCounts += 1;
		} else {
     // cout << "illegal move" << endl;
    }


	}

	/**
	 * 	Counts the total moves.
	 */
	int SpinOut::totalMoves() const {
		return this->totalCounts;
	}

	/**
	 * 	Determines if the current object
	 * 	is in its solved configuration.
	 */
	bool SpinOut::isSolved() const{
		int flag = 0;
		for (int t = 0; t < 7; t++) {
				if (this->currSeq[t] != '-') flag = 1;
		}
		if (flag == 0) {
			return 1;
		} else {
			return 0;
		}

	}

	/**
	 * 	Returns a string representation of
	 * 	the current object.
	 */
	string SpinOut::toString() const{
		string str(this->currSeq);
		return str.substr(0,7);
	}


}
