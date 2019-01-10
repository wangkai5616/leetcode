#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxProfit(vector<int>& prices)
{
	if (prices.size() < 2)
		return 0;
	const int n = prices.size();
	vector<int> v1(n, 0);
	vector<int> v2(n, 0);
	int min_value = prices[0];
	int max_value = prices[n - 1];
	//从前往后记录第i天的最大利润
	for (int i = 1; i < n; ++i)
	{
		min_value = min(min_value, prices[i]);
		v1[i] = max(v1[i - 1], prices[i] - min_value);
	}
	for (int i = n - 2; i >= 0; --i)
	{
		max_value = max(max_value, prices[i]);
		v2[i] = max(v2[i], max_value - prices[i]);
	}
	int max_profit = 0;
	for (int i = 0; i < n; ++i)
		max_profit = (max_profit, v1[i] + v2[i]);
	return max_profit;
}
int main(void)
{
	system("pause");
	return 0;
}