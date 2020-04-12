/*
 * FileReader.cpp
 *
 *  Created on: Apr 10, 2020
 *      Author: William Reames
 */
#include <iostream>
#include <fstream>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;

//trys to open filename, and return its contents in contents
//it will strip out only \n's (char return\line feed)
//returns:
//SUCCESS all worked, contents string contains all in the file
//COULD_NOT_OPEN_FILE_TO_READ contents string is cleared
int KP_FileIO::getFileContents(const std::string &filename, std::string &contents){
	//Makes sure contents is empty
	if(contents.size()==0){
		fstream inputFile;
		inputFile.open(filename, ios::in);
		//Makes sure the file opened properly
		if(inputFile.is_open()){
			//Append data to contents
			string line;
			while(!inputFile.eof()){
				getline(inputFile, line);
				contents += line;
			}
			inputFile.close();
			return SUCCESS;
		}
	}
	return COULD_NOT_OPEN_FILE_TO_READ;
}

//trys to open filename, and serialize  myEntryVector contents to it
//returns:
//SUCCESS all worked, filename contains myEntryVector strings
//COULD_NOT_OPEN_FILE_TO_WRITE
int KP_FileIO::writeVectortoFile(const std::string filename,std::vector<std::string> &myEntryVector)
{
	fstream outputFile;
	outputFile.open(filename, ios::out);
	//Makes sure the file opened properly
	if(outputFile.is_open()){
		//iterates over the entry vector
		for(vector<string>::iterator iter = myEntryVector.begin(); iter != myEntryVector.end(); ++iter){
			//outputs the data
			outputFile << *iter << "\n";
		}
		outputFile.close();
		return SUCCESS;
	}
	return COULD_NOT_OPEN_FILE_TO_WRITE;
}


