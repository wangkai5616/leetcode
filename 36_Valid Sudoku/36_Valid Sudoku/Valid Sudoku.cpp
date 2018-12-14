#include<iostream>
#include<vector>
using namespace std;
bool isValidSudoku(vector<vector<char>>& board)
{
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
		{
			if (board[i][j] != '.')
			{
				if (!IsValid(board, i, j))
					return false;
			}
		}
	return true;
}
//���(x,y)�Ƿ�Ϸ�
bool IsValid(const vector<vector<char>>& board, int x, int y)
{
	//���y��
	for (int i = 0; i < 9; ++i)
		if (i != x && board[i][y] == board[x][y])
			return false;
	//���x��
	for (int j = 0; j < 9; ++j)
		if (j != y && board[x][j] == board[x][y])
			return false;
	//���3X3�������Ƿ�Ϸ�
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