/*
 * TextParser.cpp
 *
 *  Created on: Jun 20, 2017
 *      Author: Brayan
 */

#include "TextParser.h"

using namespace std;

bool File::fileExists(const std::string& filename) {
	struct stat buf;
	if (stat(filename.c_str(), &buf) != -1) {
		return true;
	}
	return false;
}

int Parser::wordPos(std::string Line, std::string Word) {

	std::size_t found = Line.find(Word);
	if (found != std::string::npos) {

	}
	return found;
}

int config(fstream& document, std::string fieldName) {

	Parser Parse;
	string a;
int FieldNum = 1;
	while (document >> a) {
		if (Parse.word != "#Fields:") {

			Parse.word = "";
		} else {
			getline(document, a);
			int FieldPos = Parse.wordPos(Parse.Line, fieldName);

			for (int p = 0; p < FieldPos; p++) {

				if (Parse.Line[p] == ' ') {
					FieldNum++;

				}
			}
			if(FieldNum>1)
			{
				return 1;
			}
			else{
				return 0;
			}
		}
	}
}

string Parser::readColumn(std::string filename, std::string fieldName) {

	int currentField = 1;

	Parser Parse;
	File d;

	char* fileName = (char*) filename.c_str();

	if (d.fileExists(filename)) {

		printf("Opening File. \n");

		document.open(fileName);
		Parse.config(document,fieldName);
				while (getline(document, Parse.Line)) {

					for (int i = 0; i < Parse.Line.length(); i++) {

						if (FieldNum == 1) {
							string test1 = Parse.Line.substr(i);

							int test2 = test1.find(" ");
							cout << Parse.Line.substr(i, test2) << endl;
							i = Parse.Line.length();
						}

						if (Parse.Line[i] == ' ') {

							if (currentField == FieldNum - 1) {

								string test1 = Parse.Line.substr(i + 1);

								int test2 = test1.find(" ");
								cout << Parse.Line.substr(i + 1, test2) << endl;

								i = Parse.Line.length();
								currentField = 0;
							}
							currentField++;
						}
					}

				}





		document.close();
	}

	else {
		cout << "File \"" << filename << "\" does not exist";
		return "0";
	}
}

