#include<iostream>
#include<vector>
using namespace std;
/*
����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬
����ÿ��Ԫ�ؾ����������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
*/
/*
˼·�����������������ֵĶ����Ʊ�ʾ��ÿһλ�������������ĳһλ�ĺ��ܱ�3������
��ô�Ǹ�ֻ����һ�ε����ֶ����Ʊ�ʾ�ж�Ӧ����һλ��0���������1��
*/
int singleNumber(vector<int>& nums)
{
	int bitSum[32] = { 0 };
	for (int i = 0; i < nums.size(); ++i)
	{
		int bitMask = 1;
		for (int j = 31; j >= 0; --j)
		{
			int bit = bitMask & nums[i];
			if (bit != 0)
				bitSum[j] += 1;
			bitMask = bitMask << 1;
		}
	}
	int result = 0;
	for (int i = 0; i < 32; ++i)
	{
		result = result << 1;
		result += bitSum[i] % 3;
	}
	return result;
}
int main(void)
{
	system("pause");
	return 0;
}