#include <iostream>
#include <fstream>
#include "conway.h"

using cs427_527::Conway;
using namespace std;
using std::strcmp;
using std::string;

int main(int argc, char *argv[])
{
	// interactive mode
  if (argc > 1) {
  if (strcmp(argv[1], "-i") == 0)
  {
    if (argc > 2 && (strcmp(argv[2],"-f") == 0) && strlen(argv[3]) > 0) {

    	// interactive mode with file input
    	ifstream bfile;
    	bfile.open(argv[3]);
    	if (!bfile) {
    		return 1;
    	}

    	// create the object
    	Conway state(bfile);
    cout << state;

    // get the input from players
    int fromR,fromC,toR,toC;
    while(cin >> fromR >> fromC >> toR >> toC) {
    		if (state.isLegalMove(fromR,fromC,toR,toC)) {
    			state.makeMove(fromR,fromC,toR,toC);
    			cout << state;
    			if (state.isSolved()) {
    				cout << state.totalMoves() << " moves" << endl;
    				break;
    			}
    		} else {
    			cout << "illegal move" << endl;
    			//break;
		}
	}
    return 0;
    } else if(!argv[2]) {
    		Conway state;
    		cout << state;

		// get the input from players
		int fromR,fromC,toR,toC;
		while(cin >> fromR >> fromC >> toR >> toC) {
			//cout << fromR << fromC << toR << toC << endl;
				if (state.isLegalMove(fromR,fromC,toR,toC)) {
					state.makeMove(fromR,fromC,toR,toC);
					cout << state;
					if (state.isSolved()) {
						//cout << state;
						cout << state.totalMoves() << " moves" << endl;
						break;
					}
				} else {
					cout << "illegal move" << endl;
					//break;
				}
		}
		return 0;
    }

 } else if (strcmp(argv[1], "-f") == 0 && strlen(argv[2]) > 0) {
	// file input mode
	 ifstream bfile;
	 bfile.open(argv[2]);
 	 if (!bfile) {
 		 return 1;
 	 }
	 // create the object
	 Conway state(bfile);
	 //cout << state;

	 // get the input from command lines
	 int fromR,fromC,toR,toC;
	 int i = 3;
	 int count = 0;
	 while((i+3) <= argc) {
		 count++;
		 fromR = atoi(argv[i]);
		 fromC = atoi(argv[i+1]);
		 toR = atoi(argv[i+2]);
		 toC = atoi(argv[i+3]);

		if (state.isLegalMove(fromR,fromC,toR,toC)) {
			state.makeMove(fromR,fromC,toR,toC);
			if (state.isSolved()) {
				cout << "SOLVED" << endl;
				break;
			}
		} else {
			cout << "Conway: illegal move " << fromR << " " << fromC << " " << toR << " " << toC << " in position " << count << " for" << endl;
			//cout << state;
			break;
		}
		i += 4;

	 }
	 if (!state.isSolved()) {
		 cout << state;
	 }
	 return 0;

 } else if ((atoi(argv[1])>=0 && atoi(argv[1])<6)) {

	 // check the answer without other argument
	 Conway state;
	 	//cout << state;

	 // get the input from command lines
	 int fromR,fromC,toR,toC;
	 int i = 1;
	 int count = 0;
	 while((i+3) <= argc) {
		 count++;
		 fromR = atoi(argv[i]);
		 fromC = atoi(argv[i+1]);
		 toR = atoi(argv[i+2]);
		 toC = atoi(argv[i+3]);
		if (state.isLegalMove(fromR,fromC,toR,toC)) {
			state.makeMove(fromR,fromC,toR,toC);
			if (state.isSolved()) {
				cout << "SOLVED" << endl;
				break;
			}
		} else {
			cout << "Conway: illegal move " << fromR << " " << fromC << " " << toR << " " << toC << " in position " << count << " for" << endl;
			//cout << state;
			break;
		}	
		i += 4;

	 }
	 if (!state.isSolved()) {
		 cout << state;
	 }

 	 }


  }

}
