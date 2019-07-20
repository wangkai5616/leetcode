#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool containsDuplicate(vector<int>& nums)
{
	if (nums.size() == 0)
		return false;
	unordered_map<int, int> m;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (m.find(nums[i]) != m.end())
			return true;
		++m[nums[i]];
	}
	return false;
}