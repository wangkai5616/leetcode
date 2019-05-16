#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
说明：解集不能包含重复的子集
*/
void dfs(const vector<int> &nums, int k, vector<int> &v, vector<vector<int>> &result);
vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	vector<vector<int>> result;
	vector<int> v;
	dfs(nums, 0, v, result);
	return result;
}
void dfs(const vector<int> &nums, int k, vector<int> &v, vector<vector<int>> &result)
{
	result.push_back(v);
	for (int i = k; i < nums.size(); ++i)
	{
		if (i != k && nums[i] == nums[i - 1])
			continue;
		v.push_back(nums[i]);
		dfs(nums, i + 1, v, result);
		v.pop_back();
	}
}
void print(vector<vector<int>> &result)
{
	for (int i = 0; i < result.size(); ++i)
	{
		for (int j = 0; j < result[i].size(); ++j)
			cout << result[i][j] << " ";
		cout << endl;
	}
}
int main(void)
{
	vector<int> nums = { 1,2,2 };
	vector<vector<int>> result = subsetsWithDup(nums);
	print(result);
	system("pause");
	return 0;
}