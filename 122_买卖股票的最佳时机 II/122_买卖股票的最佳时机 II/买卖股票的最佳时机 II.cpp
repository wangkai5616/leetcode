#include<iostream>
#include<vector>
using namespace std;
/*
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
*/
/*
贪心算法：
策略：只要后一天的股票价格比前一天高，就在前一天买入，后一天卖出；反之什么也不做。
*/
int maxProfit(vector<int>& prices)
{
	int sum = 0;
	for (int i = 1; i < prices.size(); ++i)
	{
		if (prices[i] > prices[i - 1])
			sum += prices[i] - prices[i - 1];
	}
	return sum;
}
int main(void)
{
	system("pause");
	return 0;
}