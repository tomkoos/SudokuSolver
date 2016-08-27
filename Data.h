#ifndef DATA_H
#define DATA_H

#include "header.h"

class Data
{
public:
	vector<char> initUniverse;
	vector<char> curUniverse;
	int loc_i;
	int loc_j;
	char solution;

	void setupCurUniverse();	
};


#endif
