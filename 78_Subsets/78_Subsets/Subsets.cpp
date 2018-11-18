#include<iostream>
#include<vector>
using namespace std;
/*
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
说明：解集不能包含重复的子集。

思路：增量构造法，对于每个元素，都有两种选择，选或者不选
*/
void subsetsCore(vector<vector<int>> &result, vector<int> &v, vector<int>& nums, int i);
vector<vector<int>> subsets(vector<int>& nums)
{
	vector<vector<int>> result;
	if (nums.size() < 1)
		return result;
	vector<int> v;
	int i = 0;
	subsetsCore(result, v, nums, i);
	return result;
}
void subsetsCore(vector<vector<int>> &result,vector<int> &v, vector<int>& nums,int i)
{
	if (i == nums.size())
	{
		result.push_back(v);
		return;
	}
	subsetsCore(result, v, nums, i + 1);
	v.push_back(nums[i]);
	subsetsCore(result, v, nums, i + 1);
	v.pop_back();
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
	vector<int> nums = { 1,2,3 };
	vector<vector<int>> result = subsets(nums);
	print(result);
	system("pause");
	return 0;
}