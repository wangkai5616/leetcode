#include<iostream>
#include<vector>
using namespace std;
bool increasingTriplet(vector<int>& nums)
{
	int n = nums.size();
	if (n < 3)
		return false;
	vector<int> record(n, 1);
	for (int j = 1; j < n; ++j)
	{
		for (int i = 0; i < j; ++i)
			if (nums[j]>nums[i] && record[i] + 1>record[j])
				record[j] = record[i] + 1;
		if (record[j]>2)
			return true;
	}
	return false;
}