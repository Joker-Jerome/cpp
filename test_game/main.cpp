#include <cstdlib>
#include <cstring>
#include "spinout.h"

using std::strcmp;
using std::string;
using cs427_527::SpinOut;

int main(int argc, char *argv[])
{
  if (argc > 1) {
  if (strcmp(argv[1], "-i") == 0)
	{
    if (argc > 2 && strlen(argv[2])>0) {
    SpinOut state(argv[2]); // auto-converts C-string argv[2] to std::string
		int disk;
		std::cout << state.toString() << endl;
    while(cin >> disk) {
			// print the current state
			state.makeMove(disk);
			std::cout << state.toString() << endl;
			//std::cout << state.totalMoves() << " moves" << endl;
			if (state.isSolved()) {
        //cout << "SOLVED" << endl;
			  std::cout << state.totalMoves() << " moves" << endl;
        break;
      }
		}
		return 0;
		// run interactive mode
	  }
    else if (argc == 2)
    {
      SpinOut state; 
      int disk;
			std::cout << state.toString() << endl;
      while(cin >> disk) {
      // print the current state
        if (state.isLegalMove(disk)) {
          state.makeMove(disk);
			    cout << state.toString() << endl;
        } else {
          cout << "illegal move"  << endl;
        }
      if (state.isSolved()) {
        //cout << "SOLVED" << endl;
        break;
      }
    }
    return 0;

    }
  }
	else
	{
		// run non-interactive mode
    if (argc > 2 && strlen(argv[1]) == 7) {
      // answer check mode
      //cout << "answer check" << endl;
      SpinOut state(argv[1]);
      for (int i = 2; i < argc; i++) {
        if (state.isLegalMove(atoi(argv[i]))) {
          state.makeMove(atoi(argv[i]));
        } else {
          cout << "SpinOut: illegal move " << argv[i] << " in position " << i << " for " << state.toString() << endl;
          return 0;
        }
      }
      if (state.isSolved()) {
        cout << "SOLVED" << endl;
        return 0;
      } else {
			  cout << state.toString() << endl;
        return 0;
      
      }
    } else {
      // no state is specified
      SpinOut state;
      for (int i = 1; i < argc; i++) {
        if (state.isLegalMove(atoi(argv[i]))) {
          state.makeMove(atoi(argv[i]));
        } else {
          cout << "SpinOut: illegal move " << argv[i] << " in position " << i << " for " << state.toString() << endl;
          return 0;
        }
      }
      if (state.isSolved()) {
        cout << "SOLVED" << endl;
        return 0;
      } else {
        cout << state.toString() << endl;
        return 0;

      }


    }
    return 0;
  }
  } else {
    return 0;

  }
}
