#include<iostream>
#include<vector>
using namespace std;
/*
˼·�Ǽ�Ȼ0��n֮������һ���������ǽ��������һ�����������0��n֮���������������һ�£�
��ô��ͬ�����ֶ���Ϊ0�ˣ�ʣ�µľ������˵��Ǹ�������
*/
int missingNumber(vector<int>& nums)
{
	int result = 0;
	for (int i = 0; i < nums.size(); ++i)
		result ^= (i + 1) ^ nums[i];
	return result;
}
/*
�õȲ����е���͹�ʽ���0��n֮�����е�����֮�ͣ�Ȼ���ٱ�����������������ֵ��ۻ��ͣ�Ȼ��
����������ֵ���Ƕ�ʧ���Ǹ�����
*/
int missingNumber(vector<int>& nums) 
{
	int sum = 0, n = nums.size();
	for (auto &a : nums) {
		sum += a;
	}
	return 0.5 * n * (n + 1) - sum;
}