
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>


using namespace std;

#ifndef PARSER_H
#define PARSER_H

class File
{


public :

	bool fileExists(const std::string& filename);
	bool getFile(const std::string& filename);


};

class Parser
{


public :
	string Line;
	string word;
	int FieldNum = 0;
	fstream document;

	string readColumn(std::string filename, std::string fieldName);
	int wordPos(std::string Line, std::string Word);
	int config(fstream& stream, std::string fieldName);

};




#endif
