#ifndef NODE_H
#define NODE_H

#include "Data.h"

class Node
{
public:
	Node();
	Data data;
	Node* prev;
	Node* next;

	void inputNode(int, int);
};

#endif
