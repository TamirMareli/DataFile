#pragma once
#include <ctime>
class DataFile
{
	char* FileName;
	tm* lastUpdateTime;
	char* Data;
public:
	char* getData()const { return Data; }
	void setData(char* newData);
	char* getFileName()const { return FileName; }
	void setFileName(char* newFileName);
	char* getlastUpdateTime()const;
	void setlastUpdateTime();
	DataFile();
};

