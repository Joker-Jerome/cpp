
#ifndef SRC_PUZZLE_MOVE_H_
#define SRC_PUZZLE_MOVE_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace cs427_527
{
	class PuzzleMove
	{
	public:
		PuzzleMove();

		//PuzzleMove(istringstream& movesIn);

		PuzzleMove(vector<int>& input);

		~PuzzleMove();

		friend ostream& operator << (ostream& output,PuzzleMove CurMove);

		vector<int>& getMoves();

	private:
		//int type;
		vector<int> moveVec;
		friend class Puzzle;
		friend class Conway;
		friend class SpinOut;


	};

}



#endif /* SRC_PUZZLE_MOVE_H_ */
