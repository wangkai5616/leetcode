#include<iostream>
#include<vector>
using namespace std;
/*
编写一个程序，通过已填充的空格来解决数独问题。
*/
bool solveSudoku(vector<vector<char>>& board)
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
					if (IsValid(board, i, j) && solveSudoku(board))
						return true;
					board[i][j] = '.';
				}			
				return false;
			}
		}
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
		if (j != x && board[x][j] == board[x][y])
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
int main(void)
{
	system("pause");
	return 0;
}