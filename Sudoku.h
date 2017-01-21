//  Sudoku.h
//  SudokuSolver
//
//  Created by Pattarapol Koosalapeerom
//  Copyright © 2016 Pattarapol Koosalapeerom. All rights reserved.

#ifndef SUDOKU_H
#define SUDOKU_H

#include "List.h"

class Sudoku
{
private:
	enum Test
	{
		Pass, Fail
	};
	Test testSolution(char, int, int);
public:
	Sudoku();
	char board[9][9];
	List list;

	void readfile();
	void firstEliminate();
	void setupCurUniverseAll();
	void displayBoard();
	void solve();
	void solveAlgo();
};


#endif