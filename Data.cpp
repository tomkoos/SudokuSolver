#include "Data.h"

void Data::setupCurUniverse()
{
	curUniverse.clear();
	for (unsigned int i = 0; i < initUniverse.size(); i++)
		curUniverse.push_back(initUniverse[i]);
}
