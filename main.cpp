//============================================================================
// Name        : test.cpp

// Author      : Brayan Almonte
// Version     : 1.0
// Copyright   : You are free to use this code for whatever you need.
// Description : Reads from a log file and outputs data from desired column on a separate file.
//				 Note that the format of the file needs to be specified in the source file.
//============================================================================
// -------------------------includes------------------------------------------







//My Includes
#include "TextParser.h"

using namespace std;

Parser Parse;

//-----------------------functions-------------------------------------------




int main() {

	setbuf(stdout, NULL);
	string filename;
	string fieldname;

	cout << "Enter Filename and Field name: ";
	cin >> filename >> fieldname ;

	Parse.readColumn(filename, fieldname);

	return 0;
}

