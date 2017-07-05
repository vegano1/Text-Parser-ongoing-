/*
 * TextParser.cpp
 *
 *  Created on: Jun 20, 2017
 *      Author: Brayan
 */

#include "TextParser.h"

using namespace std;

void log(string a) {
	cout << a;

}

bool File::fileExists(const std::string& filename) {
	struct stat buf;
	if (stat(filename.c_str(), &buf) != -1) {
		return true;
	}
	return false;
}

void Parser::config(std::fstream& inputDoc, std::string fieldName) {
	string word;
	if (inputDoc.is_open()) {
		string word;

		int fieldNum = 0;
		while (getline(inputDoc, word)) {

			if (word.find("#Fields:") == 0) {
				int fieldPos = word.find(fieldName);

				for (int i = 0; i <= fieldPos; i++) {

					if (word[i] == ' ') {
						fieldNum++;
					}
				}

				setFieldNum(fieldNum);

				break;
			}
		}
	} else {
		cout << "inputDoc is not opened. ";
	}

}

string Parser::readColumn(std::string filename, std::string fieldName) {

	File d;

	if (d.fileExists(filename)) {

		fstream inputDoc;

		char* fileName = (char*) filename.c_str();
		printf("Opening File. \n");
		inputDoc.open(fileName);

		config(inputDoc, fieldName);
		int FieldNum = getFieldNum();
		if(FieldNum == 0)
		{
			cout << "Field Not Found." << endl;
			return "0";
		}

		string Line;
		while (getline(inputDoc, Line)) {

			if (FieldNum == 1) {
				int test2 = Line.find(" ");
				cout << Line.substr(0, test2) << endl;
			}

			else {

				int currentField = 1;

				for (int i = 0; i < Line.length(); i++) {

					if (Line[i] == ' ') {

						currentField++;

						if (currentField == FieldNum) {

							string test1 = Line.substr(i + 1);
							int test2 = test1.find(" ");
							cout << Line.substr(i + 1, test2) << endl;

							i = Line.length();

						}
					}
				}
			}
		}

		inputDoc.close();
	}

	else {
		cout << "File \"" << filename << "\" does not exist";
		return "0";
	}
}

