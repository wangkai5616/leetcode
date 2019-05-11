#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
给定一个没有重复数字的序列，返回其所有可能的全排列。
*/
/*
此题较特殊，因为涉及从前向后，还要从后向前，所以不能根据下标
是否到达num.size()做判断
*/
vector<vector<int>> permute(vector<int>& nums)
{
	vector<vector<int>> result;
	if (nums.empty())
		return result;
	sort(nums.begin(), nums.end());
	vector<int> v;
	dfs(nums,v,result);
	return result;
}
void dfs(const vector<int>& nums, vector<int> &v, vector<vector<int>> &result)
{
	//收敛条件
	if (v.size() == nums.size())
	{
		result.push_back(v);
		return;
	}
	for (auto i : nums)
	{
		//查找i是否在v中出现过
		auto pos = find(v.begin(), v.end(), i);
		if (pos == v.end())
		{
			v.push_back(i);
			dfs(nums, v, result);
			v.pop_back();
		}
	}
}
int main(void)
{
	system("pause");
	return 0;
}