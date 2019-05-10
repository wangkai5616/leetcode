#include<iostream>
#include<vector>
using namespace std;
/*
编写一个程序，通过已填充的空格来解决数独问题。
*/
bool IsValid(const vector<vector<char>>& board, int x, int y);
bool solveSudoku1(vector<vector<char>>& board);
void solveSudoku(vector<vector<char>>& board)
{
	solveSudoku1(board);
	cout << "over" << endl;
}
//时间复杂度太高了O(9^4),空间复杂度O(1)
bool solveSudoku1(vector<vector<char>>& board)
{

	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
		{
			if (board[i][j] == '.')
			{
				//某一位如果为空,那么从1-9依次进行尝试
				for (int k = 0; k < 9; ++k)
				{
					board[i][j] = '1' + k;
					if (IsValid(board, i, j) && solveSudoku1(board))
						return true;
					board[i][j] = '.';
				}			
				return false;
			}
		}
	return true;
}
//检测(x,y)是否合法
bool IsValid(const vector<vector<char>>& board, int x, int y)
{
	//检测y列
	for (int i = 0; i < 9; ++i)
		if (i != x && board[i][y] == board[x][y])
			return false;
	//检测x行
	for (int j = 0; j < 9; ++j)
		if (j != y && board[x][j] == board[x][y])
			return false;
	//检测3X3方形内是否合法
	for (int i = 3 * (x / 3); i < 3 * (x / 3 + 1); ++i)
	{
		for (int j = 3 * (y / 3); j < 3 * (y / 3 + 1); ++j)
			if ((i != x || j != y) && board[i][j] == board[x][y])
				return false;
	}
	return true;
}
void print(const vector<vector<char>> &board)
{
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[0].size(); ++j)
			cout << board[i][j] << " ";
		cout << endl;
	}
	
}
int main(void)
{
	vector<vector<char>> board =
	{ {'5','3','.','.','7','.','.','.','.'},
	{'6','.','.','1','9','5','.','.','.' },
	{'.','9','8','.','.','.','.','6','.'},
	{'8','.','.','.','6','.','.','.','3'},
	{'4','.','.','8','.','3','.','.','1'},
	{'7','.','.','.','2','.','.','.','6'},
	{'.','6','.','.','.','.','2','8','.'},
	{'.','.','.','4','1','9','.','.','5'},
	{'.','.','.','.','8','.','.','7','9'} };
	solveSudoku(board);
	print(board);
	system("pause");
	return 0;
}