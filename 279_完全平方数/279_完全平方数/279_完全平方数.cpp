#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int numSquares(int n)
{
	// dp[i] 表示正整数i最少能由多个完全平方数组成
	vector<int> dp(n + 1, INT_MAX);
	dp[0] = 0;
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 1; i + j*j <= n; ++j)
			dp[i + j*j] = min(dp[i + j*j], dp[i] + 1);
	}
}