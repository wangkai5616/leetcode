#include<iostream>
#include<vector>
using namespace std;
int majorityElement(vector<int>& nums)
{
	int count = 1;
	int cur = nums[0];
	int n = nums.size();
	for (int i = 1; i < n; ++i)
	{
		if (nums[i] == cur)
			++count;
		else
		{
			if (--count == 0)
			{
				cur = nums[i];
				count = 1;
			}
		}
	}
	return cur;
}