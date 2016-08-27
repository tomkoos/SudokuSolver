#include "Sudoku.h"

Sudoku::Sudoku()
{
	List list;
	readfile();
	firstEliminate();
}

void Sudoku::readfile()
{
	string line;
	ifstream myfile("Sudoku.txt");
	if (myfile.is_open())
	{
		int i = 0;
		while (getline(myfile, line))
		{
			for (unsigned int j = 0; j < 9; j++)
			{
				if (line[j] == '0')
				{
					board[i][j] = ' ';
					list.insertNode(i, j);
				}
				else
					board[i][j] = line[j];
			}
			i++;
		}
		myfile.close();
	}
	else cout << "Unable to open file";
}

void Sudoku::firstEliminate()
{
	Node* cur = list.head;

	while (cur != NULL)
	{
		for (int i = 1; i <= 9; i++)
		{
			char buffer[10];
			sprintf(buffer,"%d",i);
			if (testSolution(buffer[0], cur->data.loc_i, cur->data.loc_j) == Fail)
			{
				for (unsigned int c = 0; c < cur->data.initUniverse.size() ; c++)
				{
					if (buffer[0] == cur->data.initUniverse[c])
					{
						cur->data.initUniverse.erase(cur->data.initUniverse.begin() + c);
						break;
					}
				}
			}
		}
		cur->data.setupCurUniverse();
		cur = cur->next;
	}
}

void Sudoku::displayBoard()
{
	cout << endl;
	for (unsigned int i = 0; i < 9; i++)
	{
		if (i % 3 == 0 && i != 0)
			cout << "------+-------+------" << endl;
		for (unsigned int j = 0; j < 9; j++)
		{
			if (j % 3 == 0 && j != 0)
				cout << "| ";
			cout << board[i][j] << " ";
			if (j == 8)			
				cout << endl;	
		}		
	}
}

void Sudoku::solve()
{
	Node* cur = list.head;

	//Backtracking Method
	while (cur != NULL)
	{				
		while (cur->data.curUniverse.size() != 0)
		{
			if (testSolution(cur->data.curUniverse.front(), cur->data.loc_i, cur->data.loc_j) == Fail)
			{
				cur->data.curUniverse.erase(cur->data.curUniverse.begin());
				continue;
			}
			cur->data.solution = cur->data.curUniverse.front();
			board[cur->data.loc_i][cur->data.loc_j] = cur->data.solution;
			break;
		}
		if (cur->data.curUniverse.size() == 0)
		{
			cur->data.solution = ' ';
			board[cur->data.loc_i][cur->data.loc_j] = ' ';
			cur = cur->prev;
			cur->data.solution = ' ';
			board[cur->data.loc_i][cur->data.loc_j] = ' ';
			cur->data.curUniverse.erase(cur->data.curUniverse.begin());
			continue;
		}
		cur = cur->next;
		if (cur != 0)
			cur->data.setupCurUniverse();
	}	
}

void Sudoku::solveAlgo()
{
	Node* cur = list.head;

	while (cur != NULL)
	{
		displayBoard();
		while (cur->data.curUniverse.size() != 0)
		{
			if (testSolution(cur->data.curUniverse.front(), cur->data.loc_i, cur->data.loc_j) == Fail)
			{
				cur->data.curUniverse.erase(cur->data.curUniverse.begin());
				continue;
			}
			cur->data.solution = cur->data.curUniverse.front();
			board[cur->data.loc_i][cur->data.loc_j] = cur->data.solution;			
			break;
		}
		if (cur->data.curUniverse.size() == 0)
		{
			cur->data.solution = ' ';
			board[cur->data.loc_i][cur->data.loc_j] = ' ';
			cur = cur->prev;
			cur->data.solution = ' ';
			board[cur->data.loc_i][cur->data.loc_j] = ' ';
			cur->data.curUniverse.erase(cur->data.curUniverse.begin());
			continue;
		}
		cur = cur->next;
		if (cur != 0)
			cur->data.setupCurUniverse();
	}
}

Sudoku::Test Sudoku::testSolution(char s, int loc_i, int loc_j)
{
	//Up -> Down
	for (int i = 0; i < 9; i++)
	{
		if (board[i][loc_j] == s && i != loc_i)
			return Fail;
	}

	//Left -> Right
	for (int j = 0; j < 9; j++)
	{
		if (board[loc_i][j] == s && j != loc_j)
			return Fail;
	}

	//Inside small box
	int i1, i2, j1, j2;
	switch (loc_i % 3)
	{
	case 0 :
		i1 = loc_i + 1;
		i2 = loc_i + 2;
		break;
	case 1:
		i1 = loc_i - 1;
		i2 = loc_i + 1;
		break;
	case 2:
		i1 = loc_i - 1;
		i2 = loc_i - 2;
		break;
	}
	switch (loc_j % 3)
	{
	case 0:
		j1 = loc_j + 1;
		j2 = loc_j + 2;
		break;
	case 1:
		j1 = loc_j - 1;
		j2 = loc_j + 1;
		break;
	case 2:
		j1 = loc_j - 1;
		j2 = loc_j - 2;
		break;
	}
	if (board[i1][j1] == s || board[i1][j2] == s || board[i2][j1] == s || board[i2][j2] == s)
		return Fail;
	
	return Pass;
}
