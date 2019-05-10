#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
bool isValidSudoku(vector<vector<char>>& board)
{
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[0].size(); ++j)
		{
			if (!isValidSudokuCore(board, i, j))
				return false;
		}
	}
}
bool isValidSudokuCore(vector<vector<char>>& board,int m,int n)
{
	for (int i = 0; i < board.size(); ++i)
		if (board[i][n] == board[m][n] && i != m)
			return false;
	for (int i = 0; i < board[0].size(); ++i)
		if (board[m][i] == board[m][n] && n != i)
			return false;
	for (int i =3* (m / 3); i < 3*(m / 3 + 1); ++i)
	{
		for (int j = n / 3; j < n / 3 + 1; ++j)
		{

		}
	}
}
int main(void)
{
	cout << myPow(2, -1) << endl;
	system("pause");
	return 0;
}

