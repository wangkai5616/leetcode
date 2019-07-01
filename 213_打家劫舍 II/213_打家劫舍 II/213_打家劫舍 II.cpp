#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int robCore(vector<int>& nums,int left,int right)
{
	if (nums.size() == 0)
		return 0;
	int sum1 = 0;
	int sum2 = 0;
	for (int i = left; i < right; ++i)
	{
		if (i % 2 == 1)
			sum1 = max(sum1 + nums[i], sum2);
		else
			sum2 = max(sum2 + nums[i], sum1);
	}
	return sum1 > sum2 ? sum1 : sum2;
}
int rob(vector<int>& nums)
{
	if (nums.size() <= 1)
		return nums.size() == 0 ? 0: nums[0];
	return max(robCore(nums, 0, nums.size() - 1), robCore(nums, 1, nums.size()));
}