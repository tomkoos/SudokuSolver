#include "Sudoku.h"

int main()
{
	Sudoku sudoku;

	cout << "Initial Sudoku:";
	sudoku.displayBoard();
	cout << endl;

	char choice;
	while (true)
	{
		cout << "Menu\n-----\n";
		cout << "1) Solve\n";
		cout << "2) Display Board\n";
		cout << "3) Display All Nodes\n";
		cout << "4) Exit\n";
		cout << "Choose : ";
		cin >> choice;
		if (choice == '4')
			break;
		switch (choice)
		{
		case '1':
			while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
			{
				cout << "Display algorithm? (Y/N) : ";
				cin >> choice;
				long t0 = clock();
				switch (choice)
				{
				case 'y': case 'Y':
					sudoku.solveAlgo();
					break;
				case 'n': case 'N':
					sudoku.solve();
					break;
				default:
					break;
				}
				long t1 = clock();
				sudoku.displayBoard();
				cout << "Time processed " << (t1-t0)/1000. << " seconds" << endl << endl;
			}
			break;
		case '2' :
			sudoku.displayBoard();
			break;
		case '3':
			sudoku.list.displayAllNodes();
			break;
		default:
			break;
		}
	}
	sudoku.list.deleteAllNodes();
}
