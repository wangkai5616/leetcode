#include<iostream>
#include<vector>
using namespace std;
/*
��дһ������ͨ�������Ŀո�������������⡣
*/
bool IsValid(const vector<vector<char>>& board, int x, int y);
bool solveSudoku1(vector<vector<char>>& board);
void solveSudoku(vector<vector<char>>& board)
{
	solveSudoku1(board);
	cout << "over" << endl;
}
//ʱ�临�Ӷ�̫����O(9^4),�ռ临�Ӷ�O(1)
bool solveSudoku1(vector<vector<char>>& board)
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
					if (IsValid(board, i, j) && solveSudoku1(board))
						return true;
					board[i][j] = '.';
				}			
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