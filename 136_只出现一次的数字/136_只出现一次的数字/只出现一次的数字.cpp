#include<iostream>
#include<vector>
using namespace std;
/*
����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬
����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
*/
//˼·��������ͬ���������Ϊ0
int singleNumber(vector<int>& nums)
{
	int result = 0;
	for (int i = 0; i < nums.size(); ++i)
		result ^= nums[i];
	return result;
}
int main(void)
{
	system("pause");
	return 0;
}