#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List
{
public:
	List();
	Node* head;

	void insertNode(int, int);
	void displayAllNodes();
	void deleteAllNodes();
};


#endif
