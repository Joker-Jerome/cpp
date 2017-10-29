/*
 * main.cpp
 *
 *  Created on: Oct 25, 2017
 *      Author: jerome
 */

#include "cooccur.h"
#include <fstream>


using namespace std;

int main(int argc, char *argv[])
{
	if (argc > 1) {
		stringstream ss;
		string tmp_str;
		int num_w = argc-1;
		vector<string> iv(argc-1);
		for (int i = 1; i < argc; i++) {
			 iv[i-1] = argv[i];
		}
		//istream input_stream;
		//ss >> input_stream;
		CooccurrenceMatrix cocooccur_matrix(iv);
	    while(getline(cin, tmp_str)) {
	    		unordered_set<string> tmp_key;
	    		istringstream iss(tmp_str);
	    		//istream is(iss);
	    		//istream is;
	    		//iss >> is;
	    		tmp_key = cocooccur_matrix.readContext(iss);
	    		cocooccur_matrix.update(tmp_key);

	    }
	    //cocooccur_matrix.PrintMatrix();
	    for(int i = 0; i < num_w; i++) {
	    		string keyword = argv[i+1];
	    		std::vector<double> ocvec = cocooccur_matrix.getVector(keyword);
	    		cout.setf(ios::showpoint);
	    		cout.precision(6);
	    		cout.setf(ios::fixed);
	    		cout << keyword << ": [" ;
	    		for(int j = 0; j < (num_w -1); j++) {
	    			cout << ocvec[j] << ", ";
	    		}
	    		cout << ocvec[num_w - 1] << "]" << endl;
	    }

	}
}
