#include<iostream>
#include<vector>
using namespace std;
/*
����һ�����飬���ĵ� i ��Ԫ����һ֧������Ʊ�� i ��ļ۸�
���һ���㷨�����������ܻ�ȡ�������������Ծ����ܵ���ɸ���Ľ��ף��������һ֧��Ʊ����
ע�⣺�㲻��ͬʱ�����ʽ��ף���������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ����
*/
/*
̰���㷨��
���ԣ�ֻҪ��һ��Ĺ�Ʊ�۸��ǰһ��ߣ�����ǰһ�����룬��һ����������֮ʲôҲ������
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