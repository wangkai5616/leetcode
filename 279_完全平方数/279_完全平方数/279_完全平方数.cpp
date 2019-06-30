#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int numSquares(int n)
{
	// dp[i] ��ʾ������i�������ɶ����ȫƽ�������
	vector<int> dp(n + 1, INT_MAX);
	dp[0] = 0;
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 1; i + j*j <= n; ++j)
			dp[i + j*j] = min(dp[i + j*j], dp[i] + 1);
	}
}