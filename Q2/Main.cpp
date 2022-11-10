#include "DataFile.h"
#include <iostream> 
using namespace std;

void main() {
	DataFile df;
	char* c = new char[10];
	strcpy_s(c,9,"tamir>");
	df.setData(c);
	df.setFileName(c);
}