#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中
“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单
元格内的字母不允许被重复使用。
*/
/*
思路：利用深度优先搜索，时间复杂度为0(n^2*m^2)，空间
复杂度为O(n^2)
*/
bool dfs(const vector<vector<char>>& board, const string &word,
	int index, int x, int y, vector<vector<bool>> &visited);
bool exist(vector<vector<char>>& board, string word)
{
	if (board.size() == 0 || word.size() == 0)
		return false;
	int m = board.size();
	int n = board[0].size();
	//初始时每个元素都未被访问过
	vector<vector<bool>> visited(m, vector<bool>(n, false));
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if (dfs(board, word, 0, i, j, visited))
				return true;
	return false;
}
/*
x、y是给定二维数组的下标
index是给定单词的下标
*/
bool dfs(const vector<vector<char>>& board, const string &word,
	int index, int x, int y, vector<vector<bool>> &visited)
{
	if (index == word.size())
		return true;
	if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
		return false;//越界

	if (visited[x][y])
		return false;//之前已经访问过该元素
	if (board[x][y] != word[index])
		return false;//与当前元素不相等

	visited[x][y] = true;//与当前元素相等
	bool result = dfs(board, word, index, x - 1, y, visited) ||
		dfs(board, word, index + 1, x + 1, y, visited) ||
		dfs(board, word, index + 1, x, y - 1, visited) ||
		dfs(board, word, index + 1, x, y + 1, visited);
	//因为是进行的引用，在返回上一级的时候，再变为false，防止影响后面的判断
	visited[x][y] = false;
	return result;
}
int main(void)
{
	vector<vector<char>> board = { {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','F'} };
	string word = "FBD";
	bool result = exist(board, word);
	if (result)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	system("pause");
	return 0;
}