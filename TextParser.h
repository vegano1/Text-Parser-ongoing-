
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>


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

	int FieldNum;
public :



	std::string Line;
	std::string word;

	std::string readColumn(std::string filename, std::string fieldName);

	void config(std::fstream& document, std::string fieldName);

	void setFieldNum( int num){ FieldNum = num;}
	int getFieldNum(){ return FieldNum; }
};




#endif
