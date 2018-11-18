#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*
����һ����ά�����һ�����ʣ��ҳ��õ����Ƿ�����������С�

���ʱ��밴����ĸ˳��ͨ�����ڵĵ�Ԫ���ڵ���ĸ���ɣ�����
�����ڡ���Ԫ������Щˮƽ���ڻ�ֱ���ڵĵ�Ԫ��ͬһ����
Ԫ���ڵ���ĸ�������ظ�ʹ�á�
*/
/*
˼·�������������������ʱ�临�Ӷ�Ϊ0(n^2*m^2)���ռ�
���Ӷ�ΪO(n^2)
*/
bool dfs(const vector<vector<char>>& board, const string &word,
	int index, int x, int y, vector<vector<bool>> &visited);
bool exist(vector<vector<char>>& board, string word)
{
	if (board.size() == 0 || word.size() == 0)
		return false;
	int m = board.size();
	int n = board[0].size();
	//��ʼʱÿ��Ԫ�ض�δ�����ʹ�
	vector<vector<bool>> visited(m, vector<bool>(n, false));
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if (dfs(board, word, 0, i, j, visited))
				return true;
	return false;
}
/*
x��y�Ǹ�����ά������±�
index�Ǹ������ʵ��±�
*/
bool dfs(const vector<vector<char>>& board, const string &word,
	int index, int x, int y, vector<vector<bool>> &visited)
{
	if (index == word.size())
		return true;
	if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
		return false;//Խ��

	if (visited[x][y])
		return false;//֮ǰ�Ѿ����ʹ���Ԫ��
	if (board[x][y] != word[index])
		return false;//�뵱ǰԪ�ز����

	visited[x][y] = true;//�뵱ǰԪ�����
	bool result = dfs(board, word, index, x - 1, y, visited) ||
		dfs(board, word, index + 1, x + 1, y, visited) ||
		dfs(board, word, index + 1, x, y - 1, visited) ||
		dfs(board, word, index + 1, x, y + 1, visited);
	//��Ϊ�ǽ��е����ã��ڷ�����һ����ʱ���ٱ�Ϊfalse����ֹӰ�������ж�
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