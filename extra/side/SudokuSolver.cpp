#include <iostream>
#include <vector>
using namespace std;
bool isSafe(int r, int c, vector<vector<int>> board, int val)
{
	int n = 9;
	for (int i = 0; i < n; i++)
	{
		if (board[r][i] == val || board[i][c] == val || board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == val)
			return false;
	}
	return true;
}
bool solve(vector<vector<int>> &board)
{
	int n = 9;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 0)
			{
				for (int val = 1; val <= 9; val++)
				{
					if (isSafe(i, j, board, val))
					{
						board[i][j] = val;
						if (solve(board))
						{
							return true;
						}
						else
						{
							board[i][j] = 0;
						}
					}
				}
				return false;
			}
		}
	}
	return true;
}
int main()
{
	vector<vector<int>> sudoku;
	for (int i = 0; i < 9; i++)
	{
		vector<int> temp;
		for (int j = 0; j < 9; j++)
		{
			// cout<<"Enter value at "<<i<<","<<j<<": ";
			int x;
			cin >> x;
			temp.push_back(x);
		}
		sudoku.push_back(temp);
	}
	// print board
	for (int i = 0; i < 9; i++)
	{
		if (i % 3 == 0)
			cout << "-------------------------" << endl;
		for (int j = 0; j < 9; j++)
		{
			if (j % 3 == 0)
				cout << "| ";
			if (sudoku[i][j] == 0)
				cout << "  ";
			else
				cout << sudoku[i][j] << " ";
		}
		cout << "|" << endl;
	}
	cout << "-------------------------" << endl;
	if (solve(sudoku))
	{
		cout << "Solution is: " << endl;
		for (int i = 0; i < 9; i++)
		{
			if (i % 3 == 0)
				cout << "-------------------------" << endl;
			for (int j = 0; j < 9; j++)
			{
				if (j % 3 == 0)
					cout << "| ";
				cout << sudoku[i][j] << " ";
			}
			cout << "|" << endl;
		}
		cout << "-------------------------" << endl;
	}
	else
	{
		cout << "No solution exists" << endl;
	}
}
// EASY WALA
// 4 6 3 0 0 9 8 7 0 8 1 2 3 4 7 9 6 0 9 0 5 2 6 0 1 3 4 6 9 0 0 0 0 2 8 3 5 3 7 0 8 2 4 0 9 2 4 0 9 3 0 0 5 7 0 8 4 7 2 3 5 9 0 3 0 9 4 1 0 7 2 0 7 0 0 8 0 5 3 4 0

// MEDIUM WALA
// 2 8 4 1 0 0 7 0 3 0 0 3 7 0 2 0 0 0 0 9 0 0 3 8 0 4 0 3 0 2 9 8 0 0 1 0 8 1 6 3 0 0 4 0 9 9 4 5 2 0 6 8 0 7 0 5 0 0 0 1 0 9 8 0 0 9 8 7 5 2 0 4 4 2 8 0 0 0 0 0 0

// EXTREME WALA
// 0 0 7 0 8 0 0 0 0 4 0 0 0 0 0 0 2 0 0 0 6 0 0 9 0 1 0 0 0 0 0 0 6 0 0 9 5 7 0 0 0 0 0 0 8 0 9 0 0 5 3 0 0 0 0 0 0 5 0 0 2 0 0 2 0 0 9 0 0 0 7 0 0 0 9 2 0 7 6 8 0