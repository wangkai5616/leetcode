#include<iostream>
#include<vector>
using namespace std;
//给定一个整数数组 nums ，找到一个具有最大和的连
//续子数组（子数组最少包含一个元素），返回其最大和。
int maxSubArray(vector<int>& nums)
{
	if (nums.size() < 1)
		return -1;
	int max = INT_MIN;
	int current = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (current < 0)
			current = nums[i];
		else
			current += nums[i];
		if (current > max)
			max = current;
	}
	return max;
}
int main(void)
{
	vector<int> v = { -3,4,-4,6,3,-1,8 };
	int result = maxSubArray(v);
	cout << result << endl;
	system("pause");
	return 0;
}