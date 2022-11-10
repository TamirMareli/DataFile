#define _CRT_SECURE_NO_WARNINGS
#include "DataFile.h"
#include <string>
#include <iostream> 
using namespace std;
const int SIZE = 100;



void DataFile::setData(char* newData)
{
    delete[] this->Data;
	int count = strlen(newData);
	this->Data = new char[count+1];
	strcpy_s(this->Data,count+1, newData);
}

void DataFile::setFileName(char* newFileName)
{
	int chack;
	do
	{
		chack = 0;
		for (int i = 0; i < strlen(newFileName); i++) {
			if (newFileName[i] == '<' || newFileName[i] == '?' || newFileName[i] == '*' || newFileName[i] == ':' || newFileName[i] == '/' || newFileName[i] == '\\' || newFileName[i] == '|' || newFileName[i] == '>') {
				chack = 1;
				break;
			}
		}
		if (chack) {
			delete[] newFileName;
			newFileName = new char[SIZE + 1];
			cout << "Enter new file name" << endl;
			cin.getline(newFileName, SIZE);
		}
	} while (chack);

}

char* DataFile::getlastUpdateTime() const
{
	char buf[80];
	strftime(buf, sizeof(buf), "%d/%m/%Y %X", lastUpdateTime);
	char* stringTime = new char[strlen(buf) + 1];
	strcpy(stringTime, buf); return stringTime;
	
}

void DataFile::setlastUpdateTime()
{
	// current date/time based on current system
	time_t now = time(0);
	lastUpdateTime = localtime(&now);
}

DataFile::DataFile()
{
	this->Data = new char[6];
	strcpy(this->Data, "new data");
	this->FileName = new char[6];
	strcpy(this->FileName, "new file");
	this->lastUpdateTime = new tm;
	this->setlastUpdateTime();
}

