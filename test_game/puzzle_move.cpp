#include "puzzle_move.h"

namespace cs427_527
{


	PuzzleMove::PuzzleMove(){
		moveVec.push_back(1);

	}

	//PuzzleMove::PuzzleMove(istringstream& movesIn){

	//}

	PuzzleMove::PuzzleMove(vector<int>& input){
		for(int i = 0; i < input.size();i++) {
			moveVec.push_back(input[i]);
		}

	}

	PuzzleMove::~PuzzleMove(){

	}

	vector<int>& PuzzleMove::getMoves(){
		return(this->moveVec);

	}

	friend ostream& operator <<(ostream& output,PuzzleMove CurMove) {

				for(int i = 0; i<CurMove.moveVec.size();i++) {
					output << CurMove.moveVec[i];
				}
				return(output);

			}






}

