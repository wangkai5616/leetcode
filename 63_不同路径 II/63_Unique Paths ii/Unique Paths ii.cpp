#include<iostream>
#include<vector>
using namespace std;
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1) return 0;
	vector<vector<long> > dp(obstacleGrid.size(), vector<long>(obstacleGrid[0].size(), 0));
	for (int i = 0; i < obstacleGrid.size(); ++i) {
		for (int j = 0; j < obstacleGrid[i].size(); ++j) {
			if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
			//第一个元素为1
			else if (i == 0 && j == 0) dp[i][j] = 1;
			//第一行元素的值为每个元素前一个元素的值，如果某个值为0，代表这一行走不通了
			else if (i == 0 && j > 0) dp[i][j] = dp[i][j - 1];
			//第一列元素的值为每个元素前一个元素的值，如果某个值为0，代表这一列走不通了
			else if (i > 0 && j == 0) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp.back().back();
}

int main(void)
{
	vector<vector<int>> v = { {0,0,0},{0,1,0},{0,0,0} };
	int result = uniquePathsWithObstacles(v);
	cout << result << endl;
	system("pause");
	return 0;
}