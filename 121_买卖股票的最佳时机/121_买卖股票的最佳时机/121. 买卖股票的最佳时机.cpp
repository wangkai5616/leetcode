#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//̰���㷨
//˼·������С�Ĺ�Ʊ�۸�
int maxProfit(vector<int>& prices)
{
	if (prices.size() < 2)
		return 0;
	int profit = 0;//����Ҳ���ǲ��
	int cur_min = prices[0];//������С�Ĺ�Ʊ�۸�
	/* 
	��i��������Ʊ���������Ϊ��i���Ʊ��
	�۸�͵�i��֮ǰ��С�Ĺ�Ʊ�۸�����
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