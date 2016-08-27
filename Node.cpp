#include "Node.h"

Node::Node()
{
	prev = NULL;
	next = NULL;
}

void Node::inputNode(int i, int j)
{
	data.loc_i = i;
	data.loc_j = j;	
	for (int i = 1; i <= 9; i++)
	{
		char buffer[10];
		sprintf(buffer,"%d",i);
		data.initUniverse.push_back(buffer[0]);
	}
	data.solution = ' ';
}
