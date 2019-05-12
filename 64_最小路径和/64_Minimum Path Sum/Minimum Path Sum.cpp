#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
给定一个包含非负整数的 m x n 网格，
请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
说明：每次只能向下或者向右移动一步。

思路：二维动态递归进行求解
*/
int minPathSum(vector<vector<int>>& grid)
{
	if (grid.size() == 0)
		return 0;
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>> result(m, vector<int>(n, 0));
	result[0][0] = grid[0][0];
	for (int i = 1; i < m; ++i)
		result[i][0] = result[i - 1][0] + grid[i][0];
	for (int i = 1; i < n; ++i)
		result[0][i] = result[0][i - 1] + grid[0][i];
	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
			result[i][j] = min(result[i - 1][j], result[i][j - 1]) + grid[i][j];
	}
	return result[m - 1][n - 1];
}
int main(void)
{
	vector<vector<int>> result = { {9,1,4,8} };
	int minValue = minPathSum(result);
	cout << minValue << endl;
	system("pause");
	return 0;
}