#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<algorithm>
#include<memory>
using namespace std;
bool exist(vector<vector<char>>& board, string word)
{
	if (word.size() == 0)
		return true;
	int row = board.size();
	int col = board[0].size();
	vector<vector<bool>> visited(row, vector<bool>(col, false));
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
			if (dfs(board, word, i + 1, j, row, col, 0, visited))
				return true;
	}
	return false;
}
bool dfs(const vector<vector<char>>& board, const string &word,
	int i,int j,int m, int n, int k, vector<vector<bool>> &visited)
{
	if (k == word.size())
		return true;
	bool b = false;
	if (i >= 0 && i < m && j >= 0 && j < n && board[i][j] == word[k] && !visited[i][j])
	{
		visited[i][j] = true;
		bool b= dfs(board, word, i + 1, j, m, n, k + 1, visited) ||
			dfs(board, word, i - 1, j, m, n, k + 1, visited) ||
			dfs(board, word, i, j + 1, m, n, k + 1, visited) ||
			dfs(board, word, i, j - 1, m, n, k + 1, visited);
		visited[i][j] = false;
	}
	return b;
}
int main(void)
{
	vector<vector<int>> result;
	system("pause");
	return 0;
}




