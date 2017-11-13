#include <iostream>

#include "conway.h"
using namespace std;

namespace cs427_527
{
	Conway::Conway()
	{
		rowNum = 5;
		colNum = 6;
		totalCounts = 0;
		ary = new char*[rowNum];
		for(int i = 0; i < rowNum; i++)
		      ary[i] = new char[colNum];

		  // fill
		for(int i = 0; i < rowNum; i++)
			for(int j = 0; j < colNum; j++)
				ary[i][j] = '.';
		ary[2][1] = 'X';
		ary[2][2] = 'X';
		ary[2][3] = 'X';
		ary[3][3] = 'X';

	}

	/**
	 * Creates an empty conway object.
	 */
	Conway::Conway(istream& s)
	{
			string input;
			int count = 0;
			totalCounts = 0;

			// get the board information rownum and colnum
			getline(s,input);
			istringstream sin(input);
			sin >> rowNum;
			sin >> colNum;

			// initialize the 2D array
			//char** ary = new char*[rowNum];
			ary = new char*[rowNum];
			for(int i = 0; i < rowNum; i++)
				ary[i] = new char[colNum];

			// read the soldiers information
			while(getline(s,input) && input.length() >0) {
			//	cout << input << endl;
				for (int i = 0; i < colNum; i++) {
					if ((input[i] == '.') || (input[i] == 'X')) {
						ary[count][i] = input[i];
			//			cout << input[i];
					}
				}
				count++;
			}

	}

	Conway::Conway(const Conway &rhs) {

		    // copy primitive values from list to copy from
		    rowNum = rhs.rowNum;
			colNum = rhs.colNum;
			totalCounts = rhs.totalCounts;

			ary = new char*[rowNum];
			for(int i = 0; i < rowNum; i++)
					ary[i] = new char[colNum];

			for (int i = 0; i < rhs.rowNum; i++) {
				for (int j = 0; j < rhs.colNum; j++) {
					ary[i][j] = rhs.ary[i][j];
				}

			}



	}

	Conway::Conway(Conway &&rhs) {

		// copy primitive values from list to copy from
		rowNum = rhs.rowNum;
		colNum = rhs.colNum;
		totalCounts = rhs.totalCounts;
		ary = rhs.ary;

		rhs.rowNum = 0;
		rhs.colNum = 0;
		rhs.totalCounts = 0;
		rhs.ary = NULL;


	}



	/**
	 *  Destroys a conway object.
	 */
	Conway::~Conway(){
		delete[] ary;

	}
	PuzzleMove* Conway::readMove(istringstream& input){
		int dim = 4;
		int tmpVal = 0;

		vector<int> tmpVec;
		for(int i = 0; i < dim; i++) {
			input >> tmpVal;
			tmpVec.push_back(tmpVal);
		}

		PuzzleMove *tmpMove = new PuzzleMove(tmpVec);
		return(tmpMove);
	}

	PuzzleMove* Conway::readMove(istream& input){
			int dim = 4;
			int tmpVal = 0;

			vector<int> tmpVec;
			for(int i = 0; i < dim; i++) {
				input >> tmpVal;
				tmpVec.push_back(tmpVal);
			}

			PuzzleMove *tmpMove = new PuzzleMove(tmpVec);
			return(tmpMove);
		}
	/**
	 *  Takes four integers 
	 *  and determine whether the move is legal.
	 */
	bool Conway::isLegalMove(PuzzleMove *curMove) const
	{
			if (curMove->moveVec.size() == 4) {
			int fromR, fromC, toR, toC;

			fromR = curMove->moveVec[0];
			fromC = curMove->moveVec[1];
			toR = curMove->moveVec[2];
			toC = curMove->moveVec[3];

			// evaluate the input
			if (fromR >= this->rowNum || toR >= this->rowNum || fromC >= this->colNum || toC >= this->colNum) {
				return(0);
			} else if (fromR < 0 || toR < 0 || fromC < 0 || toC < 0) {
				return(0);
			} else if (this->ary[fromR][fromC] != 'X' || this->ary[toR][toC] == 'X' ) {
				return(0);
			} else if ((abs(fromR-toR) == 2 && (fromC == toC)) || (abs(fromC-toC) == 2 && (fromR == toR))) {
				if (this->ary[(fromR+toR)/2][(fromC+toC)/2] == 'X') {
					return(1);
				} else {
					return(0);
				}
			} else {
				return(0);
			}
			}
			else return(0);

		}

	/**
	 * 	Makes move if the
	 * 	move is legal.
	 */
	void Conway::makeMove(PuzzleMove *curMove) {
		//bool legal = this->isLegalMove(fromR, fromC, toR, toC);
		//if (legal == 0) {
		//	cout << "illegal move" << endl;
		//} else {
		if (curMove->moveVec.size() == 4) {

		int fromR, fromC, toR, toC;

		fromR = curMove->moveVec[0];
		fromC = curMove->moveVec[1];
		toR = curMove->moveVec[2];
		toC = curMove->moveVec[3];
		this->ary[fromR][fromC] = '.';
		this->ary[toR][toC] = 'X';
		this->ary[(fromR+toR)/2][(fromC+toC)/2] = '.';
		this->totalCounts++;
		//cout << "make some changes" << endl;
		//	}
		}


	}

	/**
	 * 	Counts the total moves.
	 */
	int Conway::totalMoves() const {
		return(this->totalCounts);
	}

	/**
	 * 	Determines if the current object
	 * 	is in its solved configuration.
	 */
	bool Conway::isSolved() const{
		int flag = 0;
		for (int t = 0; t < this->colNum; t++) {
				if (this->ary[0][t] == 'X') flag = 1;
		}
		if (flag == 0) {
			return 0;
		} else {
			return 1;
		}

	}

	Conway& Conway::operator=(const Conway &rhs) {
	    // check for self-assignment
	    if (&rhs != this) {
		// free old array
	    	delete(ary);

		// copy primitive values from list to assign from
		rowNum = rhs.rowNum;
		colNum = rhs.colNum;
		totalCounts = rhs.totalCounts;

		ary = new char*[rowNum];
		for(int i = 0; i < rowNum; i++)
				ary[i] = new char[colNum];

		for (int i = 0; i < rhs.rowNum; i++) {
			for (int j = 0; j < rhs.colNum; j++) {
				ary[i][j] = rhs.ary[i][j];
			}

		}
	    }

	    return *this;
	  }

	Conway& Conway::operator=(Conway &&rhs) {
		    // check for self-assignment
		    if (&rhs != this) {
			// free old array
		    	delete(ary);

			// copy primitive values from list to assign from
			rowNum = rhs.rowNum;
			colNum = rhs.colNum;
			ary = rhs.ary;
			totalCounts = rhs.totalCounts;

			rhs.rowNum = 0;
			rhs.colNum = 0;
			rhs.totalCounts = 0;
			rhs.ary = NULL;
		    }

		    return *this;
		  }
	/**
	 * 	<< operator
	 */
	ostream& operator<<(ostream& output, const Conway& obj) {
		for (int i = 0; i < obj.rowNum; i++) {
				for (int j = 0; j < obj.colNum; j++) {
					output << obj.ary[i][j];
				}
				output << endl;
			}
	         return output;
	      }

	void Conway::print(ostream& output) const
	{

		for (int i = 0; i < this->rowNum; i++) {
					for (int j = 0; j < this->colNum; j++) {
						output << this->ary[i][j];
					}
					output << endl;
				}

		      }




}
