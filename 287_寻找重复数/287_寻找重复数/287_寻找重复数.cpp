#include<iostream>
#include<vector>
using namespace std;
/*
考虑用二分搜索法了，我们在区间 [1, n] 中搜索，首先求出中点 mid，然后
遍历整个数组，统计所有小于等于 mid 的数的个数，如果个数小于等于 mid，
则说明重复值在 [mid+1, n] 之间，反之，重复值应在 [1, mid-1] 之间，然后
依次类推，直到搜索完成，此时的 right 就是我们要求的重复值
*/
int findDuplicate(vector<int>& nums)
{
	int left = 0, right = nums.size();
	int mid = 0;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		int cnt = 0;
		for (int num : nums)
			if (num <= mid)
				++cnt;
		if (cnt <= mid)
			left = mid + 1;
		else
			right = mid;
	}
	return right;
}