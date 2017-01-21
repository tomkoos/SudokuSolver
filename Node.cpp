//  Node.cpp
//  SudokuSolver
//
//  Created by Pattarapol Koosalapeerom
//  Copyright © 2016 Pattarapol Koosalapeerom. All rights reserved.

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
		sprintf_s(buffer,"%d",i);
		data.initUniverse.push_back(buffer[0]);
	}
	data.solution = ' ';
}
