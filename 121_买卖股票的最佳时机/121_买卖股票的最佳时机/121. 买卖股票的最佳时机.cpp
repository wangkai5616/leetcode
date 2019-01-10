#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//贪心算法
//思路：找最小的股票价格
int maxProfit(vector<int>& prices)
{
	if (prices.size() < 2)
		return 0;
	int profit = 0;//利润，也就是差价
	int cur_min = prices[0];//保存最小的股票价格
	/* 
	第i天卖出股票的最大利润为第i天股票的
	价格和第i天之前最小的股票价格买入
	*/
	for (int i = 1; i < prices.size(); ++i)
	{
		profit = max(profit, prices[i] - cur_min);
		cur_min = min(cur_min, prices[i]);
	}
	return profit;
}

int main(void)
{
	system("pause");
	return 0;
}