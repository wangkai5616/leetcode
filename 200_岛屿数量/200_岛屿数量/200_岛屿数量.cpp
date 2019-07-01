#include<iostream>
#include<vector>
using namespace std;
void dfs(const vector<vector<char>>& grid, vector<vector<bool>> &visited
	, int x, int y,int m,int n)
{
	if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0' || visited[x][y])
		return;
	visited[x][y] = true;
	dfs(grid, visited, x - 1, y, m, n);
	dfs(grid, visited, x + 1, y, m, n);
	dfs(grid, visited, x, y - 1 , m, n);
	dfs(grid, visited, x , y + 1, m, n);
	return;
}
int numIslands(vector<vector<char>>& grid)
{
	if (grid.size() == 0 || grid[0].size() == 0)
		return 0;
	int m = grid.size();
	int n = grid[0].size();
	int result = 0;
	vector<vector<bool>> visited(m, vector<bool>(n, false));
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (grid[i][j] == '0' || visited[i][j])
				continue;
			dfs(grid, visited, i, j, m, n);
			++result;
		}
	}
	return result;
}
int main()
{
	vector<vector<char>> v{ {'1'},{'1'} };
	cout<< numIslands(v)<<endl;
	system("pause");
	return 0;
}