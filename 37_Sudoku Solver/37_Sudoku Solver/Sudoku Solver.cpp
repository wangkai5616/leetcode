#include<iostream>
#include<vector>
using namespace std;
/*
��дһ������ͨ�������Ŀո�������������⡣
*/
bool solveSudoku(vector<vector<char>>& board)
{

	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
		{
			if (board[i][j] == '.')
			{
				//ĳһλ���Ϊ��,��ô��1-9���ν��г���
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
//���(x,y)�Ƿ�Ϸ�
bool IsValid(const vector<vector<char>>& board, int x, int y)
{
	//���y��
	for (int i = 0; i < 9; ++i)
		if (i != x && board[i][y] == board[x][y])
			return false;
	//���x��
	for (int j = 0; j < 9; ++j)
		if (j != x && board[x][j] == board[x][y])
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